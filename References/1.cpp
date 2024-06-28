/*References in C++ are aliases that provide an alternative name for an existing variable.*/

Properties of References
- References must be initialized when they are created=
- Once a reference is initialized, it cannot be changed to refer to another variable
- References cannot be null. They must always refer to a valid memory location.
-  References are usually used as function parameters and return values


References vs Pointers

- References cannot be null, while pointers can.
- Once a reference is initialized, it cannot be changed to refer to another variable, but pointers can be made to point to different variables.
- References must be initialized when they are created, while pointers can be initialized at any time.



Use Cases

- Function parameters: References allow you to pass arguments to functions by reference, avoiding the need to create copies of the arguments

- Function return values: Functions can return references to allow modifying the original variables

- Nested data access: References can be used to easily access nested data structures



/*


#include<iostream>
using namespace std;


int main()
{
    int a = 4;
    int b = 5;
    cout<<&a<<endl;
    cout<<&b<<endl;
    
    int &ref = a;
    
    cout<<&ref<<endl;
    
    ref = b;
    
    cout<<"---------------------------"<<endl;
     cout<<&ref<<endl;
    
     cout<<"---------------------------"<<endl;
     cout<<ref<<endl;
    
     cout<<"---------------------------"<<endl;
     cout<<a<<endl;
     
    
    
}


OUTPUT

0x7fff0fb365d8
0x7fff0fb365dc
0x7fff0fb365d8
---------------------------
0x7fff0fb365d8
---------------------------
5
---------------------------
5

*/





/*
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Declare a reference to x
    int& ref_x = x;

    // Attempt to change the reference to refer to y
    ref_x = y; // This does not change the reference, it just assigns the value of y to x

    std::cout << "x = " << x << std::endl; // Output: x = 20
    std::cout << "y = " << y << std::endl; // Output: y = 20
    std::cout << "ref_x = " << ref_x << std::endl; // Output: ref_x = 20

    return 0;
}

*/
int a = 5;
int &b = a;

std::cout << a << std::endl;  // 5

std::cout << b << std::endl;  // 5


std::cout << &a << std::endl;  // 0x7ffc1ab0ebbc

std::cout << &b << std::endl;  // 0x7ffc1ab0ebbc




#include <iostream>

int main(){

    int int_data{33};
    double double_data{55};

    //References
    int& ref_int_data{int_data};
    double& ref_double_data{double_data};

    //Print stuff out
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

    int_data = 111;
    double_data = 67.2;


    //Print stuff out
    std::cout << std::endl;
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;


    ref_int_data = 1012;
    ref_double_data = 1000.45;


   //Print stuff out
    std::cout << std::endl;
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
    
    return 0;
}
