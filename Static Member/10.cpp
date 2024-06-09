// NESTED CLASSES 


Nested classes in C++17 allow you to define a class inside another class.
The class inside which a nested class is declared is called the enclosing class. Here are the key points about nested classes in C++:


Syntax: A nested class is declared inside the scope of another class using the class keyword. 

cpp
class EnclosingClass {
    // members
    class NestedClass {
        // members
    };
};

Access: Nested classes have the same access rights as other class members. 
Private members of the nested class can be accessed by member functions of the nested class. 



Enclosing class access: The enclosing class has no special access to private members of the nested class. The usual access rules apply. 

Scope: Nested classes are scoped to the enclosing class.
 They can be accessed using the scope resolution operator (EnclosingClass::NestedClass) outside the enclosing class. 

Instantiation: To create an object of a nested class, you need an object of the enclosing class or use the scope resolution operator. 
cpp
EnclosingClass::NestedClass obj;

Motivation: Nested classes can be used to hide implementation details, improve code organization, and provide a namespace for related classes. 

Limitations: Nested classes cannot access private members of the enclosing class directly.
 They must use public member functions to interact with private members. 


In summary, nested classes in C++ allow you to define classes within classes, providing a way to organize related 
functionality and hide implementation details. They follow the usual access rules and can be accessed using the scope resolution operator.


/*
SOME FACTS ABOUT NESTED CLASSES

- When inner is private , its objects can't be created from the outside,like in main

- Outer doesn't have access to private section of inner 

- Inner has access to private section of outer

- Inner can directly access static members of Outer , but can't access member variables without going through an object 





*/


#ifndef OUTER_H
#define OUTER_H

#include <iostream>

class Outer
{
public:
    Outer(int int_param, double double_param);
    Outer();
    ~Outer();
    
    void do_something(){
        Inner inner1(10.0);
        //std::cout << "Created inner object with value : " <<inner1.get_double() <<  std::endl;
        //inner1.inner_var; // Outer doesn't have access to private parts of Inner
                            // Has to go through setters and getters
                            
        inner1.do_something_with_outer(this);
    }
	
    
private : 
    int m_var1;
    double m_var2;
    inline static int static_int{45};
public : 
    class Inner{
        public: 
            Inner(double double_param);
			
            double get_double() const{
                //Accessing private parts of Outer
                //std::cout << "Inner accessing m_var1 : " << m_var1 << std::endl;// Compiler error.
                std::cout << "static_int : " << static_int << std::endl;
                return inner_var;
            }
            
            void do_something_with_outer(Outer * outer){
               std::cout << "This is inner accessing private parts of outer object, m_var1 : "  <<
               outer->m_var1 << std::endl;
            }
          
    private : 
            double inner_var;
    };

};

#endif // OUTER_H



#include "outer.h"
Outer::Outer(int int_param, double double_param)
    : m_var1(int_param) , m_var2(double_param)
{
}

//default constructor . Delegates to two param constructor
Outer::Outer() : Outer(0,0.0){
    
}

Outer::~Outer()
{
}

Outer::Inner::Inner(double double_param) : inner_var(double_param){
    
}


#include <iostream>
#include "outer.h"


int main(){

    Outer outer1(10,20.1);
    outer1.do_something();

    
   
    return 0;
}