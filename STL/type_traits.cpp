#include <type_traits>
#include <iostream>
#include <typeinfo>
#include <typeindex>

enum en {};
struct someStruct {
    someStruct() = default;
};

class someClass {
    someClass();
    someClass(const someClass&);
    someClass(someClass&&);
    virtual void somefunc() = 0;
};

class someClassSec : public someClass {
    void somefunc() {};
};

/* and more more checks
 is_fundamental, is_object, is_class, is_union etc. */
template< typename T >
T checkingForVoid(T value){
    /* this function ckeck for void type T
    accepts argument type std::integral_constant<T,v>, where
    T - value type
    v - type */
    bool check = std::is_void<T>::value;
    return check;
}

template< typename T >
T checkingForIntegral(T value){
    /* this function ckeck for void type T
    accepts argument type std::integral_constant<T,v>, where
    T - value type
    v - type */
    bool check = std::is_integral<T>::value;
    return check;
}

template<typename T>
typename std::enable_if_t<std::is_floating_point_v<T>, T> foo1(T t){
    std::cout << "type is float, ok \n";
    return t;
}

template<typename T, typename ... Ts>
std::enable_if_t<std::conjunction_v<std::is_same<T, Ts>...>>
func(T, Ts ...){
    std::cout << "All packs Ts... are type T \n";
}

template<typename T, typename ... Ts>
std::enable_if_t<!std::conjunction_v<std::is_same<T, Ts>...>>
func(T, Ts ...){
    std::cout << "All packs Ts... are not a type T \n";
}

int main()
{
    int arr[5]={};
    bool check;
    void* pointer; 
    // check = checkingForVoid(5);
    std::cout << std::boolalpha;
    // std::cout << check << '\n';
    std::cout << std::is_null_pointer<decltype(nullptr) >::value << '\n';
    std::cout << std::is_pointer_v<decltype(*arr)><< '\n';
    std::cout << std::is_void_v<decltype(pointer)> << '\n';
    // std::cout << std::is_null_pointer< void* >::value << '\n';
    check = checkingForIntegral(*arr);
    std::cout << "array is integral type? "<< check << '\n';
    std::cout << "en is enum? " << std::is_enum<en>::value << "\n\n";

    /* For all examples below - all structs included c++17 variant with _v prefix or _t
     Example: C++11: std::is_nothrow_move_constructible<someStruct>::value;
     C++17: std::is_nothrow_move_constructible_v<someStruct>;
     C++11: std::alignment_of<double>() or std::alignment_of<double>::value;
     C++17: std::alignment_of_v<double>; 
     C++11: std::enable<true, int>::type;
     C++17: std::enable_t<true, int>;*/

    /* check some structs or classes for constructibility / trivial constructibility */
    std::cout << "someStruct is default constructible? "<< std::is_default_constructible<someStruct>::value << '\n';
    std::cout << "someStruct is trivialy default constructible? "<< std::is_trivially_default_constructible<someStruct>::value << '\n';
    std::cout << "someStruct is no throw constructible? "<< std::is_nothrow_default_constructible<someStruct>::value << "\n\n";

    /* check some structs or classes for copy - constructor/ copy - trivial constructor */
    std::cout << "someClass is copy - constructible? "<< std::is_copy_constructible<someStruct>::value << '\n';
    std::cout << "someClass is trivialy copy - constructible? "<< std::is_trivially_copy_constructible<someStruct>::value << '\n';
    std::cout << "someClass is nothrow copy - constructible? "<< std::is_nothrow_copy_constructible<someStruct>::value << "\n\n";

    /* check some structs or classes for move - constructor/ move - trivial constructor */
    std::cout << "someClass is move - constructible? "<< std::is_move_constructible<someStruct>::value << '\n';
    std::cout << "someClass is trivialy move - constructible? "<< std::is_trivially_move_constructible<someStruct>::value << '\n';
    std::cout << "someClass is nothrow move - constructible? "<< std::is_nothrow_move_constructible<someStruct>::value << "\n\n";

    /* checks type for alignment requirements */
    // std::cout << std::alignment_of_v<double> << '\n';
    std::cout << std::alignment_of_v<someClass> << '\n';
    std::cout << std::alignment_of_v<someStruct> << '\n';

    auto arrdimention = std::rank_v<decltype(*arr)>;
    auto arrsize = std::extent_v<decltype(arr)>;

    /* measure of dimentions array */
    std::cout << arrdimention << '\n';
    
    /* measure for numbers in array */
    std::cout << arrsize << '\n' << "\n";

    /* std::is_same compare type T1 with T2 
    if T1 == T2 return true otherwise return false */
    std::cout << std::is_same_v<int,int> << '\n';
    std::cout << std::is_same_v<someClass, someStruct> << '\n';

    /* check inheritance check is it T1 ancestor of T2 
    std::is_base_of_v<T1, T2>; */
    std::cout << std::is_base_of_v<someClass, someClassSec> << '\n' << "\n";

    /* check is layot compatibility type */
   //std::cout << std::is_layout_compatible_v<someClass, someStruct>;
   
   /* Test std::enable_if_t */
    foo1(1.2);

    /* Test std::conjunction_t */
    func(1,2,3);
    func(1,3,"hello");
    
    return 0;
}
