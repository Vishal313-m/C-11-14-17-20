/* Override SPECIFIER*/

// A CPP program that uses override keyword so
// that any difference in function signature is
// caught during compilation
#include <iostream>
using namespace std;

class Base {
public:
	// user wants to override this in
	// the derived class
	virtual void func() { cout << "I am in base" << endl; }
};

class derived : public Base {
public:
	// did a silly mistake by putting
	// an argument "int a"
	void func(int a) override
	{
		cout << "I am in derived class" << endl;
	}
};

int main()
{
	Base b;
	derived d;
	cout << "Compiled successfully" << endl;
	return 0;
}

/*
OUTPUT 

prog.cpp:17:7: error: 'void derived::func(int)'
marked 'override', but does not override
  void func(int a) override 
       ^

*/


/*
The user intended to override the function func() in the derived class but did a silly mistake and redefined the function with a different signature. 
Which was not detected by the compiler. However, the program is not actually what the user wanted. 
So, to get rid of such silly mistakes to be on the safe side, the override identifier can be used. 

*/


/*  IMPORTANT 

Question - Is it possible to use override keyword in derived class without having virtual function in base class ?


Answer - No, it is not possible to use the override keyword in a derived class without having a virtual function in the base class. 
The override keyword is used to indicate that a method in a derived class is intended to override a virtual method in the base class. 
If there is no virtual method in the base class, there is nothing to override, and the override keyword is not necessary or allowed.



*/
