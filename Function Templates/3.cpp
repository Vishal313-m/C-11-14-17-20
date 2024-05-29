// Template PARAMETERS BY REFERENCE 


#include <iostream>

template <typename T> const T& maximum(const T& a, const T& b); // Declaration


int main(){

    double a {23.5};
    double b {51.2};

    std::cout << "Out - &a: " << &a << std::endl; // 0x111abc
    auto result = maximum(a,b);
    std::cout << "Out - &a: " << &a << std::endl; // 0x111abc
  
    return 0;
}


//Definition
template <typename T> const T& maximum(const T& a, const T& b){
    std::cout << "In - &a: " << &a << std::endl; // // 0x111abc
    return (a > b ) ? a : b ;
}

/*

OUTPUT 

Out - &a: 0x7ffd895cb7c0
In - &a: 0x7ffd895cb7c0
Out - &a: 0x7ffd895cb7c0


*/


/*
 TEMPLATE INSTANCE 
 const double & maximum<double>(const double & a, const double & b)
{
  std::operator<<(std::cout, "In - &a: ").operator<<(reinterpret_cast<const void *>(&a)).operator<<(std::endl);
  return (a > b) ? a : b;
}




*/