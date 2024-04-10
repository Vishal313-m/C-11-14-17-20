/* PURE VIRTUAL FUNCTIONS AND ABSTRACT CLASS */

/* And what this is going to tell the compiler is these methods are not meant to be implemented in the base class.
They are meant to be overridden and implemented by inheriting classes. And another side effect of this is that the compiler is going to prevent you from creating objects of
this class because it really doesn't make sense to create an object of shape in your design.*/

/*
- If a Class has at least One Pure Virtual function , it becomes an abstract class 
- You can't create objects of an abstract class , if you do that , you'll get a hard compiler error 
- Derived classes from an abstract class must explicitly override all the pure  virtual functions from the abstract parent class , if they don't they themselves become abstract
- Pure Virtual Functions don't have an implementation in the abstract class.They are meant to be implemented by deriving classes
- You Can't call the pure virtual functions from the constructor of the abstract class 
- The Constructor of the abstract class is  used by deriving class to build up the base part of the  object.

*/

#include <iostream>
#include<typeinfo>
#include <string>

class Shape
{
protected:
    Shape() = default;
   Shape(std::string_view description) : m_description(description)
   {
	
   }
public :    
    
    virtual ~Shape() = default; // If destructor is not public, you won't be
                            // able to delete base_ptrs. SHOW THIS TO STUDENTS
    //Pure virtual functions
    virtual double perimeter() const = 0;
    virtual double surface() const = 0;
private : 
    std::string m_description;
};



class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(double width , double height,std::string_view  description) : Shape(description), m_width(width), m_height(height)
   {
   }
    virtual ~Rectangle() = default;
    
public:
    
    virtual double perimeter() const override{
        return (2*m_width + 2*m_height);
    }
	
	
    virtual double surface() const override{
        return (m_width * m_height);
    }
	
private : 
    double m_width{0.0};
    double m_height{0.0};

};


class Circle : public Shape
{
public:
    Circle() = default;
    Circle(double radius , std::string_view  description): Shape(description) , m_radius(radius)
    {
    }
    virtual ~Circle()= default;
    
    
    virtual double perimeter() const {
        return (2 * PI * m_radius);
    }

    virtual double surface() const {
        return PI * m_radius* m_radius;
    }

    
private: 
    double m_radius{0.0};
    
    inline static double PI{3.14159265};
};

int main(){
   
   //Shape * shape_ptr = new Shape; // Compiler error

    const Shape * shape_rect = new Rectangle(10,10,"rect1");
    double surface = shape_rect->surface();
    std::cout << "dynamic type of shape_rect : " << typeid(*shape_rect).name() << std::endl;
    std::cout << "The surface of shape rect is : " << surface << std::endl;


    std::cout << "--------------" << std::endl;

    const Shape * shape_circle = new Circle(10,"circle1");
    surface = shape_circle->surface();
    std::cout << "dynamic type of shape_circle : " << typeid(*shape_circle).name() << std::endl;
    std::cout << "The surface of the circle is : " << surface << std::endl;
    return 0;
}

/*
OUTPUT

dynamic type of shape_rect : 9Rectangle
The surface of shape rect is : 100
--------------
dynamic type of shape_circle : 6Circle
The surface of the circle is : 314.159




*/