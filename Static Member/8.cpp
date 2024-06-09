// MEMBER VARIABLES OF OTHER TYPES 

#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
	explicit Integer(int value);
	Integer()  = default;
	~Integer();
	
	int get_value () const{
		return inner_int;
	}
	
	void set_value(int new_val){
		inner_int = new_val;
	}
	
private : 
	int inner_int{0};
};

#endif // INTEGER_H

#include <iostream>
#include "integer.h"

Integer::Integer(int value) : inner_int(value)
{
	std::cout << "Constructor for Integer " << inner_int << " called" << std::endl;
}

Integer::~Integer()
{
}


------------------------------------------------------------------------

#ifndef POINT_H
#define POINT_H

#include <iostream>

#include "integer.h"

class Point
{
public : 
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

	// Members of other objects
	Integer i1{1};
	const Integer i2{2}; 
	static inline Integer i3{3};
	static inline const Integer i4{4};
	
	Integer* p_i5{nullptr};
	static Integer i6;
	static const Integer i7;
private:
	double m_x;
	double m_y;
    static size_t m_point_count;
 };



#endif // POINT_H



#include "point.h"
#include <iostream>
#include <cmath>

size_t Point::m_point_count {}; // Initialize static member of Point class to 0

Integer Point::i6 {6};
const Integer Point::i7 {7};


Point::Point(double x, double y)
	:	p_i5(new Integer(5)),
		m_x(x) , m_y(y) 
{
	std::cout << "Constructing Point [ m_x : " << m_x << ", m_y : " << m_y << "]" << std::endl;
    ++m_point_count;
}

Point::Point(double xy_coord) : Point(xy_coord,xy_coord) {
    std::cout << "Point single param constructor called" << std::endl;
}

Point:: Point() : Point(0.0,0.0){
     std::cout << "Point default constructor called" << std::endl; 
}

Point::Point(const Point& point) : m_x(point.m_x) {
    //Copy constructor
    std::cout << "Copy constructor called" << std::endl;
    ++m_point_count; // Creating a copy object. So we increment
}

Point::~Point(){
    //Destructor
    std::cout << "Destroying point object. ";
    //We destroy a point object , so we decrement
    --m_point_count;
	
    std::cout << " Current point count : " << m_point_count << std::endl;
}

double Point::length() const{
    // Function to calculate distance from the point(0,0)
    return sqrt(pow(m_x - 0.0, 2) +  pow(m_y - 0.0, 2)); 
}


------------------------------

#include <iostream>
#include "point.h"

int main(){

	std::cout << std::endl;
	std::cout << "Entering main: " << std::endl;
	
	Point point1(3.0,3.0);
	std::cout << "distance : " << point1.length() << std::endl;
	
	std::cout << std::endl;
	std::cout << "Reading in the integers " << std::endl;
	
	std::cout << "point1.i1 : " << point1.i1.get_value() << std::endl;
	std::cout << "point1.i2 : " << point1.i2.get_value() << std::endl;
	std::cout << "Point::i3 : " << Point::i3.get_value() << std::endl;
	std::cout << "Point::i4 : " << Point::i4.get_value() << std::endl;

	
	//point1.i1.set_value(8);// Works, i1 is not const
	//point1.i2.set_value(10); // Compiler error, i2 is const, can't modify it.
	
	std::cout << "point1.p_i5 (pointer) : " << point1.p_i5->get_value() << std::endl;
	
	std::cout << "Point::i6 : " << Point::i6.get_value() << std::endl;
	std::cout << "Point::i7 : " << Point::i7.get_value() << std::endl;
	
	//Point::i6.set_value(50);
	//Point::i7.set_value(60); // Compiler error : i6 is const.
	
	std::cout << std::endl;
	std::cout << "Leaving main" << std::endl;
 
    return 0;
}