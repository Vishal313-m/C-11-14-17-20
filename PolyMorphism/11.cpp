/*  Non Polymorphic Functions and Access specifiers */

/*  If you don't use virtual function , you are going to get static binding  results , even if you go through a base pointer or base reference */

#include<iostream>
#include<memory>
using namespace std;

class base
{
    public:
    void draw()
    {
        cout<<"base draw is called"<<endl;
    }
    
    private:
    
    void  func()
    {
        cout<<"base func is called"<<endl;
    }
    
};

class derived : public base
{
     
     public:
     
     void func() 
     { 
       cout<<"derived func is called"<<endl;      
     }
     
     private:
     
     void draw()
     {
         cout<<"derived draw is called "<<endl;
     }
};

int main()
{
   //Accessing stuff through the base class pointer
    shared_ptr<base> obj1 = make_shared<derived>();
    obj1->draw(); // Static Binding
   //obj1->func(); // Error :  func is private in base
   

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

/*
OUTPUT

base draw is called
-------------------------------------------
derived func is called
-------------------------------------------
base draw is called


*/