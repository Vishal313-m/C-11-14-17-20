Explain member variable of self type in class in cpp


In C++, a class cannot have a non-static member variable of its own type (self type). This is because the size of the class would be undefined,
 as the compiler needs to know the size of the class to allocate memory for objects of that class. 
However, there are a few ways to work around this limitation:

Static member variable of self type: A class can have a static member variable of its own type. 
Since static variables do not contribute to the size of objects, the compiler can calculate the size of the class without any issues.

class Test {
    static Test self; // works fine
    // other members
};


Pointer to self type: A class can have a pointer to its own type as a member variable.
 Pointers have a fixed size regardless of the type they point to, so the compiler can determine the size of the class

 class Test {
    Test* self; // works fine
    // other members
};


Using typedef or using alias: You can use a typedef or using alias to create a type alias for the class itself.
 This allows you to use the alias as the type for a member variable.

 struct Foo {
    typedef Foo self;
    // other members
};


Using decltype with this: While not directly possible, you can use decltype with the this pointer to get the type of the class. 
However, this can only be used within a member function, not in the class definition itself. 

struct Foo {
    void bar() {
        typedef decltype(*this) self;
        // use self within the member function
    }
    // other members
};

/*In summary, while a class cannot have a non-static member variable of its own type, you can work around this by using static member variables, pointers, 
type aliases, or decltype within member functions. The key limitation is that the size of the class must be known to the compiler when defining member variables.*/



#ifndef POINT_H
#define POINT_H

#include <iostream> // Included just to get access to size_t

class Point
{
public:
  //Constructors
  Point(double x, double y);
  Point(double xy_coord);       // Point Constructor
  Point();                  // Default constructor
  Point(const Point& point);    // Point Copy Constructor
  ~Point();                     // Point Destructor
  double length() const;   // Function to calculate distance from the point(0,0)
  
  size_t get_point_count() const{
	 return m_point_count;
  }

  void initialize_pointer(double x, double  y){
	  p_m_point4 = new Point(x,y);
  }

  void print_info()const{
    std::cout << "Point  [ m_x : " << m_x << ", m_y : " << m_y << "]" << std::endl;
  }

public : 
  //Point m_point1; // Incomplete type compiler error
  //const Point m_point2; //Incomplete type compiler error
  //static inline const Point m_point3{}; // Incomplete type compiler error

  Point* p_m_point4; // Works

  static const Point m_point4;
  static Point m_point5;

  
private:
  double m_x;
  double m_y;
  inline static size_t m_point_count {}; // C++17
};
#endif // POINT_H


 #include "point.h"
  #include <cmath>

const Point Point::m_point4 {4,5};
Point Point::m_point5 {3,8};

  Point::Point(double x, double y) :p_m_point4{nullptr}, m_x{x},m_y{y}{
    std::cout << "Point constructor called" << std::endl;
    ++m_point_count;
  }

    // Point Constructor
  Point::Point(double xy_coord) : Point(xy_coord,xy_coord){
  }  
 // Default constructor 
  Point::Point() :Point(0.0,0.0){

  }
  // Point Copy Constructor
  Point::Point(const Point& point) : Point{point.m_x,point.m_y}{

  }
// Point Destructor
  Point::~Point(){
    --m_point_count;
  }
  // Function to calculate distance from the point(0,0)
 double  Point::length() const{
  return sqrt(pow(m_x - 0, 2) +  pow(m_y - 0, 2) * 1.0); 
  }


  #include <iostream>
#include "point.h"

int main(){

    Point p1(5,5); // The most vexing parse
    p1.initialize_pointer(10,10);

    p1.m_point4.print_info();



 
    return 0;
}