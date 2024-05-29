// OBJeCT STORED iN ARRAYS ARE copieS


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





#include "person.h"

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

//Delegate from the copy constructor
Person::Person(const Person& source_p) 
    : Person(source_p.get_last_name(),source_p.get_first_name(),*(source_p.get_age()))
{
    std::cout << "Copy constructor called for " << last_name <<  std::endl;

}




#include "person.h"


int main(){

    Person p1("John","Snow",25);
    Person p2("Sam","Gray",45);
    Person p3("Johny","Drill",5);
    p1.print_info();
    p2.print_info();
    p3.print_info();

    std::cout << "----" << std::endl;

    Person students[] {p1,p2,p3};
    for(size_t i{}; i < std::size(students); ++i){
        students[i].print_info();
    }

    std::cout << "----" << std::endl;
    for(Person& p : students){  // iT AVOID COPIES 
    
        p.print_info();
    }


   
    return 0;
}