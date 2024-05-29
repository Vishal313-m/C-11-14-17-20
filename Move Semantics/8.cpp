// https://www.youtube.com/watch?v=pIzaZbKUw2s



//other LInks
//https://www.youtube.com/watch?v=0GXnfi9RAlU
//https://www.youtube.com/watch?v=Bt3zcJZIalk
//https://www.youtube.com/watch?v=PNRju6_yn3o&t=1997s

/*The purpose of std::forward is to preserve the value category (lvalue or rvalue) of its argument when passing it to another function. 
This is particularly useful when writing generic code that needs to pass arguments to other functions while maintaining their original value category.
Here's how std::forward works:
If the argument passed to std::forward is an lvalue, it returns an lvalue reference to the original argument.
If the argument passed to std::forward is an rvalue, it returns an rvalue reference to the original argument.*/


/*std::forward
std::forward is a utility function in C++ that is used to forward arguments exactly as they were passed to a function.
 It is typically used in template functions, especially in the implementation of forwarding references (also known as universal references).

The purpose of std::forward is to preserve the value category (lvalue or rvalue) of the argument that is passed to a function template, 
allowing perfect forwarding. This means that if an rvalue is passed to a function, std::forward will cast it to an rvalue reference, and if an lvalue is passed, 
it will cast it to an lvalue reference. This helps in forwarding arguments to another function while preserving their value category.*/



/*std::forward: Used to forward arguments exactly as they were passed, preserving their value category (lvalue or rvalue).
std::move: Used to cast a value to an rvalue, typically to enable the move semantics and transfer ownership.*/

#include<iostream>
#include<utility>


void inner(int&& x)
{
    std::cout<<"Rvalue x:"<<x<<"\n";
}

void inner(int& x)
{
    std::cout<<"Lvalue x:"<<x<<"\n";
}

template <typename T>
void wrapper(T&& arg)
{
    inner(std::forward<T>(arg));
}


int main()
{
    int x=5;
    wrapper(x);    // 'x' is an Lvalue , forwarded as an Lvalue
    wrapper(50);   // '50' is an Rvalue , forwarded as an rvalue
}

/*
OUTPUT

Lvalue x: 5
Rvalue x: 50


*/


----------------------------Important--------------------------------------------------


std::forward vs std::move
#include <iostream>

/* This function takes an lvalue reference */
void equivalent(int& a) {
    std::cout << "int&: " << a << std::endl;
}

/* This function takes an rvalue reference */
void equivalent(int&& a) {
    std::cout << "int&&: " << a << std::endl;
}

/* This function calls equivalent with std::move, converting the argument to an rvalue reference */
template <typename T>
void func1(T&& a) {
    equivalent(std::move(a));
}

/* This function calls equivalent with std::forward, preserving the argument's original value category */
template <typename T>
void func2(T&& a) {
    equivalent(std::forward<T>(a));
}

int main() {
    int arg = 10;

    std::cout << "Calling func1 with std::move()..." << std::endl;
    func1(arg); /* arg is an lvalue */
    func1(25);  /* 25 is an rvalue  */

    std::cout << "Calling func2 with std::forward()..." << std::endl;
    func2(arg); /* arg is an lvalue */
    func2(25);  /* 25 is an rvalue  */

    return 0;
}


/*OUTPUT
Calling func1 with std::move()...
int&&: 10
int&&: 25
Calling func2 with std::forward()...
int&: 10
int&&: 25

*/