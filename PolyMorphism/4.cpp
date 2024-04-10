/*OBJECT SLICING*/
/* When a derived class object is assigned to a base class object in C++, the derived class object’s extra attributes are sliced off (not considered) 
to generate the base class object; and this whole process is termed object slicing.*

-- 
In C++, object slicing occurs when you assign a derived class object to a base class object, resulting in the loss of derived class-specific information.

*/

#include <iostream>
#include <string>

class Base {
public:
    Base(int id) : id(id) {}
    virtual void display() const {
        std::cout << "Base ID: " << id << std::endl;
    }
protected:
    int id;
};

class Derived : public Base {
public:
    Derived(int id, const std::string& name) : Base(id), name(name) {}
    void display() const override {
        std::cout << "Derived ID: " << id << ", Name: " << name << std::endl;
    }
private:
    std::string name;
};

int main() {
    Derived derivedObj(1, "Derived Object");
    Base baseObj = derivedObj; // Object Slicing: Derived object sliced to Base object

    // Display the objects
    std::cout << "Original Derived Object:" << std::endl;
    derivedObj.display();

    std::cout << "\nSliced Base Object:" << std::endl;
    baseObj.display(); // Only the Base part is displayed

    return 0;
}


/*

Original Derived Object:
Derived ID: 1, Name: Derived Object

Sliced Base Object:
Base ID: 1


*/