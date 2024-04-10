/* ABSTRACT CLASSES AS INTERFACES */

/* An abstract Class with only pure virtual functions and no member variable can be used to model what is called an interface in object Oriented Programming   */
/* An Interface is a specification of something that will be fully implemented in a derived class , but the specification itself resides in the abstract class */

/*Abstract classes and interfaces in C++ serve as mechanisms for defining contracts and achieving abstraction,
 but they have distinct characteristics and usage scenarios. While abstract classes can contain both implemented and 
 unimplemented member functions and have member variables, interfaces only contain pure virtual functions and no member variables
. In C++, an abstract class is a class that cannot be instantiated on its own and must have at least one pure virtual function,
 while an interface is a class-like structure that contains only pure virtual functions and no member variables

Abstract classes are useful for creating hierarchies, providing common implementations,
 and defining shared member variables or common functionality among derived classes. On the other hand,
 interfaces are beneficial for defining contracts of behaviors that multiple unrelated classes can implement and achieving multiple inheritances with different base classes

. Abstract classes support single inheritance, meaning a derived class can only inherit from one abstract class, 
while interfaces support multiple inheritance, allowing a class to inherit from multiple interfaces

*/

#include <iostream>

// Abstract interface class
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double calculateArea() const = 0;
    
    // Virtual destructor (to allow proper destruction of derived classes)
    virtual ~Shape() {}
};

// Concrete class implementing the Shape interface
class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    // Implementing the pure virtual function
    double calculateArea() const override {
        return width * height;
    }
};

// Another concrete class implementing the Shape interface
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    // Implementing the pure virtual function
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Creating instances of concrete classes
    Rectangle rect(3, 4);
    Circle circle(5);
    
    // Using the interface to access the calculateArea function
    std::cout << "Area of Rectangle: " << rect.calculateArea() << std::endl;
    std::cout << "Area of Circle: " << circle.calculateArea() << std::endl;
    
    return 0;
}


/*
OUTPUT

Area of Rectangle: 12
Area of Circle: 78.5




*/