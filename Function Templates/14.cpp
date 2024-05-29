// TYPE TRAITS 

/*In C++, type traits are a fundamental aspect of template metaprogramming that allow for the inspection and transformation of type properties at compile time. 
They provide a way to query the compiler about various characteristics of types and perform operations based on these characteristics.
 Type traits are part of the <type_traits> header introduced in C++11, offering a collection of tools to work with different data types efficiently.*/


 /*
 
#include <iostream>
#include <type_traits>

template <typename T>
void checkType(T value) {
    if (std::is_integral<T>::value) {
        std::cout << "Type is integral." << std::endl;
    } else {
        std::cout << "Type is not integral." << std::endl;
    }
}

int main() {
    checkType(5); // Output: Type is integral.
    checkType(3.14); // Output: Type is not integral.
    
    return 0;
}
 
 
 */


#include <iostream>
#include <type_traits>

template <typename T>
void print_number( T n){
    //static_assert(std::is_integral<T>::value ,"print_number() can only be called with integral types" );
    static_assert(std::is_integral_v<T> ,"print_number() can only be called with integral types" );
    std::cout << "number : " << n << std::endl;
}


int main(){

    /*
    std::cout << std::boolalpha;
    std::cout << "std::is_integral<int> : " << std::is_integral<int>::value << std::endl;
    std::cout << "std::is_floating_point<int> : " << std::is_floating_point<int>::value << std::endl;

    std::cout << "-------------" << std::endl;

    std::cout << "std::is_integral_v<int> : " << std::is_integral_v<int> << std::endl;
    std::cout << "std::is_floating_point_v<int> : " << std::is_floating_point_v<int> << std::endl;
    */

   /*
   double a{7};
   print_number(a);
   */

    auto func = []<typename T>(T a, T b){
        static_assert(std::is_integral_v<T>,"func can only be called with integral types");
        return a + b;
    };

    double x {7};
    double y{6};
    func(x,y);
   
    return 0;
}