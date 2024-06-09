 --- Static member function 

Static Member Function in C++
Static Member Function in a class is the function that is declared as static because of which function attains certain properties as defined below:

A static member function is independent of any object of the class. 
A static member function can be called even if no objects of the class exist.
A static member function can also be accessed using the class name through the scope resolution operator.
A static member function can access static data members and static member functions inside or outside of the class.
Static member functions have a scope inside the class and cannot access the current object pointer.
You can also use a static member function to determine how many objects of the class have been created.
The reason we need Static member function:
Static members are frequently used to store information that is shared by all objects in a class. 
For instance, you may keep track of the quantity of newly generated objects of a specific class type using a static data member as a counter. 
This static data member can be increased each time an object is generated to keep track of the overall number of objects.


const is not applied to static member function



// C++ Program to show the working of
// static member functions
#include <iostream> 
using namespace std; 

class Box 
{ 
	private: 
	static int length; 
	static int breadth; 
	static int height; 
	
	public:
	
	static void print() 
	{ 
		cout << "The value of the length is: " << length << endl; 
		cout << "The value of the breadth is: " << breadth << endl; 
		cout << "The value of the height is: " << height << endl; 
	}
}; 

// initialize the static data members 

int Box :: length = 10; 
int Box :: breadth = 20; 
int Box :: height = 30; 

// Driver Code

int main() 
{
	
	Box b; 
	
	cout << "Static member function is called through Object name: \n" << endl; 
	b.print(); 
	
	cout << "\nStatic member function is called through Class name: \n" << endl; 
	Box::print(); 
	
	return 0; 
}



----this pointer 
15. Which of the following is correct about this pointer in C++?
a) this pointer is passed as a hidden argument in all static variables of a class
b) this pointer is passed as a hidden argument in all the functions of a class
c) this pointer is passed as a hidden argument in all non-static functions of a class
d) this pointer is passed as a hidden argument in all static functions of a class
View Answer


Answer: c
Explanation: As static functions are a type of global function for a class so all the object shares 
the common instance of that static function whereas all the objects have there own instance for non-static 
functions and hence they are passed as a hidden argument in all the non-static members but not in static members.



In C and C++ programming, this is a pointer that is automatically available within the body of a nonstatic member function of a class
. It points to the object for which the function is being called. In other words, this is a pointer to the class object that is currently using the member function.
The this pointer is a constant pointer, which means it cannot be reassigned to point to a different object.
 However, it can be used to access the members of the class object it points to.
Here's an example that demonstrates the use of this pointer:
cpp
class MyClass {
private:
    int myData;
public:
    MyClass(int data) {
        myData = data;
    }

    void setData(int data) {
        myData = data;
    }

    int getData() {
        return myData;
    }

    void printData() {
        cout << "Data: " << this->getData() << endl;
    }
};

int main() {
    MyClass obj(10);
    obj.printData();
    obj.setData(20);
    obj.printData();
    return 0;
}

In the above example, the printData() function uses the this pointer to access the getData() function. The output of the program would be:
Data: 10
Data: 20

Note that the this pointer is not required to be used explicitly in the code. It is provided by the compiler as a convenience to the programmer. 
However, it can be useful in situations where there is ambiguity between class members and local variables.