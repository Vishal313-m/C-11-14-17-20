// Structured Binding 


/*Answer
Structured bindings in C++17 allow you to declare multiple variables initialized from a tuple or struct in a concise way

 Here are the key points about structured bindings:
The syntax is auto [identifier-list] = expression;

The identifiers in the list are bound to the elements of the initializer expression

The initializer expression can be a tuple, array, or class type with accessible non-static data members

The type of each identifier is deduced from the initializer expression

Structured bindings work with auto - you cannot use a specific type instead of auto*/


#include <iostream>

struct Point {
    double x;
    double y;
};

int main() {
    Point p = {1.0, 2.0}; // Creating a Point object

    auto [x, y] = p; // Structured binding to unpack Point p into variables x and y

    std::cout << "X coordinate: " << x << std::endl;
    std::cout << "Y coordinate: " << y << std::endl;

    return 0;
}




/*----------------------------------------------------------------------*/

#include <iostream>


class Point
{
public : 
    double x;
    double y;
};

void print_point(const Point p){
    std::cout << "Point [ x : " << p.x << ", y : " << p.y << "]" << std::endl;
}


int main(){

    Point point1;

    point1.x = 5;
    point1.y = 6;

    print_point(point1);
 
     // a and b are just copies 
    auto [a,b] = point1;

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    point1.x = 44.1;  // changing x and Y won't change a and b because they are copies 
    point1.y = 55.2;  

    print_point(point1);

    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;

    auto func = [=](){
        std::cout << "a (captured) : " << a << std::endl;
        std::cout << "b (captured) : " << b << std::endl;
    };
    func();

    
    return 0;





    /*
    OUTPUT 


Point [ x : 5, y : 6]
a : 5
b : 6
Point [ x : 44.1, y : 55.2]
a : 5
b : 6
a (captured) : 5
b (captured) : 6
  */
}