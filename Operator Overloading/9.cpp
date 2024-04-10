// Unary Postfix Increment Operator 
#include<iostream>

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	friend void operator++(Point& operand);
	
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}

    //Postfix
	Point operator++(int){                          /*  The int parameter is a dummy parameter to differentiate it from the prefix increment operator.*/
		Point local_point(*this);   /* Inside the function, a local copy of the current object is created using the copy constructor  and This local_point object will hold the current state of the Point object before it gets incremented.*/
		++(*this);                /*Then, it calls the prefix increment operator on the current object:*/
		return local_point;      /*Finally, it returns the local copy of the original object, which still holds the state before the increment operation.*/
	}                             
	

	~Point() = default;



private : 
	double m_x{}; 
	double m_y{}; 
};


inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";	
	return os;
}


int main(){

    Point p1(10,10);
    std::cout << "p1 : " << p1++ << std::endl; // (10,10);
    std::cout << "p1 : " << p1 << std::endl; // (11,11)
   
    return 0;
}