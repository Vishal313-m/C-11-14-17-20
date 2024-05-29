// Size of class objects 
/*
The size of a class object in C++ is determined by several factors, including the size of its non-static data members,
 the presence of virtual functions, and the compiler being used.

Here are the key points:

Non-static data members: The size of a class object includes the size of all its non-static data members.
 Static members are not part of the class object and do not contribute to its size.

Virtual functions: If a class has virtual functions, it will have a virtual table pointer (vptr) that points to a table of function pointers.
 The size of the vptr is typically the size of a pointer on the system, which is usually 4 bytes on 32-bit systems and 8 bytes on 64-bit systems.

Inheritance: If a class inherits from another class, its size will include the size of the base class.
 If the base class has virtual functions, the derived class will also have a vptr, but it will point to the same virtual table as the base class.

Compiler-specific behavior: The size of a class object can vary depending on the compiler being used. 
For example, the Microsoft C++ compiler may align classes on 4-byte or 8-byte boundaries, which can affect the size of the class object.

Padding and alignment: Compilers may add padding bytes to ensure proper alignment of data members, which can increase the size of the class object.
Mode of inheritance: In cases of virtual inheritance, there may be an additional overhead of 4 bytes for a virtual base class pointer.

Here are some examples of class objects and their sizes:
An empty class object typically has a size of 1 byte, as the C++ standard requires
 that each object must have a unique address.

A class with a virtual function will have a size that includes the size of the vptr,
 which is usually 4 bytes on 32-bit systems and 8 bytes on 64-bit systems.

A class that inherits from another class will have a size that includes the size of the base class, 
plus any additional data members or virtual functions it may have.

A class with both virtual functions and non-static data members will have a size that includes the size of the vptr and the size of the data members,
plus any padding or alignment required by the compiler.

In summary, the size of a class object in C++ is determined by the size of its non-static data members,
 the presence of virtual functions, inheritance, and compiler-specific behavior.

*/
#include <iostream>

class Dog{
    public : 
     Dog() = default;
     void prin_info(){

     }
     void do_something(){

     }

     private :
      size_t leg_count; //8
      size_t arm_count; //8
      int * p_age; // 8
};


int main(){

    Dog dog1;
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    std::cout << "sizeof(int*) : " << sizeof(int*) << std::endl;
    std::cout << "sizeof(Dog) : " << sizeof(dog1) << std::endl;

    std::string name{"I am the king of the universe!"};

    std::cout << "sizeof(name) : " << sizeof(name) << std::endl;
   
    return 0;
}



/*

OUTPUT 

sizeof(size_t) : 8
sizeof(int*) : 8
sizeof(Dog) : 24
sizeof(name) : 32




*/