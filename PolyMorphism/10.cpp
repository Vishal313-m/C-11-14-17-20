/*POLYMORPHIC FUNCTION AND ACCESS SPECIFIER*/

/* -------------------------------------------------------------------------------------------------------------------- ------------------------*/

/*If you  go through a base pointer to manage a derived class object , the compiler is just going to look at the access specifier in the base class 
and that's what it is going to follow  to decide whether you can access things from outside or not 
*/

/* ------------------------------------------------------------------------------------------------------------------------------------------------*/

/* When you call the virtual function through a bass class pointer, the access specifier in the base class determines  whether the function is accessible 
,regardless of the access specifier in the derived class */

/* ------------------------------------------------------------------------------------------------------------------------------------------------*/


/*In  general , 
If a function is done through dynamic binding or polymorphism,the access specifier in the base class is going to apply .
If the call is done through static binding , the access specifier of the derived class applies . */

/* ------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Guideline 
As a rule of thumb, except for the base class ,I mark all my other derived overrides as private , unless the specific problem i am solving requires otherwise. */

/* ------------------------------------------------------------------------------------------------------------------------------------------------*/

#include<iostream>
#include<memory>
using namespace std ;

class base 
{
    public:
    virtual void draw() const
    {
        cout<<"base draw is called "<<endl;
        
    }
    
    private:
    virtual void func() const
    {
        cout<<"base func is called"<<endl; 
    }
};

class derived : public base 
{
    public:
    void func() const override
    {
        cout<<"derived func is called"<<endl; 
    }
    
    private:
     void draw() const override
    {
        cout<<"derived draw is called "<<endl;
        
    }
    
};
 
int main()
{
    //Accessing stuff through the base class pointer
    shared_ptr<base> obj1 = make_shared<derived>();
    obj1->draw();
   //obj1->func(); // Error :  func is private in Shape
   

   cout<<"-------------------------------------------"<<endl;
     
   //Direct objects : static binding
   derived obj2;
   obj2.func();
   //obj2.draw();  //Error : draw() is private in derived.- Static binding

   cout<<"-------------------------------------------"<<endl;
  
  //Raw derived object assigned to raw base object
  //Slicing will occur, Base::draw will be called
   base obj3 = derived();
   obj3.draw();
  // obj3.func(); // Error : func is private in base
} 


/* OUTPUT


derived draw is called 
-------------------------------------------
derived func is called
-------------------------------------------
base draw is called 

*/