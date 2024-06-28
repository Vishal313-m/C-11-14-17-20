/* CALLBACK FUNCTION */


/* A callback function is a function whose function pointer may be passed to another function as a parameter 
, and be called somewhere in the body of that function */

#include <iostream>


char encrypt(const char& param){ // Callback function
    return static_cast<char> (param + 3);
}

char decrypt(const char& param){ // Callback function
    return static_cast<char> (param - 3);
}


std::string & modify(std::string& str_param,
                                        char(* modifier)(const char&))
{
     for(size_t i{} ; i < str_param.size() ; ++i){
        str_param[i] = modifier(str_param[i]); // Calling the callback
     }
     return str_param;
}

int main(){

    std::string msg{"Hello"};
    modify(msg,encrypt);
    std::cout << "outcome : " << msg << std::endl;

    std::cout << "------" << std::endl;
   

    modify(msg,decrypt);
    std::cout << "outcome : " << msg << std::endl;
/*

outcome : Khoor
------
outcome : Hello




*/
}