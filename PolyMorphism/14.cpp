/*  DYNAMIC CAST */

/* A cast is an operator that converts data from one type to another type. 
In C++, dynamic casting is mainly used for safe downcasting at run time. To work on dynamic_cast there must be one virtual function in the base class. 
A dynamic_cast works only polymorphic base class because it uses this information to decide safe downcasting. 

Syntax:

dynamic_cast <new_type>(Expression)

Downcasting: Casting a base class pointer (or reference) to a derived class pointer (or reference) is known as downcasting.
 In figure 1  casting from the Base class pointer/reference to the “derived class 1” pointer/reference showing downcasting (Base ->Derived class).


Upcasting: Casting a derived class pointer (or reference) to a base class pointer (or reference) is known as upcasting. 
In figure 1 Casting from Derived class 2 pointer/reference to the “Base class” pointer/reference showing Upcasting (Derived class 2 -> Base Class).
 */


#include<iostream>
using namespace std;

class base
{
    public:
    void func()
    {
        cout<<"base func is called"<<endl;
    }
};

class derived1 : public base
{
    public:
    void func()
    {
        cout<<"derived1 func is called"<<endl;
    }
    
 
};

class derived2 : public base 
{
    
    public:
    void func()
    {
        cout<<"derived2 func is called"<<endl;
    }
    
};

int main()
{
    base *ptr = new derived1;
    derived1 *dptr = dynamic_cast<derived1*>(ptr);
  
}

/*

main.cpp: In function ‘int main()’:
main.cpp:38:22: error: cannot ‘dynamic_cast’ ‘ptr’ (of type ‘class base*’) to type ‘class derived1*’ (source type is not polymorphic)
   38 |     derived1 *dptr = dynamic_cast<derived1*>(ptr);
      |                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

/*------------------------------------------------------------------------------------------------------------------------------------*/


#include<iostream>
using namespace std;

class base
{
    public:
    virtual void func()
    {
        cout<<"base func is called"<<endl;
    }
};

class derived1 : public base
{
    public:
    void func()
    {
        cout<<"derived1 func is called"<<endl;
    }
    
 
};

class derived2 : public base 
{
    
    public:
    void func()
    {
        cout<<"derived2 func is called"<<endl;
    }
    
};

int main()
{
    base *ptr = new derived1;
    derived1 *dptr = dynamic_cast<derived1*>(ptr);
     if (dptr == nullptr)
        cout << "null" << endl;
    else
        cout << "not null" << endl;
  
}

/*
OUTPUT
not null
It returns a null pointer if the cast is not possible, indicating that the object being pointed to is not of the expected derived type. 
*/



/* The main benefit of this is to be able to call Non- Polymorphic methods on derived pointers */


#include<iostream>
using namespace std;

class base
{
    public:
    virtual void func()
    {
        cout<<"base func is called"<<endl;
    }
};

class derived1 : public base
{
    public:
    void func()
    {
        cout<<"derived1 func is called"<<endl;
    }
    
    void draw()
    {
        cout<<"derived1 draw is called"<<endl;
    }
 
};

class derived2 : public base 
{
    
    public:
    void func()
    {
        cout<<"derived2 func is called"<<endl;
    }
    
};

int main()
{
    base *ptr = new derived1;
    derived1 *dptr = dynamic_cast<derived1*>(ptr);
     if (dptr)
        dptr->draw();
    else
        cout << "coudn't cast" << endl;
  
}

/*
OUTPUT
derived1 draw is called


*/