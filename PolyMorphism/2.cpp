// DYNAMIC BINDING 
/*
Compiler does not look  the type of pointer
It is going to look at the type of the actual object that the pointer is managing.
*/

#include<iostream>
using namespace std;

class Shape
{ 
    
    public:
  virtual  void draw()
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

    //Base pointers
    Shape * shape_ptr = &shape1;
    shape_ptr->draw();

    shape_ptr = &oval1;
    shape_ptr->draw(); // Draw an oval

    shape_ptr = &circle1;
    shape_ptr->draw();
}

/*
OUTPUT

SHAPE is called
OVAL is called
CIRCLE is called


*/