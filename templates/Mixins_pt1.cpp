#include <iostream>

/* Mixins */

struct access{
    template<typename Impl>
    static void on_handle_response(Impl impl){ impl.handle_response(); }
    template<typename Impl>
    static void on_handle_connect(Impl impl){ impl.handle_connect(); }
};

template<typename Base>
struct connection_handler{
    void on_connection(){
        access::on_handle_connect(static_cast<Base*>(this));
    }
};

template<typename Base>
struct response_handler{
    void on_response(){
        access::on_handle_response(static_cast<Base*>(this));
    }
};

/* Helper Class */
template<typename work>
struct combined_class : public connection_handler<work>, 
                        public response_handler<work>
{
private:
    friend struct access;
    void handle_connect() { std::cout << "Connecting" << '\n'; }
    void handle_response() { std::cout << "Responsing" << '\n'; }
};

int main()
{
    access ac;
    combined_class<access> ch;
    ac.on_handle_connect(ch);
    ac.on_handle_response(ch);
    return 0;
}
