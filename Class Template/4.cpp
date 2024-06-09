// Explicit Template Instantiations 


/*
- The compiler generates the instances based on the arguments you provide

- Template instances are put exactly where your template class statements are in your code

- All members of the class template are instantiated ,regardless of whether they are used or not

- This feature is useful to debug your class template code

*/



Explicit template instantiations in C++ are used to manually generate template instances for specific types. This can be useful for several reasons:


Reducing Compile Times and Output Sizes: By explicitly instantiating templates, you can reduce compile times and output sizes by avoiding unnecessary instantiations. 
This is particularly important when working with large projects where compile times can be significant.


Removing Definitions from Headers: Explicit instantiation allows you to leave definitions in the .cpp file, 
which can help in reducing compile times. When definitions are in header files and you modify them, an intelligent build system would recompile all includers, 
which could be dozens of files, making incremental re-compilation after a single file change unbearably slow.


Avoiding Object Redefinition: If you completely define a template on a header file, every single compilation unit that includes that header
 ends up compiling its own implicit copy of the template for every different template argument usage made. 
 This can lead to a lot of useless disk usage and compilation time. Explicit instantiation helps in avoiding this redundancy.


Hiding Template Implementations: Explicit template instantiation can help in hiding the definition of templates.
 This is done by putting the template declaration in the header file and the template definition in the source file. 
 Then, at the end of the source file, you explicitly instantiate only the version you want to be available.

Suppressing Template Instantiation: Explicit instantiation can also be used to suppress template instantiation. 
This is done by using the extern keyword in C++11. This means that the compiler does not generate a template instantiation, 
and the linker throws away all template instantiations but one, reducing waste of computing time.

Here is an example of explicit template instantiation:


// MyClass.h
#include <typeinfo>
#include <string>

template <typename T>
class MyClass {
public:
    MyClass(T t) { }
    std::string getType() const;
};

// MyClass.cpp
#include "MyClass.h"

template <typename T>
std::string MyClass<T>::getType() const {
    return typeid(T).name();
}

template class MyClass<int>; // Explicit instantiation for int

// mainMyClass.cpp
#include "MyClass.h"
#include <iostream>

int main() {
    MyClass myClass(5);
    std::cout << "myClass.getType(): " << myClass.getType() << '\n';
    return 0;
}

In this example, MyClass is a template class with a member function getType(). The template definition is in MyClass.cpp, 
and the explicit instantiation for int is done at the end of MyClass.cpp. This means that only the int version of MyClass is generated, 
reducing unnecessary instantiations.
