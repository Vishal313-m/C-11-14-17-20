// Copy Constructor 

#include<iostream>


class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	
public:
	Point() = default;
	Point(double x, double y, int data) : 
		m_x(x), m_y(y),p_data(new int(data)){
	}
	Point(const Point& p); // Copy constructor

	void set_data (int data) {
		*p_data = data;
	}
	~Point() {
		delete p_data;
	}

private: 
	double length() const;   // Function to calculate distance from the point(0,0)

private : 
	double m_x{}; 
	double m_y{}; 
	int * p_data;
};


inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y 
		<< " data : " << *(p.p_data) << "]";	
	return os;
}

/*
  IN CPP FILE
Point::Point(const Point &p)
{
    std::cout << "Copy constructor called to copy point " << p << std::endl;
    if(this != &p){
		delete p_data;
		p_data = new int(*(p.p_data));
        m_x = p.m_x;
        m_y = p.m_y;
    }
}

*/
int main()
{
Point p3(30,30,30);
   Point p4 = p3;

   std::cout << "p3 : " << p3 << std::endl;
   std::cout << "p4 : " << p4 << std::endl;

   p3.set_data(77);

   std::cout << "-----" << std::endl;
   std::cout << "p3 : " << p3 << std::endl;
   std::cout << "p4 : " << p4 << std::endl;


   std::cout << "Done!" << std::endl;
}

/*
Copy constructor called to copy point Point [ x : 30, y : 30 data : 30]
p3 : Point [ x : 30, y : 30 data : 30]
p4 : Point [ x : 30, y : 30 data : 30]
-----
p3 : Point [ x : 30, y : 30 data : 77]
p4 : Point [ x : 30, y : 30 data : 30]
Done!

*/