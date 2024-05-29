//SHALLOW COPY


/* - In a shallow copy, an object is created by simply copying the values of all member variables of the original object.

- If the object contains pointers or references to dynamically allocated memory, the shallow copy will also point to the same memory location.
Changes made to the copied object may affect the original object and vice versa.

- The default copy constructor and assignment operator in C++ perform shallow copies*/

class MyClass {
public:
    MyClass(int x) : x(x), p(new int(x)) {}
    MyClass(const MyClass& other) : x(other.x), p(other.p) {}
    
    int x;
    int* p;
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1; // Shallow copy using default copy constructor
    
    std::cout << "obj1: " << obj1.x << ", " << *obj1.p << std::endl;
    std::cout << "obj2: " << obj2.x << ", " << *obj2.p << std::endl;
    
    *obj1.p = 20;
    std::cout << "After modifying obj1.p:" << std::endl;
    std::cout << "obj1: " << obj1.x << ", " << *obj1.p << std::endl;
    std::cout << "obj2: " << obj2.x << ", " << *obj2.p << std::endl;
    
    return 0;
}


//DEEP COPY 


/*
In a deep copy, an object is created by allocating new memory for the copied object 
and copying the values of all member variables, including the values pointed to by pointers.

If the object contains pointers or references to dynamically allocated memory,
 the deep copy will allocate new memory and copy the values.


Changes made to the copied object will not affect the original object and vice versa.
To perform a deep copy, you need to explicitly define a copy constructor that allocates new memory and copies the values

*/


class MyClass {
public:
    MyClass(int x) : x(x), p(new int(x)) {}
    MyClass(const MyClass& other) : x(other.x), p(new int(*other.p)) {}
    ~MyClass() { delete p; }
    
    int x;
    int* p;
};

int main() {
    MyClass obj1(10);
    MyClass obj2(obj1); // Deep copy using custom copy constructor
    
    std::cout << "obj1: " << obj1.x << ", " << *obj1.p << std::endl;
    std::cout << "obj2: " << obj2.x << ", " << *obj2.p << std::endl;
    
    *obj1.p = 20;
    std::cout << "After modifying obj1.p:" << std::endl;
    std::cout << "obj1: " << obj1.x << ", " << *obj1.p << std::endl;
    std::cout << "obj2: " << obj2.x << ", " << *obj2.p << std::endl;
    
    return 0;
}