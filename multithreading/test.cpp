#include <iostream>
#include <mutex>
#include <future>
#include <atomic>
#include <string>
#include <fstream>

std::pair<uint64_t, uint64_t> get_thread_id1(std::thread::id id){
    uint64_t* ptr = (uint64_t*) &id;
    uint64_t ptr1 = *reinterpret_cast<uint64_t*>(&id);
    return std::make_pair((*ptr), ptr1);
}

uint64_t get_thread_id(std::thread::id id){
    uint64_t ptr1 = *reinterpret_cast<uint64_t*>(&id);
    return ptr1;
}

int do_something(unsigned int& i){
    return i ++; 
}

template<typename data>
void write_in_file(std::ofstream& file_obj, data _data){
    if(!(file_obj.is_open())){
        std::cout << "file not opened" << '\n';
    }else{
        file_obj << _data;
        file_obj << " ";
    }
}

struct func{
    private:
        unsigned int i;
        std::ofstream& m_obj;
    public:
        func(unsigned int _i, std::ofstream& _m_obj) : i{_i}, m_obj{_m_obj} {}

        void operator()(){
            write_in_file(m_obj, "\n second thread id: ");
            write_in_file(m_obj, get_thread_id(std::this_thread::get_id()));
            write_in_file(m_obj, "\n");
            for(unsigned int j = 0; j < 100000; ++j){
                write_in_file(m_obj, std::to_string(do_something(i)));
            }
        }

        std::ofstream get_stream(){
            return std::move(m_obj);
        }
};

class thread_guard{
    std::thread& t;
    public:
        explicit thread_guard(std::thread& t_) : t(t_) {}
        ~thread_guard(){
            if(t.joinable()){
                t.join();
            }
        }
        thread_guard(thread_guard const&) = delete;
        thread_guard& operator=(thread_guard const&) = delete;
};

int main(){
    std::ofstream fout;
    fout.open("test.txt");
    unsigned int some_local_state = 0;
    func my_func(some_local_state, fout);
    std::thread my_thread(my_func);
    thread_guard tg(my_thread);
    my_thread.join();
    fout = my_func.get_stream();
    write_in_file(fout, "\n main thread id: ");
    write_in_file(fout, get_thread_id(std::this_thread::get_id()));
    fout.close();
    std::boolalpha(std::cout);
    std::cout << fout.is_open() << '\n';
    std::cout << my_thread.joinable() << '\n';
    return 0;
}
