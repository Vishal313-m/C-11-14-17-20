//PASS BY VALUE 


#include <iostream>

void say_age(int age){ // Parameter
    ++age;
    std::cout <<  "Hello , you are " << age << " years old! &age : " << &age <<  std::endl;
}

int main(){

    int age{23}; // Local
    std::cout << "age (before call) : " << age << "&age : " << &age << std::endl;
    say_age(age); // Argument
    std::cout << "age (after call) : " << age << "&age : " << &age <<  std::endl;

    return 0;
}



age (before call) : 23&age : 0x7fff62059d74
Hello , you are 24 years old! &age : 0x7fff62059d5c
age (after call) : 23&age : 0x7fff62059d74
