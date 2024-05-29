// MOVE CONSTRUCTOR 

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point
{
private : 
	double* x{};
	double* y{};
	
	void invalidate(){
		x = nullptr;
		y = nullptr;
	}
public:
	Point(double x_param, double y_param);
	~Point();
	
    //Copy constructor
	Point(const Point& source_point);

    //Move constructor
    Point( Point&& source_point);

	
	//Setters
	void set_x(double x){
		*(this->x) = x; // Dereference and assign
	}
	void set_y(double y){
		*(this->y) = y; // Dereference and assign
	}
	
	//Getters
	double * get_x()const{
		return x;
	}
	
	double * get_y()const{
		return y;
	}

	double * steal_x(){
		double * new_x = x;
		x = nullptr;
		return new_x;
	}
	
	double * steal_y(){
		double* new_y = y;
		y = nullptr;
		return new_y;
	}
	
	//Utilities
	void print_info()const{
			std::cout << "Point [ x : " << *x << ", y: " << (*y) << "]" << std::endl;
	}
};

#endif // POINT_H



#include "point.h"

Point::Point(double x_param, double y_param) 
	: x(new double(x_param)),
		y(new double(y_param))
{
    std::cout << "Point constructed  : " << this << std::endl;

}

//Copy constructor
Point::Point(const Point& source_point)
	: x(new double(*(source_point.get_x()))),
		y(new double(*(source_point.get_y())))
{
	std::cout << "Body of copy constructor" << std::endl;
}

//Move constructor
Point::Point( Point&& source_point)
	: x(source_point.steal_x()),
		y(source_point.steal_y())
{
    //source_point.invalidate();
	std::cout << "Body of move constructor" << std::endl;
}


Point::~Point()
{
	delete x;
	delete y;
}



#include <iostream>
#include "point.h"


int main(){
    //Point p1(10.4,15.6);
    //p1.print_info();

    //Create a copy from a temporary
    Point p3(std::move(Point(20.5,5.8)));
    p3.print_info();
   
    return 0;
}