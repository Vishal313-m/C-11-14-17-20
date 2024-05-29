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
