/* SIZE OF POLYMORPHIC OBJECT  WITHOUT VIRTUAL FUNCTION */

#include<iostream>
using namespace std;

class Shape
{ 

    public:
    void draw()
    {
        cout<<"SHAPE is called"<<endl;
    }
};

class Oval : public Shape 
{
    public:
 void draw()
    {
        cout<<"OVAL is called"<<endl;
    }
};

class Circle : public Oval
{
    public:
   void draw()
    {
        cout<<"CIRCLE is called"<<endl;
    }
};

int main()
{
  Shape shape1;
   Oval oval1;
   Circle circle1;
    cout<<sizeof(shape1)<<endl;
    cout<<sizeof(oval1)<<endl;
    cout<<sizeof(circle1)<<endl; 
    
}

/*
OUTPUT 
1
1
1
When dealing with an empty class in C++, the size is generally 1 byte 

*/

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#include<iostream>
using namespace std;

class Shape
{ 
    int num =0;
    int num2= 7;
    public:
    void draw()
    {
        cout<<"SHAPE is called"<<endl;
    }
};

class Oval : public Shape 
{
    public:
 void draw()
    {
        cout<<"OVAL is called"<<endl;
    }
};

class Circle : public Oval
{
    public:
   void draw()
    {
        cout<<"CIRCLE is called"<<endl;
    }
};

int main()
{
  Shape shape1;
   Oval oval1;
   Circle circle1;
   cout<<sizeof(shape1)<<endl;
    cout<<sizeof(oval1)<<endl;
  cout<<sizeof(circle1)<<endl;
      
}

/*

OUTPUT
8
8
8
*/

/*################################################################################################################################################################*/

/*SIZE OF OBJECT WITH VIRTUAL FUNCTION   --  DYNAMIC POLYMORPHISM*/

#include<iostream>
using namespace std;

class Shape
{ 
    int num =0;
    int num2= 7;
    public:
    virtual void draw()
    {
        cout<<"SHAPE is called"<<endl;
    }
};

class Oval : public Shape 
{
    public:
 void draw()
    {
        cout<<"OVAL is called"<<endl;
    }
};

class Circle : public Oval
{
    public:
   void draw()
    {
        cout<<"CIRCLE is called"<<endl;
    }
};

int main()
{
  Shape shape1;
   Oval oval1;
   Circle circle1;
    cout<<sizeof(shape1)<<endl;
    cout<<sizeof(oval1)<<endl;
    cout<<sizeof(circle1)<<endl;
       
}


/*
OUTPUT
16
16
16



And hopefully you can see that with dynamic polymorphism, our objects are going to be much larger because
the compiler has to keep track of the information that allows it to dynamically resolve virtual functionc alls.

That's why our objects are larger with polymorphism and you should note that you are not getting polymorphic results for free.

You are going to be paying in terms of much more memory that you use for your objects in your C++ programs.


*/