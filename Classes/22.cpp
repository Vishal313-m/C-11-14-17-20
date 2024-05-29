// Explicit Constructor 


#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
public:
	 explicit Square(double side_param , const std::string& color_param = "black");
	 ~Square();
    double surface() const;
    
private :
    double m_side;
    std::string m_color;
};

#endif // SQUARE_H


#include "square.h"

Square::Square(double side_param , const std::string& color_param)
     : m_side{side_param},
        m_color{color_param}
{
}

double Square::surface() const {
    return m_side*m_side;
}

Square::~Square()
{
}


#include <iostream>
#include "square.h"

//Is square1 > to square2 ? true or false
bool compare( const Square& square1 ,const Square& square2){
    return (square1.surface() > square2.surface()) ? true : false;
}

int main(){

    Square s1(100.0);
    Square s2(20.0);

    std::cout << std::boolalpha;
    std::cout << "s1 > s2 : " << compare(s1,s2) << std::endl; 

    //Implicit conversions
    std::cout << "s1 > 45.9 : " << compare(s1,45.9) << std::endl; // Compiler error 


   
    return 0;
}