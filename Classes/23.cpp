// Constructor Delegation

/*
Constructor delegation in C++ refers to the ability of a constructor to call another constructor within the same class. 
This feature was introduced in C++11 and is a powerful tool for reducing code redundancy and improving code efficiency. 
By using constructor delegation, a constructor can transfer the responsibility of initialization to another constructor in the same class,
 thereby streamlining the code and avoiding duplication.
It is going to delegate the work to build the object to another constructor.


 BEnefits =----------------------------


 Centralized initialization logic: Constructor delegation enables you to centralize common initialization logic in one primary constructor.
  Other constructors can then delegate to this primary constructor, ensuring that the initialization is performed consistently across all constructors


  delegate meaning - to give a particular job, duty, right, etc. to someone else so that they do it for you
  */



/*
EVENT SEQUENCE


-- The One parameter constructor is called 
 BEfore we get into the body of the one param constructor ,the compiler realizes the delegation and calls the three param 
 constructor to do actual object creation with provided data 


- The three param constructor constructs the object and initializes with the provided data . Notice that the actual object
  is constructed by the three  param constructor 

  - control reaches the body of the three param constructor 

  - Control reaches the body of the single param constructor 

  - control goes back in main '

  - ALL THESE CALLS TO CONSTRUCTORS CAN BE SEEN IN THE CALL STACK WITH THE DEBUGGER 


*/





/*

Q - wHAT IF YOU CALL THE THREE PARAM CONSTRUCTOR YOURSELF

// Delegate object construction to other constructor 

Square::Square(double side_param)
{
    std::cout<<"Body of the square constructor with single param" << std::endl;
    Square(side_param , "red", 3);  // Doesn't do what you expect .BAD!
}

Square::Square(double side_param , std::string color_param , int shading_param) :
  
                            side{side_param}, color{color_param} , shading(shading_param)

  {
    std::cout<<"Body of Square Constructor with multiple params " << std::endl;
  }                          



Okay, some of you might be asking, okay, constructor delegation is good and we have seen that we could use initializer list to do that.

But what if I call the three parameter constructor myself like I do here? Well, I hate to break this to you, but this is not going to do what you want.

This is not going to do constructor delegation. This is just going to create a local object of square and it is going to be thrown away when the body
of this function finishes executing. So if you really want to do constructor. Delegation initializer lists are your only bet.

*/



/*

// No further initialization before / after delegation call

//Can't do further initialization after delegated cALL.

Square::Square(double side_param) : Square(side_param,"red", 3) , position(0.0)  // Compiler error 
{
    std::cout<<"Body of the square constructor with single param" << std::endl;
}


*/



#ifndef SQUARE_H
#define SQUARE_H

#include <string>

class Square
{
public:
	 explicit Square(double side_param);
     Square( double side_param, const std::string& color_param, int shading_param);
	 ~Square();
    double surface() const;
    
private :
    double m_side;
    std::string m_color;
    int m_shading;
    double m_position;
};

#endif // SQUARE_





#include "square.h"
#include <iostream>

Square::Square(double side_param )
     : Square{side_param,"black",6}
{
    m_position = 45.8;
    std::cout << "One param constructor called" << std::endl;
}

Square::Square( double side_param, const std::string& color_param, int shading_param )
    : m_side{side_param},m_color{color_param},m_shading{shading_param}
{
    std::cout <<  "Three param constructor called" << std::endl;
}

double Square::surface() const {
    return m_side*m_side;
}

Square::~Square()
{
    std::cout << "Square object destroyed"  << std::endl;
}





#include <iostream>
#include "square.h"

int main(){

    Square s1(100.0);


    return 0;
}

