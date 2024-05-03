#include <iostream>

class MyObject {
public:
    // Constructor
    MyObject(int val) : data(new int(val)) {
        std::cout << "Constructor called. Value: " << *data << std::endl;
    }

    // Move Constructor
    MyObject(MyObject&& other) noexcept : data(other.data) {
        other.data = nullptr; // Nullify the source's data to avoid double deletion
        std::cout << "Move Constructor called. Value: " << *data << std::endl;
    }
 
    // Move Assignment Operator
    MyObject& operator=(MyObject&& other) noexcept { 
        if (this != &other) {
            delete data; // Release existing resources
            data = other.data; // Transfer ownership
            other.data = nullptr; // Nullify the source's data
            std::cout << "Move Assignment Operator called. Value: " << *data << std::endl;
        }
        return *this;
    }

    // Destructor
    ~MyObject() {
        if (data != nullptr) {
            std::cout << "Destructor called. Value: " << *data << std::endl;
            delete data;
        }
    }

private:
    int* data;
};

int main() {
    MyObject obj1(42); // Constructor called

    MyObject obj2 = std::move(obj1); // Move Constructor called
    // obj1 is now in a valid but unspecified state

    obj1 = MyObject(84); // Move Assignment Operator called
    // Temporary MyObject(84) is moved to obj1

    return 0;
}
