// Addition Operator as Non Member 

#include<iostream>
using namespace std ;

class Point 
{
    friend Point operator+(const Point& left , const Point&right);
   
private :
       int x;
       int y;

public:
       Point(int x, int y): x(x), y(y) {}
     void print()
     {
        cout<<x<<endl;
        cout<<y<<endl;
     }
};

 inline Point operator+(const Point& left , const Point&right)
    {
        Point p(left.x+ right.x, left.y + right.y); // Initialize p with the sum of coordinates
        return p;
    }


int main() 
{
    Point p1(10,10);
    Point p2(20,20);
    Point p3{p1+p2};
    p3.print();
    Point p4{p2 +Point(5,5)};
}