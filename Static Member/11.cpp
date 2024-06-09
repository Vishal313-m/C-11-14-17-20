// In CLASS MEMBER VARIABLE Initialization 


#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
	explicit Integer(int value);
	Integer(){
		std::cout << "Default constructor for Integer called" << std::endl;
	}
	~Integer();
	
	int get_value () const{
		return inner_int;
	}
	
	void set_value(int new_val){
		inner_int = new_val;
	}
	
private : 
	int inner_int{};

};

#endif // INTEGER_H


#include "integer.h"

Integer::Integer(int value) : inner_int(value)
{
	std::cout << "Constructor for Integer " << inner_int << " called" << std::endl;
}

Integer::~Integer()
{
}



#include <iostream>
#include "integer.h"

class Point{
public : 
    Point() {

    }
    Point(double x , double y) : m_x{x} , m_y{y}{
    };

 private :
    /*
    //No initialization at all  -- JUNK DATA 
    double m_x;
    double m_y;
    */

    //Explicit assignment
    /* 
    double m_x = 0.1;
    double m_y = 0.1;
    */

   //Braced initializers
   double m_x{0.1};
   double m_y{0.1};

   //
   Integer i{}; // Default constructo the object

};



int main(){

    Point p1;
   
    return 0;
}