#include "t_class.hpp"
#include <iostream>

int TClass::print_mb(const char *ptr){
    std::mbtowc(NULL, 0, 0); // reset the conversion state
    const char* end = ptr + std::strlen(ptr);
    int ret;
    for (wchar_t wc; (ret = std::mbtowc(&wc, ptr, end-ptr)) > 0; ptr+=ret) {
        std::wcout << wc;
    }
    std::wcout << '\n';
    return ret;
}

int TClassWithStrictTypePos::print_mb(const char *ptr){
    std::mbtowc(NULL, 0, 0); // reset the conversion state
    const char* end = ptr + std::strlen(ptr);
    int ret;
    for (wchar_t wc; (ret = std::mbtowc(&wc, ptr, end-ptr)) > 0; ptr+=ret) {
        std::wcout << wc;
    }
    std::wcout << '\n';
    return ret;
}