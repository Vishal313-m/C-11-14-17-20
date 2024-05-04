/* Date Input and Output */


Stream	        Purpose
cin (istream)	Used for taking input from the standard input device (usually the keyboard)
cout (ostream)	Used for writing output to the standard output device (usually the console/terminal)
cerr (ostream)	Used for writing unbuffered error messages to the standard error device (usually the console/terminal)
clog (ostream)	Used for writing buffered error messages to the standard error device (usually the console/terminal)


#include <iostream>
#include <string>

int main(){
   //Printing data
   /*
   std::cout << "Hello C++20 " << std::endl;

   int age{21};
   std::cout << "Age : " << age << std::endl;

   std::cerr << "Error message : Something is wrong" << std::endl;
   std::clog << "Log message : Something happened " << std::endl; 

   */

  

   //Data input

   /*
   int age1;
   std::string name;

   std::cout << "Please type your name and age : " << std::endl;

   //std::cin >> name;
   //std::cin >> age1;

    //chaining
   std::cin >> name >> age1;

   std::cout << "Hello " << name << " you are " << age1 << " years old!" << std::endl;

    */



    //Data with spaces

    std::string full_name;
    int age3;

    std::cout << "Please type in your full name and age " << std::endl;

    std::getline(std::cin,full_name);

    std::cin >> age3;

    std::cout << "Hello " << full_name 
            << " you are " << age3 << " years old!" << std::endl;


 
  return 0;
}