/* FUNCTOR */

/* Class Objects that can be called like ordinary funtions */
/* We set them up by overloading the () operatopr for our class */



A functor in C++ is an object that can be used like a function.
 It is implemented by overloading the function call operator () in a class. Here are some key points about the usage of functors:
Creating a Functor
Overloading the Function Call Operator (()): The () operator is overloaded to define the behavior of the functor when called. 
This allows the functor to be used like a function.


Using a Functor
Creating an Object: An instance of the functor class is created.
Calling the Functor: The functor is called using the () operator, passing in any required arguments.


Advantages
Encapsulation: Functors can encapsulate complex logic and operations, making the code more modular and easier to maintain.
Flexibility: Functors can be used with various data types and can be customized to perform different operations.
Efficiency: Functors can be more efficient than regular functions in certain situations, such as when used with algorithms like std::transform().

Examples

Multiplier Functor: A functor that multiplies its argument by a fixed value.
Increment Functor: A functor that adds a fixed value to its argument.
Fibonacci Generator: A functor that generates a sequence of Fibonacci numbers.

Common Use Cases
STL Algorithms: Functors are often used with C++ Standard Template Library (STL) algorithms like std::transform() and std::sort() to provide custom operations or comparisons.
Custom Data Structures: Functors can be used to implement custom data structures like maps and sets.
Example Code
cpp
#include <iostream>
#include <vector>

class Multiplier {
private:
    int factor_;
public:
    Multiplier(int factor) : factor_(factor) {}
    
    int operator()(int x) const {
        return x * factor_;
    }
};

int main() {
    // Create a functor
    Multiplier multiply_by_5(5);

    // Use the functor
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::transform(numbers.begin(), numbers.end(), numbers.begin(), multiply_by_5);

    // Print the results
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

Example Output
5 10 15 20 25

Example Explanation
Multiplier Functor: The Multiplier class is a functor that multiplies its argument by a fixed value.
Using the Functor: An instance of Multiplier is created with a factor of 5.
 The functor is then used with std::transform() to multiply each element in a vector by 5.
Output: The transformed vector is printed, showing the elements multiplied by 5


/*------------------------------------------------------------------------------------------------------------------------------------*/


/*Decrypt.h*/

#ifndef DECRYPT_H
#define DECRYPT_H

//Functor or function object

class Decrypt
{
public:
    char operator()( const char& param){
         return static_cast<char> (param - 3);
    }
};

#endif // DECRYPT_H




/*Encrypt.h*/


#ifndef ENCRYPT_H
#define ENCRYPT_H

class Encrypt
{
public:
    char operator()( const char& param){
         return static_cast<char> (param + 3);
    }
};

#endif // ENCRYPT_H



/*main.cpp*/


#include <iostream>
#include "encrypt.h"
#include "decrypt.h"


char encrypt(const char& param){ // Callback function
    return static_cast<char> (param + 3);
}

char decrypt(const char& param){ // Callback function
    return static_cast<char> (param - 3);
}


template <typename Modifier>
std::string & modify(std::string& str_param,
                                        Modifier modifier)
{
     for(size_t i{} ; i < str_param.size() ; ++i){
        str_param[i] = modifier(str_param[i]); // Calling the callback
     }
     return str_param;
}


int main(){

    std::string str {"Hello"};
    
    std::cout << std::endl;
    std::cout << "Modifying string through function pointers : " << std::endl;
    std::cout << "Initial : " << str << std::endl;
    std::cout << "Encrypted : " <<  modify(str,encrypt) << std::endl;
    std::cout << "Decrypted : " << modify(str,decrypt) << std::endl;

    std::cout << "------" << std::endl;

    //Using functors
    Encrypt encrypt_functor;
    Decrypt decrypt_functor;
    
    std::cout << "encrypt_functor : " << encrypt_functor('A') << std::endl; // D
    std::cout << "decrypt_functor : " << decrypt_functor('D') << std::endl;// A


    std::cout << "-----" << std::endl;

    std::cout << std::endl;
    std::cout << "Modifying string through functors : " << std::endl;
    std::cout << "Initial : " << str << std::endl;
    std::cout << "Encrypted : " <<  modify(str,encrypt_functor) << std::endl;
    std::cout << "Decrypted : " << modify(str,decrypt_functor) << std::endl;
   
    return 0;
}



/*---------------------------------------------------------------------------------------------------------------------------*/


#include<iostream>
#include<vector>
#include<algorithm>

struct value{

     int m_result1{0};
     int m_result2{0};

     int operator()(int newResult1){
        m_result1 = newResult1;
        return newResult1;
     }


     float operator()(float newResult2 ){
        m_result2 = newResult2;
        return newResult2;
      }

};

int main()
{
    value v;
    v(42);
    v(42.7f);

    std::cout<< v.m_result1 
              << " ,"
              <<v.m_result2
              <<std::endl;
}



/*-------------------------------------------------------------------------------------------------------------*/

#include<iostream>
#include<vector>
#include<algorithm>


struct Goblin{

    int mHealth;
    int mStrength;

    Goblin(int h , int s) : mHealth(h),mStrength(s) {}

    bool operator <(const Goblin& rhs){
        return this->mHealth <rhs.mHealth;
    }
};


struct GoblinComparator{

    bool operator () (const Goblin& lhs , const Goblin& rhs ) const
    {
        return lhs.mStrenght < rhs.mStrenght 
    }
};


int main()
{
    std::vector<Goblin> goblins { Goblin(5, 205),
                                   Goblin(3,25) ,
                                   Goblin(100,1)};

     std::sort(begin(goblins),end(goblins ),GoblinComparator());

     for(auto g :goblins){
        std::cout<< g.mHealth << std::endl;
        
     }                              
}


