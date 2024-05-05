https://www.geeksforgeeks.org/operators-in-cpp/

Types of C++ Relational Operators
We have six relational operators in C++ which are explained below with examples.

Relational Operator             Meaning

>                           Greater than

<                           Less than

>=                         Greater than equal to

<=                         Less than equal to

==                           Equal to

!=                         Not equal to



Name	     Symbol	                            Description                                           	Example
Logical AND	  &&	        Returns true only if all the operands are true or non-zero	             int a = 3, b = 6; a&&b; // returns true

Logical OR	||	            Returns true if either of the operands is true or non-zero	                         int a = 3, b = 6; a||b; // returns true

Logical NOT	!	                   Returns true if the operand is false or zero	                            int a = 3; !a; // returns false



include <iostream>


int main(){
   
    int number1 {20};
    int number2 {20};
	
    std::cout << "number1 : " << number1 << std::endl;
    std::cout << "number2 : " << number2 << std::endl;
	
	std::cout << std::endl;
	std::cout << "Comparing variables" << std::endl;
	
    std::cout << std::boolalpha ; // Make bool show up as true/false instead of 1/0
	//Stress the need for parentheses here
    std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
	std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number2 : " << (number1 >= number2) << std::endl;
    std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
    std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;

	std::cout << std::endl;
	std::cout << "store comparison result and use it later" << std::endl;
	
	bool result = (number1 == number2);
    
    std::cout <<  number1 << " == " << number2 << " : " << result <<  std::endl;

    return 0;
}







#include <iostream>



int main(){

	bool a {true};
    bool b {false};
    bool c {true};
	
	std::cout << std::boolalpha; // true / false
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "c : " << c << std::endl;

	
	//AND : Evaluates to true when all operands are true.
	//      A single false operand will drag 
    //      the entire expression to evaluating false.
	
	std::cout << std::endl;
	std::cout << "Basic AND operations" << std::endl;

    std::cout << " a && b : " << (a && b) << std::endl; // false
    std::cout << " a && c : " << (a && c ) << std::endl; // true
    std::cout << " a && b && c :" << (a && b && c) << std::endl; // false


	//OR : Evaluates to true when at least one operand true.
	//      A single true operand will push 
    //      the entire expression to evaluating true.
	std::cout << std::endl;
	std::cout << "Basic OR operations" << std::endl;
    std::cout << " a || b : " << (a || b) << std::endl;
    std::cout << " a || c : " << (a || c ) << std::endl;
    std::cout << " a ||b || c :" << (a || b || c) << std::endl;


	//NOT : Negates whateve operand you put it with
	std::cout << std::endl;
	std::cout << "Basic NOT operations" << std::endl;	
	
	std::cout << "!a : " << !a << std::endl;
	std::cout << "!b : " << !b << std::endl;
	std::cout << "!c : " << !c << std::endl;



	//Combinations of all these operators
	std::cout << std::endl;
	std::cout << "Combining logical operators" << std::endl;
	// !(a &&b) || c
	std::cout << "!(a &&b) || c : " << (!(a &&b) || c) << std::endl; // true


    //Combining logical operators with relational operators
	int d{45};
	int e{20};
	int f{11};
	
	std::cout << std::endl;
	std::cout << "Relational and logic operations on integers" << std::endl;
	std::cout << "d : " << d << std::endl;
	std::cout << "e : " << e << std::endl;
	std::cout << "f : " << f << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "(d > e) && (d > f) : " << ((d > e) && (d > f)) << std::endl; // true
	std::cout << "(d==e) || (e <= f ) : " << ((d==e) || (e <= f ) ) << std::endl;
	std::cout << "(d < e) || (d > f) : " << ((d < e) || (d > f)) << std::endl;
	std::cout << "(f > e) || (d < f) : " << ((f > e) || (d < f)) << std::endl;
	std::cout << "(d > f) && (f <= d) : " << ((d > f) && (f <= d)) << std::endl;
	std::cout << "(d > e) && (d <= f) : " << ((d > e) && (d <= f)) << std::endl;
	std::cout << "(! a) && (d == e) : " << ((! a) && (d == e)) << std::endl;
	std::cout << "(! a) && (d == e) : " << ((! a) && (d == e)) << std::endl;
   
    return 0;
}