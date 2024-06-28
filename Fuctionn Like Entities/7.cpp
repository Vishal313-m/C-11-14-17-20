// Function Pointer :: SYNTAX
/* A function is just a block of code that lives somewhere in the memory map  of our c++  program. we can grab the address of the function and store it in a function pointer */
#include<iostream>
using namespace std;


double add(double a , double b)
{
    return a+b;

}


int main()
{
    double (*fptr) (double , double ) = &add;
    double  (*fptr) (double ,double ) = add;


    double (*fptr) (double , double )  {&add};
    double (*fptr) (double ,double ) {add};




    auto fptr = &add;
    auto fptr = add;


    auto* fptr = &add;
    auto *fptr = add;

    // This all syntax are same 

    cout<<add(10,20)<<std::endl;



   double (*fptr) (double , double ) = nullptr; // if you call this , you can expect bad things to happen 

 
    auto fptr = nullptr; // compiler error : auto deducing nullptr;
    


}