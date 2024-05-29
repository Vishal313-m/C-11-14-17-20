// Dangling Pointers and references in objects 

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

class Dog{
public : 
     Dog() = default;
     Dog(const std::string& name_param, const std::string& breed_param, unsigned int age_param);

     std::string& name(){
        return m_name;
     }
     const std::string& name() const{
        return m_name;
     }


     std::string& breed(){
        return m_breed;
     }
     const std::string& breed() const{
        return m_breed;
     }



     unsigned int& age(){
        return m_age;
     }
     const unsigned int& age() const{
        return m_age;
     }
        /*
     //Getters
     std::string get_name() const;
     std::string get_breed() const;
     unsigned int get_age() const;

     //Setters
     void set_name(std::string name_param);
     void set_breed(std::string breed_param);
     void set_age(unsigned int age);
     */

     //Utility functions
     void print_info() const;
     const std::string& compile_dog_info() const{
        std::string dog_info = "dog_name : " + m_name
                              + " dog_breed : " + m_breed
                              + " dog_age :" + std::to_string(m_age);
      return dog_info;
     }

   unsigned int* jumps_per_minute() const{
        unsigned int jumps {5};
        return &jumps;
     }

private : 
        std::string m_name;
        std::string m_breed;
        unsigned int m_age;
};


#endif // DOG_H


include "dog.h"
     
     Dog::Dog(const std::string& name_param, const std::string& breed_param, unsigned int age_param){
         m_name = name_param;
         m_breed = breed_param;
         m_age = age_param;
     }

    /*
     //Getters
     std::string Dog::get_name() const{
         //return m_name;
         return this->m_name;
     }
     std::string Dog::get_breed() const {
         return m_breed;
     }
     unsigned int Dog::get_age() const{
         return m_age;
     }

     //Setters
     void Dog::set_name(std::string name_param){
        // m_name = name_param;
        this->m_name = name_param;
     }
     void Dog::set_breed(std::string breed_param){
         m_breed = breed_param;
     }
     void Dog::set_age(unsigned int age){
         m_age = age;
     }
     */

     //Utility functions
     void Dog::print_info() const {
         std::cout << "Dog (" << this << ") : [ name : " << this->m_name  
                << ", breed : " << this->m_breed  
                << ", age : " << this->m_age << "]" << std::endl;
     }


#include <iostream>
#include "dog.h"

int main(){

    Dog dog1("Fluffy","Shepherd",2);

    /*
    const std::string& str_ref = dog1.compile_dog_info();
    std::cout << " info : " << str_ref << std::endl;
    */

   unsigned int* int_ptr = dog1.jumps_per_minute();
   std::cout << "jumps_per_minute : " << *int_ptr << std::endl;

    std::cout << "Done!" << std::endl;
    return 0;
}