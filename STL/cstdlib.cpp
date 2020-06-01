/*CSTDLIB HEADER ANALYSIS
header contains many useful defines
#DEFINE EXIT_SUCCESS - define indicates of a successful execution program
#DEFINE EXIT_FAILTURE - oppositely EXIT_SUCCES

defines for convert pointers to any pointer
IN C
#DEFINE NULL 0

IN C++
#DEFINE NULL nullptr

#DEFINE RAND_MAX - maximum value returned of function std::rand

*/

#include <iostream>
#include <cstdlib>
#include <clocale>
#include <ctime>
#include "../t_class.hpp" /* Class for tests*/

/*
    Not various for std::bsearch because compare-pred = int(const void*, const void*);
    return -1 if key not searched and array not ended
    return 1 if key searched 
    and return 0 if key not found in array'
    stilled from cppreference
*/
int comparePredForBSearch(const void *ap, const void *bp){
    int a = *static_cast<const int*> (ap);
    int b = *static_cast<const int*> (bp);
    if(a < b){
        return -1;
    }else if(a > b){
        return 1;
    }else{
        return 0;
    }
}

int main (){

    TClass tobj("134.234");
    tobj.rchar = tobj.rstring.c_str();

    /*return double number from const char *
    if const char contain not number return NULL
    */
    tobj.rdouble = atof(tobj.rchar);
    //std::cout<< tobj.rdouble;

    /*return int number from const char *
    if const char contain not number return NULL
    */
    tobj.rint = atoi(tobj.rchar);
    // std::cout<< tobj.rint;

    /*return long number from const char *
    if const char contain not number return NULL
    */
    tobj.rlong = atol(tobj.rchar);
    //std::cout<< tobj.rlong;

    
    /*Search number in sorted array */
    int arr[8] = {5,3,31,6,28,12,-7,0};
    constexpr int sizearr = sizeof(arr)/sizeof(arr[0]);
    // int key = 3;//search number
    // int *p1 = (int *) std::bsearch(&key, arr , sizearr , sizeof(arr[0]) , comparePredForBSearch);
    //std::cout<< *p1 <<"\n";

    div_t divres;
    divres = std::div(35, 7);
    /*integer part - quot, rem- remainder */
    //std::cout<< divres.quot << "\n" << divres.rem << "\n";
    
    /* retrun environment variable of OS */
    const char *path = std::getenv("PATH");
    //std::cout<< path << "\n";
    
    /* std::abs return a absolute value */
    int32_t aval = std::abs(-3);
    // std::cout<< aval << '\n';

    /* returns the number of bytes that are contained in the multibyte character  */
    const char *lstr = u8"z\u00df\u6c34\U0001d10b";; // wchar_t
    // int lenght = std::mblen(lstr, std::strlen(lstr));
    //std::cout<< lenght << '\n';

    /* std::mbstowcs */
    //std::setlocale(LC_ALL, "en_US.utf8");
    //tobj.print_mb(wbstr);
    
    /* rand , srand */
    // std::srand(std::time(0)); // use current time
    // int rdn = std::rand();
    // std::cout<< rdn;

    /* std::qsort */
    std::qsort(arr, sizearr, sizeof *arr, comparePredForBSearch);
    for( int elem: arr){
        std::cout<< elem <<"\n";
    }
    //std::exit(EXIT_SUCCESS);

    return 0;
}
