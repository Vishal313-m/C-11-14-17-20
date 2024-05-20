// OVERLOADS WITH DEFAULT PARAMETERS 


#include <iostream>

//Declarations
void print_age(int age = 33);

void print_age(long int age = 44);

int main(){


    print_age();
    
    
    return 0;
}

//Definitions
void print_age(int age ){
    std::cout << "Your age is( int version)  : " << age << std::endl;
}

void print_age(long int age){
    std::cout << "Your age is (long int version) : " << age << std::endl;
}


/*Here we have two functions.

They are a valid cplusplus overloads and that the name is print age and the parameters are of int and

long.

And these are different types in c plus plus, so they are valid function overloads.

The problem is if we try to call any of these functions without a parameter like we do here, which

would use the default argument, the compiler is going to be confused.

Again, it doesn't know which one you want.

Is it going to be the one with INT or the one with long ENT and you're going to get a compiler error

saying that your function call here is ambiguous, so be really careful about this.*/