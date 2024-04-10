// Custom type conversion
//Explicit Conversion
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
 explicit operator Point() const{
        std::cout << "Custom conversion from Number to Point" << std::endl;
        return Point(static_cast<double>(m_wrapped_int),
                        static_cast<double>(m_wrapped_int));
    }
 
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


double sum(double a, double b){
    return a + b;
}
void use_point(const Point& p){
    std::cout << "Printing the point from use_point func : " << p << std::endl;
}

int main(){

    Number n1(22);
    Number n2(10);
    
    double result = sum(static_cast<double>(n1),static_cast<double>(n2));
    std::cout << "result : " << result <<  std::endl;
    use_point(static_cast<Point>(n1));

    return 0;
}