#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>

#ifdef _WIN32           // windows
    #define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

std::vector<char> vBuffer(1 * 1024);
using namespace boost;

void GrabSomeData(asio::ip::tcp::socket &socket){
    socket.async_read_some(asio::buffer(vBuffer.data(),vBuffer.size()),
        [&](std::error_code ec, std::size_t lenght){
            if(!ec){
                for(int i = 0; i < lenght; i++){
                    GrabSomeData(socket);
                }
            }
        }
    );
}

int main(){
    std::ofstream fout;
    fout.open("test_asio.txt");

    boost::system::error_code ec;
    asio::io_context context;
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("51.38.81.49",ec),80);
    asio::io_context::work idleWork(context);
    std::thread thrContext = std::thread([&](){context.run();});

    if(!ec){
        std::cout << "Connected" << '\n';
    }else{
        std::cout << "Failed to connect to adress" << ec.message() << '\n';
    }
    asio::ip::tcp::socket socket(context);
    socket.connect(endpoint,ec);
    if(socket.is_open()){
    
    GrabSomeData(socket);
        std::string sRequest =
            "GET /index.html HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Connection: close\r\n\r\n";

        socket.write_some(asio::buffer(sRequest.data(),sRequest.size()),ec);
        
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(20000ms);

        context.stop();
        if(thrContext.joinable()) thrContext.join();
    }else{
        std::cout << "socket is off" << '\n';
    }
    
    if(!fout.is_open()){
        std::cout << "Error to open file" << '\n';
    }else{
        for(const auto c : vBuffer){
            fout << c;
        }
    }
    fout.close();
    return EXIT_SUCCESS;
}