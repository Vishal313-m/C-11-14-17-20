In C++, when a template is used, the compiler generates a concrete instance of the template for a specific combination of template arguments. 
This process is called template instantiation.

Instantiation of Templates

Class Templates:
A class template is instantiated when an object of that class is created. The compiler generates a concrete class by substituting
the template arguments for the template parameters in the template definition.

All members of the class template, including functions and data members, are also instantiated when the class is instantiated.
Function Templates:


A function template is instantiated when it is called with specific arguments. 
The compiler generates a concrete function by substituting the template arguments for the template parameters in the template definition.
Each instantiation of a function template is a version of the templated function specialized for the specific type used in the call.



Explicit Instantiation
Explicit instantiation is a way to force the compiler to generate a specific instantiation of a template without actually using it in the code. 
This is useful when creating libraries that use templates, as it allows the compiler 
to generate the necessary code without including the template definitions in the object files.


Implicit Instantiation
Implicit instantiation occurs when the compiler needs to generate a template instantiation to complete the code.
 This happens when a template is used in a context that requires a completely defined type, such as when an object of that type is constructed.


Key Points
Template Instantiation: The process of generating a concrete instance of a template for a specific combination of template arguments.
Class Template Instantiation: The generation of a concrete class by substituting template arguments for template parameters.
Function Template Instantiation: The generation of a concrete function by substituting template arguments for template parameters.
Explicit Instantiation: Forcing the compiler to generate a specific instantiation of a template without using it in the code.
Implicit Instantiation: The compiler generating a template instantiation when it is needed to complete the code.