// IF CONSTEXPR


/*
constexpr if is a C++17 feature that allows for conditional compilation based on constant expressions.
 It enables the compiler to discard branches of an if statement at compile-time, depending on the value of the constant expression condition.
Here's how constexpr if works:

cpp
template <typename T>
auto getValue(T t) {
    if constexpr (std::is_pointer_v<T>) // (1)
        return *t; // deduces return type to int for T = int*
    else // (2)
        return t; // deduces return type to int for T = int
}

In this example:
The if constexpr condition checks if T is a pointer type using the std::is_pointer_v type trait.
If T is a pointer, the code in the if branch (1) is compiled, which dereferences the pointer.
If T is not a pointer, the code in the else branch (2) is compiled, which simply returns the value.


The key points about constexpr if are:
The expression in constexpr if must be a compile-time constant expression.
The compiler will only compile the branch that matches the constant expression, discarding the other branch(es).
Both branches must be valid, even though only one will be compiled.
constexpr if simplifies template metaprogramming by making the code more readable and easier to write.
 For example, the factorial calculation using constexpr if looks like a regular function:
cpp
template <int N>
constexpr int factorial() {
    if constexpr (N >= 2)
        return N * factorial<N-1>();
    else
        return N;
}

In summary, constexpr if is a powerful C++17 feature that enables compile-time conditional compilation based on constant expressions, leading to more efficient and readable code.

*/


#include <iostream>
#include <type_traits>


void func_floating_point  (double d) {
	std::cout << "func_floating_point called..." << std::endl;
} 
void func_integral(int i) { 
	std::cout << "func_integral called..." << std::endl;
} 

template <typename T>
void func(T t)
{
    if constexpr(std::is_integral_v<T>)
        func_integral(t);
    else if constexpr(std::is_floating_point_v<T>)
        func_floating_point(t);
    else
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
			"Argument must be integral or floating point");
}


int main(){

    func(12);

    return 0;
}