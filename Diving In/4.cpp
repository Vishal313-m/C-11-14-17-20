/*Statements and Functions */

/* A Statement is a basic unit of computation in a c++ program  */
/* Every C++ program is a collection of statements organized in a certain way to achieve some goal */
/* Statement end with a semicolon in c++(;) */

/* Statements are executed in order from top to bottom when the program is run */
/* Execution keeps going until there is a statement causing program to terminate , or run another sequence of statements */


/*Functions in C++
Definition: Functions in C++ are blocks of code that perform specific tasks when called. They promote code reusability and modularity.

Types of Functions:
- Standard Library Functions: Predefined in C++ for common tasks.
-User-defined Functions: Created by programmers to encapsulate specific functionality.

Function Declaration:
- Syntax: returnType functionName(parameters) { // function body }
- Example: void greet() { cout << "Hello World"; }

Function Calling:
- Functions are invoked by using their name followed by parentheses.
- Example: greet();

Function Return Types:
- Functions can return values using a specified data type.
- Example: int add(int a, int b) { return (a + b); }

Function Prototypes:
- Used to declare a function before calling it when the function definition appears later in the code.
- Example: void add(int, int);*/

/*Function must be defined before its use */


#include <iostream>

int addNumbers( int first_param, int second_param){
    int result = first_param + second_param;
    return result;
}

int main(){

    int first_number {13}; // Statement
    int second_number {7};

    std::cout << "First number : " << first_number << std::endl; // 13
    std::cout << "Second number : " << second_number << std::endl; // 7

    int sum = first_number + second_number;
    std::cout << "Sum : " << sum << std::endl; // 20

    sum = addNumbers(25,7);
    std::cout << "Sum : " << sum << std::endl; // 32

    sum = addNumbers(30,54);
    std::cout << "Sum : " << sum << std::endl;

    std::cout << "Sum : " << addNumbers(3,42) << std::endl;


    return 0;
}