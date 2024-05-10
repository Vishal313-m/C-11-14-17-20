// if constexpr() {}


/*
The if constexpr statement in C++ is a compile-time conditional that allows the compiler to select which code to compile based on constant expressions. 
It is used to write generic, metaprogramming-style code that can be optimized at compile-time.
*/

#include<iostream>
#include<string>
#include<type_traits>
using namespace std:

template<typename T>
auto length(T const& value)
{
    if(is_integral<T>::value){
        return value;
    }

    else{
        return value.length();
    }


}

int main()
{
    int n{10};
    string s{"abc"};


    cout << "n=" << n  << "and length ="  << length(n) <<endl;

    cout << "s=" << s  << "and length ="  << length(s) <<endl;
}


/* It is will through an error , there will be two copy of the templated code one is for integer type and one is for string type 
Lets say replace T with integer now value is integer type so ther is member function for integer type value.length()
auto length( int const& value)
{
    if(is_integral<T>::value){
        return value;
    }

    else{
        return value.length();
    }


}


*/


For this now we have solution 



#include<iostream>
#include<string>
#include<type_traits>
using namespace std:

template<typename T>
auto length(T const& value)
{
    if constexpr (is_integral<T>::value){  // now this was dealing at compile time before its executing at run time 
        return value;
    }

    else{
        return value.length();
    }


}

int main()
{
    int n{10};
    string s{"abc"};


    cout << "n=" << n  << "and length ="  << length(n) <<endl;

    cout << "s=" << s  << "and length ="  << length(s) <<endl;
}

---------------------------------basically what happens here ---------------------------------------

when this length(n) is asking for integer 

auto length(int const& value)
{
    return value;
}
this is what ig going to be in integer case


case:2


auto length(string const& value)
{
    return value.length();
}