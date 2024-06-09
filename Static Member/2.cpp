--- Static member variable in c++

A static member variable in C++ is a class member that is shared by all objects of the class, 
meaning there is only one copy of the static member variable regardless of how many objects of the class are created. 
Static member variables are initialized before any object of the class is created and can be accessed without the need to create an object of the class.
In C++, static member variables must be defined outside the class, typically after the class declaration and before the main function. 
The scope resolution operator (::) is used to access static member variables. 
Any changes made to a static member variable are reflected across all objects of the class since they share the same memory block for the static member variable.

Static member variables are commonly used to store information that is shared among all objects of a class,
 such as counting the number of objects created or maintaining a common value across instances. 
 They are a powerful tool for managing shared data within a class and can be accessed using either the class name or an object of the class.
In summary, a static member variable in C++ is a class member that is shared by all objects of the class, 
with only one copy of the variable existing regardless of the number of objects created. 
Static member variables are initialized before any object is created, defined outside the class, and can be accessed without creating an object of the class


#include <iostream>

class MyClass {
public:
    // Declaration of static member variable
    static int staticVar;
};

// Definition of static member variable (outside the class)
int MyClass::staticVar = 0;

int main() {
    // Accessing static member variable using class name and scope resolution operator ::
    std::cout << "Initial value of staticVar: " << MyClass::staticVar << std::endl;

    // Modifying static member variable
    MyClass::staticVar = 10;

    // Accessing static member variable again
    std::cout << "Modified value of staticVar: " << MyClass::staticVar << std::endl;

    // You can also access static member variable using an object of the class,
    // but it's not recommended because it can be confusing.
    MyClass obj;
    std::cout << "Accessing through an object: " << obj.staticVar << std::endl;

    return 0;
}


