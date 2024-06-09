// Template Specialization

/*
You can specialize a class template for certain template arguments.
 This allows you to optimize implementations for specific types or fix misbehavior for certain types

 When specializing a class template, you must also specialize all its member functions. 
 If you specialize a single member function, you can no longer specialize the whole class

 */


/*
Class template specializations are FULL classes, they are not templates.If their definitions show up in a header and the header is included in multiple files 
you'll get ODR violations
*/


/* A common mistake for beginners is to think that you can specialize a few methods ,leave the others out,hoping the compiler will fill those in from the original
template */

#include <iostream>
#include <cstring>

// Regular class template
template <typename T>
class Adder
{
public:
	Adder(){
    }
	T add(T x, T y);
	void do_something(){
		std::cout << "Doing something..." << std::endl;
	}
};

template <typename T>
T Adder<T>::add(T a, T b)
{
	return a+b;
}


// Template specialization
template <>
class Adder <char*>
{
public:
	Adder(){
    }
	char* add(char* a, char* b);
};

 //template <> //  <= this is not needed if defined outside of class
inline 
char* Adder<char*>::add(char* a, char* b)
{
	return strcat(a,b);
}



adder.cpp

/*
 #include "adder.h"
 //template <> //  <= this is not needed if defined outside of class
char* Adder<char*>::add(char* a, char* b)
{
	return strcat(a,b);
}
*/


#include <iostream>
#include "adder.h"


int main(){

    Adder<int> adder_int;
	adder_int.do_something();
    std::cout << adder_int.add(10,20) << std::endl;

    std::cout << "-------" << std::endl;

    //Char*
    char str1[20] {"Hello"};
    char str2[] {" World!"};
    
    Adder<char*> adder_c_str;
	//adder_c_str.do_something();
    std::cout << adder_c_str.add(str1,str2) << std::endl;
   
    return 0;
}




/*



template <class T> class mycontainer {
    T value;
public:
    void increase() {
        value++;
    }
};

template <> class mycontainer<char> {
    char value;
public:
    void uppercase() {
        value = toupper(value);
    }
};

In this example, mycontainer is a class template that can store any type.
 The specialization for char type adds a different member function uppercase instead of increase


*/


#include <iostream>
using namespace std;

template <class T>
class Test
{
// Data members of test
public:
Test()
{
	// Initialization of data members
	cout << "General template object \n";
}
// Other methods of Test
};

template <>
class Test <int>
{
public:
Test()
{
	// Initialization of data members
	cout << "Specialized template object\n";
}
};

int main()
{
	Test<int> a;
	Test<char> b;
	Test<float> c;
	return 0;
}


OUTPUT 

Specialized template object
General template object 
General template object 


/*Function template specialization


#include <iostream>
using namespace std;
 
template <class T>
void fun(T a)
{
   cout << "The main template fun(): "
        << a << endl;
}
 
template<>
void fun(int a)
{
    cout << "Specialized Template for int type: "
         << a << endl;
}
 
int main()
{
    fun<char>('a');
    fun<int>(10);
    fun<float>(10.14);
}

The main template fun(): a
Specialized Template for int type: 10
The main template fun(): 10.14

*/