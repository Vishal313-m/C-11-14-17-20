// Static Binding 
/*Static binding ensures linking the function call and its function definition at compile-time only. */
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

    //Base pointers
    Shape * shape_ptr = &shape1;
    shape_ptr->draw();

    shape_ptr = &oval1;
    shape_ptr->draw(); // Draw an oval

    shape_ptr = &circle1;
    shape_ptr->draw();

    /*
      using references  - same behaviour compiler is going to look type of reference
       Shape& shape_ref = shape1;
       shape_ref.draw();

    */
}


/*
OUTPUT

SHAPE is called
SHAPE is called
SHAPE is called

Compiler is  going to look the type of pointer and use that to decide which method it is going to be calling in our Inheritance hierarchy  
*/