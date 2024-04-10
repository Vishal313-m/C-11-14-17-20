/*
IMPLICIT CONVERSION WITH OVERRIDEN BINARY OPERATOR 
-
If you want to support implicit conversion for your binary operator , you should do them as non-member free standing global function as we are doing the minus ,
multiplication, division  , and modulus operator , this is going to give you Implicit conversion , but if you do that as a member function , implicit conversion 
are not going to kick in for the first operand in lines of code  (like we have (2+ n1)), So if we want the line here to work and use implicit conversion for the
first operand , we have no choice but do that as a member function 


*/

/*
 # IMPORTANT NOTE #
   --->>   When a  binary operator is implemented as a member function , the left operand is never implicity converted 

    // as member function 
   std::cout<<(5+number1); // compiler error 
   The plus operator is done as member function of the number class ,so the implicit conversion is not going to work because the compiler is to call this operator 
   on the first operand and the first operand is just a number and the compiler doesn't know which class to implicitly convert to this two 
*/
#include <iostream>

class Number
{
    friend std::ostream& operator<<(std::ostream& out , const Number& number);

    //Arithmetic operators
    friend Number operator+(const Number& left_operand, const Number& right_operand);
    friend Number operator-(const Number& left_operand, const Number& right_operand);
    friend Number operator*(const Number& left_operand, const Number& right_operand);
    friend Number operator/(const Number& left_operand, const Number& right_operand);
    friend Number operator%(const Number& left_operand, const Number& right_operand);
		
public:
	Number() = default;
	Number(int value );


    explicit operator double()const{
        return (static_cast <double> (m_wrapped_int));
    }

    /*
    //Implicit conversions won't work for the first operand
    Number operator+(const Number& right) const{
        return Number(m_wrapped_int + right.m_wrapped_int);
    }
    */
 
    //getter
    int get_wrapped_int() const{
        return m_wrapped_int;
    }
     
    ~Number();
    
private : 
    int m_wrapped_int{0};
};



Number::Number(int value) : m_wrapped_int(value)
{
}

std::ostream& operator<<(std::ostream& out , const Number& number){
    out << "Number : [" << number.m_wrapped_int << "]";
    return out;
}



Number operator+(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);    
}

Number operator-(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);    
}
Number operator*(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);    
}
Number operator/(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);    
}
Number operator%(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);    
    
}

Number::~Number()
{
}


int main(){

    Number n1(22);
    std::cout << "n1 : " << n1 << std::endl;
    std::cout << "n1 + 2  : " << (n1 + 2) << std::endl;
    std::cout << "2 + n1 : " << (2 + n1) << std::endl; // now it is going to work  beacuse now the plus operator is done as a non member free standing global function

    std::cout << "42 - n1 : " << (42 - n1) << std::endl;
   

    return 0;
}

/*
OUTPUT
 22
 24
 24
 20
*/
