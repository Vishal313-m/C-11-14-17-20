/*  Virtual Functions With Default Arguments */ 

/*  when we say default arguments, we mean a setup like this.

We have a virtual function here, which is called and it is going to return double and it has default parameters here for A and B, and the value is 5 Here in our derived class, 
we also have the same function.
We are overriding that and we have a different set of values acting as our default parameter.
Here we are using 10 for A and B here and we want to see how this plays with polymorphism.
Now please note that with polymorphism, if we go through a base pointer to manage a derived class object,
what we want is to call the most specific implementation of the virtual function here.
For example, if we have a base pointer managing a derived object and we call the Add method from a
base pointer, we will get the most specific method here called.
But what you get with this default arguments is that the compiler is going to use static binding to
decide which default parameters to pass to your function.
------So even if you will get this method here called, the compiler will still use the default arguments we have in our base class.*/



/*
- Default arguments are handled at compile time 
- Virtual Functions are called at run time with polymorphism
- If you use default arguments with Virtual functions , you might get weird results with polymorphism.

*/


#include<iostream>
using namespace std;

class Base
{
    
    public:
    
    virtual double add(double a = 5 , double b = 5) const
    {
      cout << "Base::add() called" << std::endl;
        return (a + b + 1);
    }
};

class Derived : public  Base 
{
    
    
    public:
   
    double add(double a = 10 , double b = 10) const override
    {
        std::cout << "Derived::add() called" << std::endl;
        return (a + b +2);
    }
};
 int main()
 {//Base ptr : Uses polymorphism
    Base * base_ptr1 = new Derived;
    double result = base_ptr1->add();
    std::cout <<"Result (base ptr) : " << result  << std::endl; //12


    std::cout << "---------------------"<< std::endl;
	
    //Base ref : Uses Polymorphism
    Derived derived1;
    Base& base_ref1 = derived1;
    result = base_ref1.add();
    std::cout << "Result (base ref) : " << result << std::endl; // 12
    
    std::cout << "---------------------"<< std::endl;


    //Raw objects
    Base base3;
    result = base3.add();
    std::cout << "raw result : " << result << std::endl;

    std::cout << "---------------------"<< std::endl;

    //Direct object : Uses static binding
    Derived derived2;
    result = derived2.add();
    std::cout << "Result (Direct object) : " << result << std::endl; // 22
	
    std::cout << "---------------------"<< std::endl;

	//Raw objects - slicing : uses static binding
	Base base1 = derived2;
	result = base1.add();
    std::cout << "Result (Raw objects assignment) : " << result << std::endl; //11

   
    return 0;
     
 }


 /*
 OUTPUT 
 Derived::add() called
Result (base ptr) : 12
---------------------
Derived::add() called
Result (base ref) : 12
---------------------
Base::add() called
raw result : 11
---------------------
Derived::add() called
Result (Direct object) : 22
---------------------
Base::add() called
Result (Raw objects assignment) : 11
 
 
 */