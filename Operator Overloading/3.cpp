// STREAM INSERTION OPERATOR

#include<iostream>
using namespace std;

class YoutubeChannel
{  
    friend  void operator << (ostream& COUT ,YoutubeChannel& ytchannel);
 private:
     string name;
    int subCount;
public:
    YoutubeChannel(string name , int subCount): name{name} , subCount{subCount}
    {

    }

   
 };
  void operator << (ostream& COUT ,YoutubeChannel& ytchannel)
    {
        COUT << "Name:" << ytchannel.name<<endl;
        COUT << "Subscriber:" << ytchannel.subCount<<endl;
    }
  
 int main()
 {
    YoutubeChannel y1("Nomad", 5000);
    cout<<y1;

 }

 //----------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Point
{
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
public:
	Point() = default;
	Point(double x, double y) : m_x(x), m_y(y)
    {
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

int main(){

    Point p1(10,20);
    Point p2(3,4);

    std::cout << p1 << p2 << std::endl;
   
    return 0;
}