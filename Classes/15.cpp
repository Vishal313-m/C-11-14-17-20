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

 /*
    So here we have a simple example which is going to show how you could come up with a dangling reference.
We have a simple function which is a member of our class dog here.
The name of the function is compiled dog info and it's going to return a const Stdstring reference.
Okay, so this is a safe function.
It's not going to be modifying the object, it's just going to be reading data from the object and look at what we do in the body.
Here we are setting up a string local object and we are basically putting this together.
We have the dog name and we have the dog breed and we have the dog age in here.
And we're going to store all of this information in this string object.
But look at what we do here.
We are going to return this.
And the moment this function returns, the local object, which is this string here, which is called
info, is going to be wiped out from memory because it is a local stack object and the reference we
return here might stay there long after this function is done executing.
So if we try to use this reference somewhere later, after we call this function, we will be setting
ourselves up for disaster because this is a dangling reference.
It is no longer referencing valid data because what it was referencing is long dead.
It was wiped out after the function here finished executing.
And this is a bad reference.
You shouldn't be using it.
If you use it, you're going to be having problems.
This is what I want you to see here.
But we can also have the same problems with pointers.
Suppose we have a function here which is going to return an INT pointer and it is a cast member function.
It's not going to be modifying our object in any way.
And this is a member class because we see that it is part of the dog class here.
So what we do in the body, we are setting up a local variable and we are returning it.
So we are returning the address of this variable.
And when this function finishes, executing this pointer might be alive.
And if we try to use it, we're going to basically be dereferencing something that is already dead.
It's no longer going to be there and something else might be living at this memory address already.
Hopefully you can see that if we try to use this pointer somewhere after this function is done, we're
going to be setting ourselves up for disaster because we will be using memory that doesn't belong to us anymore.
So this is really what I want you to see, that dangling pointers and dangling references.
Are really bad and you should watch out for this.
Thanks to come up in your program whether you are using classes or not.
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
    const std::string& str_ref = dog1.compile_dog_info(); This is a reference that already dead
    std::cout << " info : " << str_ref << std::endl;
    */

   unsigned int* int_ptr = dog1.jumps_per_minute();
   std::cout << "jumps_per_minute : " << *int_ptr << std::endl;

    std::cout << "Done!" << std::endl;
    return 0;
}