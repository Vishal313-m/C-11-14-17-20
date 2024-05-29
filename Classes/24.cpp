// Copy Constructors 

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
private : 
	 std::string last_name{};
	 std::string first_name{};
	 int * age{};
public:
	//Constructors
    Person() = default;
    Person(const std::string& last_name_param, const std::string& first_name_param, int age_param);
    Person(const std::string& last_name_parm, const std::string& first_name_param);
    Person(const std::string& last_name);

    //Copy Constructor
   // Person(const Person source_p); // BAD : Potential for an endles chain of copy constructor calls

    //Memberwise copy
    //Person(const Person& source_p);

    //Don't blindly copy the pointer
    Person(const Person& source_p);
    ~Person();
	
	//Setters 
	void set_first_name(const std::string& first_name) {this->first_name = first_name;}
	void set_last_name(const std::string& last_name) {this->last_name = last_name;}
	void set_age(int age) {*(this->age) = age;} // Remember to dereference
	
	//Getters
	const std::string& get_first_name() const {return first_name;}
	const std::string& get_last_name() const {return last_name;}
	int* get_age() const{ return age;};

	//Utilities
	void print_info(){
		std::cout << "Person object at : " << this 
			<<" [ Last_name : " << last_name 
			<< ", First_name :  " << first_name 
			<< " ,age : " << *age 
			<< " , age address : " << age 
			<< " ]" << std::endl;
	}
};

#endif // PERSON_H




Person::~Person()
{
	delete age; // Make sure that you are not leaking memory
}
Person::Person(const std::string& last_name)
	: Person(last_name,"")
{
}
Person::Person(const std::string& last_name_param, const std::string& first_name_param)
	: Person(last_name_param,first_name_param,0)
{
}
Person::Person(const std::string& last_name_param, const std::string& first_name_param, int age_param)
	: 	last_name(last_name_param),
		first_name(first_name_param),
		age(new int(age_param))
{
}

/*
// Pass by value -- COMPILER ERROR
Person::Person(const Person source_p)  // BAAAAD!
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_last_name()),
        age(source_p.get_age())

{

}
*/


//Memberwise copy : BAD
/*  // This is do what compiler by default  will do it blindly copying the pointer
Person::Person(const Person& source_p) 
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_first_name()),
        age(source_p.get_age())

{
    std::cout << "Copy constructor called" << std::endl;

}
*/

//Don't blindly copy pointer member variables
/*It is going to set up a new memory location in our new person object, and then we're going to use the data in the source object.*/
/*
Person::Person(const Person& source_p) 
    : last_name(source_p.get_last_name()),
        first_name(source_p.get_first_name()),
        age(new int(*(source_p.get_age())))

{
    std::cout << "Copy constructor called" << std::endl;

}
*/

//Delegate from the copy constructor
Person::Person(const Person& source_p) 
    : Person(source_p.get_last_name(),source_p.get_first_name(),*(source_p.get_age()))
{
    std::cout << "Copy constructor called" << std::endl;

}


#include <iostream>
#include "person.h"


int main(){

    Person  p1("John","Snow",25);
    p1.print_info();

    //Create a person copy
    Person p2(p1);
    p2.print_info();

    std::cout << "-------" << std::endl;

    p1.set_age(30);
    p1.print_info();
    p2.print_info();
   
    return 0;
}

/*
Q- why we call copy constructor as pass by refrence not as pass by value


When discussing copy constructors in C++, they are referred to as "pass by reference" rather than "pass by value" due to the nature of their implementation.
 Copy constructors in C++ are designed to take a reference to an object of the same class as an argument, not the object itself.
  This design choice is crucial because passing objects by value would lead to unnecessary copies being made, triggering an infinite recursion loop.


The reason why copy constructors are called "pass by reference" is to avoid this recursive behavior. By passing objects by reference, 
the copy constructor can work directly with the original object without creating additional copies, preventing the infinite recursion
 issue that would occur if objects were passed by value. This distinction is essential in C++ to ensure the proper
  functioning of copy constructors and to avoid unintended consequences like infinite loops.


In summary, copy constructors in C++ are termed as "pass by reference" because they take a reference to an object,
 not the object itself, to prevent recursive copying and ensure efficient object initialization and copying processes



*/