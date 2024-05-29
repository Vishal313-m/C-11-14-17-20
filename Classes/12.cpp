// Const Object As Function Arguments 

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

class Dog{
public : 
     Dog() = default;
     Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param);

     //Getters
     std::string_view get_name();
     std::string_view get_breed();
     unsigned int get_age();

     //Setters
     void set_name(std::string_view name_param);
     void set_breed(std::string_view breed_param);
     void set_age(unsigned int age);

     //Utility functions
     void print_info();

private : 
        std::string_view m_name;
        std::string_view m_breed;
        unsigned int m_age;
};


#endif // DOG_H


  #include "dog.h"
     
     Dog::Dog(std::string_view name_param, std::string_view breed_param, unsigned int age_param){
         m_name = name_param;
         m_breed = breed_param;
         m_age = age_param;
     }

     //Getters
     std::string_view Dog::get_name(){
         //return m_name;
         return this->m_name;
     }
     std::string_view Dog::get_breed(){
         return m_breed;
     }
     unsigned int Dog::get_age(){
         return m_age;
     }

     //Setters
     void Dog::set_name(std::string_view name_param){
        // m_name = name_param;
        this->m_name = name_param;
     }
     void Dog::set_breed(std::string_view breed_param){
         m_breed = breed_param;
     }
     void Dog::set_age(unsigned int age){
         m_age = age;
     }

     //Utility functions
     void Dog::print_info(){
         std::cout << "Dog (" << this << ") : [ name : " << this->m_name  
                << ", breed : " << this->m_breed  
                << ", age : " << this->m_age << "]" << std::endl;
     }



#include <iostream>
#include "dog.h"

//This causes no problem because we are working with 
//a copy inside the function
void function_taking_dog(Dog dog){
	dog.set_name("Internal dog");
	dog.print_info();
}

//Parameter by reference
void function_taking_dog_ref(Dog& dog_ref){
	//Compiler won't allow passing const object as argument
}

//Parameter by const reference
void function_taking_const_dog_ref(const Dog& const_dog_ref){
	//const_dog_ref.set_name("Hillo"); //Expected
	//const_dog_ref.print_info(); // Error
}

//Pointer to non const as parameter
void function_taking_dog_p(Dog* p_dog){
	//Compiler won't allow passing const Dog objects as arguments
}

//Parameter passed as pointer to const
void function_taking_pointer_to_const_dog(const Dog* const_p_dog){
	const_p_dog->set_name("Hillo");//Error : Expected
	const_p_dog->print_info(); //Error : Not expected
}


int main(){

    const Dog dog1("Fluffy","Shepherd",2);
    std::cout << "address of object : " << &dog1 << std::endl;

    //Function taking parameter by value : WORKS
    //function_taking_dog(dog1);

    //function_taking_dog_ref(dog1); // Compiler error

    //function_taking_const_dog_ref(dog1);

    //function_taking_dog_p(&dog1);

    //function_taking_pointer_to_const_dog(&dog1);


    return 0;
}
