//subscript operator reading  
#include <iostream>
#include <cassert>

class Point
{
public:
	Point() = default;
	Point(double x, double y) : 
		m_x(x), m_y(y){
	}
	~Point() = default;

	double operator[](size_t index) const{
		assert( (index == 0) || (index == 1));
		if(index == 0){
			return m_x;
		}else{
			return m_y;
		}
	}

	void print_info(){
		std::cout << "Point [ x : " << m_x << ", y : " << m_y << "]" << std::endl;
	}

private : 
	double m_x{}; // 0
	double m_y{}; // 1
};
int main(){

    Point p1(10,20);

    //std::cout << "p1.x : " << p1[0] << std::endl; // x coordinate : 10
    std::cout << "p1.x : " << p1.operator[](0) << std::endl; // x coordinate : 10
    std::cout << "p1.y : " << p1[1] << std::endl; // y coordinate : 20
    return 0;
}