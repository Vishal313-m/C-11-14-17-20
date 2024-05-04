/*Compile-Time Errors
Compile-time errors are errors that are detected by the compiler when you try to compile your C++ code. 
These errors prevent the program from being successfully compiled and must be fixed before the program can be executed. Some common examples of compile-time errors include:

Syntax Errors
- Missing semicolons, parentheses, or curly braces
- Incorrect use of language constructs like loops, conditionals, or function declarations

Type Mismatch Errors
- Assigning a value of one data type to a variable of an incompatible data type
- Passing arguments of the wrong type to a function

Linker Errors
- Unresolved external references (e.g. missing function definitions)
- Name collisions between global variables or functions

*/


/*
Runtime Errors
Runtime errors are errors that occur during the execution of a C++ program, after it has been successfully compiled. 
These errors can cause the program to crash or produce incorrect results. Some common examples of runtime errors include:

Segmentation Faults
- Dereferencing a null pointer
- Accessing an array element outside of the array bounds

Arithmetic Errors
- Division by zero
- Overflow or underflow of numeric values

Resource Leaks
- Failing to properly allocate or deallocate memory
- Failing to close file handles or network connections


*/

/*
Warnings
Warnings are not errors, but rather messages from the compiler that indicate potential issues in the code that may lead to problems, 
even though the code is still valid and can be compiled. Some common examples of warnings include:
- Unused variables or functions
- Implicit type conversions
- Deprecated or non-standard language features
- Uninitialized variables
- Warnings should be taken seriously, as they can often indicate underlying problems in the code that may lead to runtime errors or unexpected behavior.
*/


#include <iostream>

int main(){
   
   //Compile time error
   std::cout << "Hello Word!" << std::endl;

   //Run time error
   int value = 7/0;
   std::cout << "value : " << value << std::endl;

    return 0;
}