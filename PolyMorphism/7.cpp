/*Inheritance and PolyMorphism with static Member */


/*In C++, when dealing with inheritance and polymorphism involving static members, there are certain considerations to keep in mind. 
Static members in C++ are not associated with objects but with the class itself. This means that all objects of a class share the same static member. 
In the context of inheritance, derived classes inherit static members from their base classes, and they can access and modify these static members. 
However, each class, including the base and derived classes, has its own copy of the static member.
 Therefore, re-initializing a static member in a derived class will not affect the static member in the base class or other derived classes. 
This behavior allows each class to have its unique value for the static member
*/

#include<iostream>
using namespace std;

class shape 
{
   public:
    static int count ;
     shape()
     {
         ++count;
     }
      
    
};
int shape::count = 0; 

class circle :  public shape 
{
  
  public:
  static int count ;
    circle()
    {
        ++count;
    }
};

int circle::count = 0; 
int main()
{
    shape obj1 ;
    shape obj2;
    shape obj3;
    cout<<shape::count<<endl;
    circle c1;
     cout<<shape::count<<endl;
    
    cout<<"--------------------------------"<<endl;
    cout<<circle::count<<endl;
    
}

/*
OUTPUT 

3
4   - we have total 4 shapes
-----------------------------
1  - and One circle 



*/