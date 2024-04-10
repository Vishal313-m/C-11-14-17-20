//Additon Operator as Member


#include<iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y): x(x), y(y) {}
    
    Point operator+(const Point& rhs)
    {
        Point p(x + rhs.x, y + rhs.y); // Initialize p with the sum of coordinates
        return p;
    }

    void print()
    {
        cout << x << endl;
        cout << y << endl;
    }
};

int main()
{
    Point p1(3, 2);
    Point p2(4, 5);
    Point p3 = p1 + p2;
     Point p4{p2 + Point(5,5)};
    p4.print(); // This will print the coordinates of the resulting point.
    
    return 0;
}
