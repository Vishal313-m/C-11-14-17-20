// PASS BY CONST POINTER TO CONST

#include <iostream>

int dog_count{2};

void say_age(const int* const age); // Declaration

int main(){

    int age{23}; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl; 
    say_age(&age); // Argument
    std::cout << "age (after call) : " << age << "&age : " << &age <<  std::endl; 

    return 0;
}


void say_age(const int* const age){ // Parameter
    //++(*age); //
    std::cout <<  "Hello , you are " << *age << " years old! &age : " << &age <<  std::endl;
    //age = & dog_count;
}

age (before call) : 23&age : 0x7ffd40879244
Hello , you are 23 years old! &age : 0x7ffd40879228
age (after call) : 23&age : 0x7ffd40879244
