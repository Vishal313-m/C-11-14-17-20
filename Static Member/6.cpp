PRE C++17 how we initialize static const variable

#ifndef CYLINDER_H
#define CYLINDER_H

#include <string>

class Cylinder {
public : 
    //int and enum can be initialized in class declaration
	static const int    INT_CONSTANT {5};
    enum Color{ Red = 0, Green, Blue };
    static const Color COLOR_CONSTANT{Color::Green} ;
	
	//Others have to be done in the cpp file.
	static const std::string default_color;
	static const char*  CHAR_PTR_CONSTANT;
    static const int    INT_ARRAY_CONSTANT[5];
    static const float  FLOAT_CONSTANT;
    static const std::string STRING_ARRAY_CONSTANT[2];
	
	//Not static
	const float WEIRD_FLOAT;
	const char * WEIRD_C_STRING;
	const int    WEIRD_INT_ARRAY_CONSTANT[5];
	
    //Constructors
    Cylinder()= default;
    Cylinder(double radius_param , double height_param );
	
    //Getters
    double get_base_radius();
    double get_height();
    
    //Setters
    void set_base_radius(double radius_param);
    void set_height(double height_param);
    
    //Other operations on the class object
    double volume();  
	
private :
    double base_radius{1.0};
    double height{1.0};
    static  const double PI ;
};
#endif // CYLINDER_H


#include "cylinder.h"

//std::string and double
const std::string Cylinder::default_color {"Red"};
const double Cylinder::PI {3.1415926535897932384626433832795};
const char*  Cylinder::CHAR_PTR_CONSTANT   = "CString here";
const int    Cylinder::INT_ARRAY_CONSTANT[] = {10,20,30,40,50};
const float  Cylinder::FLOAT_CONSTANT   = 6.98f;
const std::string Cylinder::STRING_ARRAY_CONSTANT[] = {"String1","String2"};



Cylinder::Cylinder(double radius_param , double height_param )
	: 	WEIRD_FLOAT{33.3},
		WEIRD_C_STRING{"Weird"},
		WEIRD_INT_ARRAY_CONSTANT{10,20,30,40,50}


{
	//WEIRD_FLOAT = 33.3;// Not allowed

    base_radius = radius_param;
    height = height_param;
}
    
//Getters
double Cylinder::get_base_radius(){
    return base_radius;
}
double Cylinder::get_height(){
   return height; 
}
    
//Setters
void Cylinder::set_base_radius(double radius_param){
    base_radius = radius_param;
}
void Cylinder::set_height(double height_param){
    height = height_param;
}
    
//Other operations on the class object
double Cylinder::volume(){
   return PI * base_radius * base_radius * height; 
}  
