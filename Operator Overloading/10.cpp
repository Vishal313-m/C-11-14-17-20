// COPY ASSIGNMENT OPERATOR 
/* Without Explicitly write Copy ASSIGNMENT OPERATOR or IF WE DON'T have ANY EXPLICIY COPY ASSIGNMENT OPERATOR */
#include <iostream>

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}

   ~Point() = default;

private : 
	double m_x{}; 
	double m_y{}; 
};



inline std::ostream& operator<<(std::ostream& os, const Point& p){
	os << "Point [ x : " << p.m_x << ", y : " << p.m_y <<"]";	
	return os;
}

int main()
{
    Point p1(10,10);
    Point p2(20,20);

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    std::cout << "-----" << std::endl;

    //Assignment
    p2=p1;

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

}

/*
OUTPUT
p1 : Point [ x : 10, y : 10]
p2 : Point [ x : 20, y : 20]
-----
p1 : Point [ x : 10, y : 10]
p2 : Point [ x : 10, y : 10]


This is going to be using the compiler generated copy assignment Operator.
If you only have non pointer member variables in your class, the compiler generated copy assignment operator is going to work just right.
You don't have to declare it in your class and this is really cool.
*/

/*
But this can be disastrous because if we have a pointer member variable and we happen to be dynamic memory allocation, this is going to blindly copy the pointers.
And after you do your copy, the two points are going to be pointing to the same data.
*/

//And let me show you what I mean here. So to show this, we can put in a pointer member variable.


#include <iostream>

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	
public:
	Point() = default;
	
    Point(double x, double y, int data) : 
		m_x(x), m_y(y),p_data(new int(data)){
	}
	
    void set_data (int data) {
		*p_data = data;
	}
	
    ~Point()= default;
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


int main()
{
    Point p1(10,10,10);
    Point p2(20,20,20);

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    std::cout << "-----" << std::endl;

    //Assignment
    p2=p1;

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

     //Change data
    p1.set_data(55);

    std::cout << "-----------" << std::endl;
    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

}

/*
p1 : Point [ x : 10, y : 10 data : 10]
p2 : Point [ x : 20, y : 20 data : 20]
-----
p1 : Point [ x : 10, y : 10 data : 10]
p2 : Point [ x : 10, y : 10 data : 10]
-----------
p1 : Point [ x : 10, y : 10 data : 55]
p2 : Point [ x : 10, y : 10 data : 55]
*/

/*
- we're going to print p1 and p2.Initially, this is going to be 10 and 20.
- After we do our assignment, we're going to have a 10 and 10 . And this is going to be good.This is what we expect.
  //shalow copy
- But after we change the data, we expect to only change the data for p1. So after we change the data, p1 is expected to be 55, but notice that p2 has also been changed
because what we have really done is blindly copy the member variables and we have also blindly copied the address in our pointer member variable.
*/

/*
Hopefully you can see the problem here, and this is the reason why you might want to do your own copy assignment operator to fix this problem and do a deep copy.
*/


//So we're going to fix this problem and we're going to set up our own copy assignment. Operator let's do this.

#include <iostream>

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	
public:
	Point() = default;
	
    Point(double x, double y, int data) : 
		m_x(x), m_y(y),p_data(new int(data)){
	}
	//copy assignment operator
	Point& operator= (const Point& right_operand){
		std::cout << "Copy assignment operator called" << std::endl;
		if(this != & right_operand){
			delete p_data;
			p_data = new int(*(right_operand.p_data));
			m_x =  right_operand.m_x;
			m_y = right_operand.m_y;
		}
		return *this;
	}

	void set_data (int data) {
		*p_data = data;
	}
	
    ~Point()= default;

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

int main()
{
    Point p1(10,10,10);
    Point p2(20,20,20);

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    std::cout << "-----" << std::endl;

    //Assignment
    p2=p1;

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

     //Change data
    p1.set_data(55);

    std::cout << "-----------" << std::endl;
    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

}

/*
OUTPUT

p1 : Point [ x : 10, y : 10 data : 10]
p2 : Point [ x : 20, y : 20 data : 20]
-----
Copy assignment operator called
p1 : Point [ x : 10, y : 10 data : 10]
p2 : Point [ x : 10, y : 10 data : 10]
-----------
p1 : Point [ x : 10, y : 10 data : 55]
p2 : Point [ x : 10, y : 10 data : 10]



*/