// Pointer to char 

#include <iostream>


int main(){
   

   //Initialize with string literal
    const char * message {"Hello World!"};
    std::cout << "message : " << message << std::endl;

    //*message = "B"; // Compiler error
    std::cout << "*message : " << *message << std::endl;

    //Allow users to modify the string
    char message1[] {"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;
    
    return 0;
}


OUTPUT 

message : Hello World!
*message : H
message1 : Bello World!
