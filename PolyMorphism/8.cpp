/*  FINAL SPECIFIER */

/*In Java, we can use final for a function to make sure that it cannot be overridden. We can also use final in Java to make sure that a class cannot be inherited. 
Similarly, the latest C++ standard C++ 11 added final. 

--Use of final specifier in C++ 11: 
Sometimes you don’t want to allow derived class to override the base class’ virtual function. 
C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier. 

Consider the following example which shows use of final specifier. This program fails in compilation. 

*/

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void myfun() final
	{
		cout << "myfun() in Base";
	}
};
class Derived : public Base
{
	void myfun()
	{
		cout << "myfun() in Derived\n";
	}
};

int main()
{
	Derived d;
	Base &b = d;
	b.myfun();
	return 0;
}

/*
OUTPUT 

prog.cpp:14:10: error: virtual function ‘virtual void Derived::myfun()’
     void myfun()
          ^
prog.cpp:7:18: error: overriding final function ‘virtual void Base::myfun()’
     virtual void myfun() final 

*/


/*2nd use of final specifier: 
final specifier in C++ 11 can also be used to prevent inheritance of class / struct. 
If a class or struct is marked as final then it becomes non inheritable and it cannot be used as base class/struct. */

// The following program shows use of final specifier to make class non inheritable: 

#include <iostream>
class Base final
{
};

class Derived : public Base
{
};

int main()
{
	Derived d;
	return 0;
}

/*
OUTPUT

error: cannot derive from ‘final’ base ‘Base’ in derived type ‘Derived’
 class Derived : public Base

*/