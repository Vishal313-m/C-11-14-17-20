/*

Question 

template <typename T>
void f(T&& arg);


template <typename T>
void f(T const && arg);

why after putting const in forwarding reference become rvalue reference


*/

The difference in behavior arises from how template type deduction works in C++. 
Let's delve deeper into the mechanics of type deduction to understand why adding const 
changes the nature of the reference from a forwarding reference to an rvalue reference.

Template Type Deduction Rules
When a function template is instantiated, the type of the argument determines how the template parameter is deduced. Here’s a quick summary:

Without const:

cpp

template <typename T>
void f(T&& arg);

In this form, T&& can be a forwarding reference (also known as a universal reference)
 because the template type deduction allows T to be deduced differently depending on whether the argument is an lvalue or an rvalue:

If you pass an lvalue (e.g., int x = 5; f(x);), T is deduced as int&, and T&& becomes int& &, which collapses to int& (lvalue reference).
If you pass an rvalue (e.g., f(5);), T is deduced as int, and T&& becomes int&& (rvalue reference).
This flexibility allows the function to forward the argument exactly as received.





With const:

cpp
Copy code
template <typename T>
void f(T const&& arg);
When you add const, you alter the type deduction:

The argument type T is deduced to match the type of the argument, but with const&& added.
For example, if you pass an rvalue of type int, T is deduced as int, and T const&& becomes int const&& (rvalue reference to a const int).
Why Adding const Changes the Behavior
The key reason adding const changes the behavior is due to the additional type qualifier. Here’s how it impacts type deduction and reference collapsing:

Original Template (Forwarding Reference):

cpp

template <typename T>
void f(T&& arg);
Passing an lvalue: T is deduced as int&, resulting in T&& being int& && which collapses to int&.
Passing an rvalue: T is deduced as int, resulting in T&& being int&&.
Modified Template (Rvalue Reference):

cpp
Copy code
template <typename T>
void f(T const&& arg);
Passing an rvalue of type int: T is deduced as int, resulting in T const&& being int const&&.
Note that passing an lvalue to T const&& will not work directly because an lvalue cannot bind to an rvalue reference, even if the latter is const-qualified.
Example to Illustrate
Consider these two functions:

cpp
Copy code
template <typename T>
void f(T&& arg) {
    std::cout << "f(T&&)\n";
}

template <typename T>
void f(T const&& arg) {
    std::cout << "f(T const&&)\n";
}

int x = 5;
f(x); // calls f<int&> and outputs "f(T&&)\n" due to lvalue reference
f(std::move(x)); // calls f<int&&> and outputs "f(T&&)\n" due to rvalue reference

f(5); // calls f<int&&> and outputs "f(T&&)\n" due to rvalue reference

f(int{5}); // calls f<int const&&> and outputs "f(T const&&)\n"
In summary, the presence of const changes the template parameter from a potentially deducible form (which allows it to match both lvalues and rvalues) to a specific form that matches only rvalues to const-qualified types, thus no longer acting as a forwarding reference.






