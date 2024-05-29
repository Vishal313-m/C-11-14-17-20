//Mutable Member variable 

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
 
     //Utility functions
     void print_info() const;

private : 
        std::string m_name;
        std::string m_breed;
        unsigned int m_age;
        mutable size_t m_print_info_count{};
};


#endif // DO


  #include "dog.h"
     
     Dog::Dog(const std::string& name_param, const std::string& breed_param, unsigned int age_param){
         m_name = name_param;
         m_breed = breed_param;
         m_age = age_param;
     }


     //Utility functions
     void Dog::print_info() const {
         ++m_print_info_count;
         std::cout << "Dog (" << this << ") : [ name : " << this->m_name  
                << ", breed : " << this->m_breed  
                << ", age : " << this->m_age
                 << ",print_count : " << m_print_info_count << "]" << std::endl;
     }



 #include <iostream>
#include "dog.h"

int main(){

    Dog dog1("Fluffy","Shepherd",2);
    dog1.print_info(); //1
    dog1.print_info();//2

    for(size_t i{0}; i <10;++i){
        dog1.print_info();
    }

    return 0;
}