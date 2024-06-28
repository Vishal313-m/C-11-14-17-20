//Const Objects#ifndef DOG_H
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


include <iostream>
#include "dog.h"


int main(){

    const Dog dog1("Fluffy","Shepherd",2);



    dog1.set_name("Milou"); // Setting values on const object won't work - Compiler error

    dog1.print_info();   // Reading won't work either : Compiler error   // make methodds const 

    std::string name = dog1.get_name();   // compiler error 
    

   //Pointer to non const
     Dog * dog_ptr = &dog1; 

   //Non const reference
     Dog& dog_ref = dog1; // Error : can't convert from const Dog& to Dog&

   //Pointer to const
   const Dog* const_dog_ptr = &dog1;
    const_dog_ptr->set_name("Milou"); // Error - Expect
   const_dog_ptr->get_name(); // Error - not Expected 

   //Const reference
   const Dog& const_dog_ref = dog1;
   const_dog_ref.set_name("Milou"); // Expected
   const_dog_ref.get_name(); // Error - not expected 

    return 0;
}