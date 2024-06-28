void Pointer in C++

In C++, a void pointer is a pointer that is declared using the ‘void‘ keyword (void*). It is different from regular pointers it is used to point to data of no specified data type. 
It can point to any type of data so it is also called a “Generic Pointer“. 

Syntax of Void Pointer in C++
void* ptr_name;
As the type of data the void pointer is pointing to is unknown, we cannot dereference a void pointer.

Example of Void Pointer in C++
The below example demonstrates the declaration and use of void pointer in C++.


// C++ Program to demonstrate the declaration and use of a 
// void pointer 
  
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int a = 10; 
  
    // void pointer holds address of int 'a' 
    void* myptr = &a; 
    // printing the value of a and adress of a stored in 
    // myptr 
    cout << "The value of a is: " << a << endl; 
    cout << "The Adress of a is  " << myptr << endl; 
}
Output
The value of a is: 10
The Adress of a is  0x7ffd9ac02a64
Application of Void Pointer in C++
1. Generic Coding
The concept of a generic pointer means a pointer that can be used to point to data of any data type. This is helpful in situations where you need a 
single pointer that can handle different data types dynamically.

Let’s see an example for this, let’s first declare variables of different types (int, double, char). then declare a void pointer named “generic pointer”. 
We use the void pointer to point to each of the variables in succession with the help of typecasting.

Example

Below is a program in which an int type pointer is declared and we try to point the value of a float datatype using it. Let’s See what happens.


// C++ program to demonstrate the need for void pointer 
  
#include <iostream> 
using namespace std; 
int main() 
{ 
    int* ptr; 
    float f = 90.6; 
    ptr = &f; // error 
    cout << "The value of *ptr is : " << *ptr << endl; 
    return 0; 
}
Output

error: cannot convert ‘float*’ to ‘int*’ in assignment
Explanation: The above program gives an error the reason is int type pointer ptr is declared and we are trying to store the memory address of a float data type into an int pointer,
 which gives an error. But if we declare void pointer it allows us to change their data type. So, declare ptr as a void pointer and the program will not give any error. 
 The below example demonstrates the same.


// C++ Program to demonstrate the use of void pointer 
// to hold the address of any type-castable type 
  
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    // Initializing multiple variables of different data 
    // type 
    int n = 10; 
    float f = 25.25; 
    char c = '$'; 
  
    // Initializing a void pointer 
    void* ptr; 
  
    ptr = &n; // pointing to int 
    cout << "The value of n " << n << endl; 
    cout << "The Adress of n " << ptr << endl; 
  
    ptr = &f; // pointing to float 
    cout << "The value of n " << f << endl; 
    cout << "The Adress of n " << ptr << endl; 
  
    ptr = &c; // pointing to char 
    cout << "The value of n " << c << endl; 
    cout << "The Adress of n " << ptr << endl; 
}
Output
The value of n 10
The Adress of n 0x7ffe05023434
The value of n 25.25
The Adress of n 0x7ffe05023430
The value of n $
The Adress of n 0x7ffe0502342f
Explanation: In the above Code, We declared a void pointer as the variable name “ptr” which acts as a generic pointer or void pointer. 
This pointer stores multiple datatype addresses like int, char and float. We Typecasted the void pointer to any data type (float, char, int).
 Hence Void Pointer allows us to change the addresses for different memory addresses of different data types.

2. Dynamic Memory Allocation
Dynamic memory allocation is performed in C++, when the size of memory needed is not known at compile time then we perform Dynamic memory Allocation using operators 
like new or malloc. Void pointers can be used to allocate memory for any data type. In C++, “new” keyword is used for dynamic memory allocation which returns a pointer to
 the allocated memory. After allocating memory, We need perform type casting to use the allocated memory with a specific data type.

Example

The below program demonstrate the use of void pointer to dynamically allocate memory for any data type.


// C++ program to demonstrate the use of void pointer to 
// dynamically allocate memory for any data type. 
  
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    // Allocate memory for an integer using new 
    void* voidPtr = new int; 
  
    // Type casting the void pointer to int* for usage 
    int* intPtr = static_cast<int*>(voidPtr); 
  
    // Assign a value to the allocated memory 
    *intPtr = 42; 
  
    // Print the value from the allocated memory 
    cout << "Value from allocated memory: " << *intPtr 
         << endl; 
  
    // Deallocate the memory 
    delete intPtr; 
  
    return 0; 
}
Output
Value from allocated memory: 42
3. Callback Functions
Functions that are passed as arguments to other functions are called callback functions. In case we need to handle multiple data types, 
the void pointer can be used as a void pointer provides us the flexibility to handle different data types. Callback functions can be defined to accept a void pointer as a parameter, 
enabling them to handle different types of data. This approach simplifies the code because this approach maintains different data types in a single callback.

Example

The below program demonstrates the use of the void function to pass a void pointer as a parameter in a callback function.


// The below program demonstrate the use of void function to 
// pass void pointer as parameter in callback function. 
  
#include <iostream> 
using namespace std; 
  
// Callback function definition 
void CallbackFunction(void* data, char dataType) 
{ 
    switch (dataType) { 
    case 'i': 
        cout << "Callback for integer: " << *(int*)data 
             << endl; 
        break; 
    case 'd': 
        cout << "Callback for double: " << *(double*)data 
             << endl; 
        break; 
    default: 
        cout << "Unsupported data type in callback!"
             << endl; 
    } 
} 
  
// Function that takes a callback 
void PerformOperation(void* data, char dataType, 
                      void (*callback)(void*, char)) 
{ 
  
    // Call the callback function 
    callback(data, dataType); 
} 
  
int main() 
{ 
    int intValue = 07; 
    double doubleValue = 8.12; 
  
    // Perform operation with integer and callback 
    PerformOperation(&intValue, 'i', CallbackFunction); 
  
    // Perform operation with double and callback 
    PerformOperation(&doubleValue, 'd', CallbackFunction); 
  
    return 0; 
}
Output
Callback for integer: 7
Callback for double: 8.12
Advantages of void Pointer in C++
The void pointer have the following major applications:

The use of void pointers can help reduce redundant code by allowing a single piece of code to handle multiple data types.
Void pointer allows abstraction of specific types in favor of a more general interface. This is common in scenarios like polymorphic containers or callback systems.
A void pointer can be declared to deal with polymorphism.
Void pointers can enhance platform independence where the sizes and representations of data types may vary across different architectures.
Conclusion
In conclusion, void pointers in C++ offer flexibility and versatility in certain programming scenarios, but this demands careful consideration. Modern C++ offers safer alternatives, 
like smart pointers for memory management.