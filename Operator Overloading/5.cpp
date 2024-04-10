//  COMPOUND ASSIGNMENT OPERATOR 
#include<iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	friend Point operator+(const Point& left , const Point& right);
	friend Point operator-(const Point& left , const Point& right);
	friend Point& operator+=(Point& left, const Point& right);
	friend Point& operator-=(Point& left, const Point& right);
	
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}
	~Point() = default;

	void print_info(){
		std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
	}

private : 
	double m_x{}; 
	double m_y{}; 
};

inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y << "]";	
	return os;
}

inline Point& operator+=(Point& left, const Point& right){
	left.m_x += right.m_x;
	left.m_y += right.m_y;
	return left;
}

inline Point& operator-=(Point& left, const Point& right){
	left.m_x -= right.m_x;
	left.m_y -= right.m_y;
	return left;
}


inline Point operator+(const Point& left , const Point& right){
	Point p(left);
	return p+=right;
}

inline Point operator-(const Point& left , const Point& right){
	Point p(left);
	return p-=right;
}


int main(){


    Point p1(10,10);
    Point p2(20,20);
    Point p3(5,5);

    std::cout << "p1 + p2 : " << (p1 +  p2) << std::endl; // (30,30)
    std::cout << "p2 - p3 : " << (p2 - p3) << std::endl; // (15,15)

    std::cout << "------" << std::endl;

    p1+=p2;
    p2-=p3;
    
    std::cout << "point1 : " <<  p1 << std::endl; // (30,30)
    std::cout << "point2 : " << p2 << std::endl; // (15,15)

    return 0;
}