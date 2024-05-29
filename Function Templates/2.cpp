// Template type deduction and Explicit Arguments 

#include <iostream>
#include <string>

template <typename T> T maximum( T a, T b){
    return (a > b) ? a : b;
}

int main(){

	int a{10};
	int b{23};
	double c{34.7};
	double d{23.4};
	std::string e{"hello"};
	std::string f{"world"};

    //Explicit template arguments

    auto max = maximum<double>(a,d);
    std::cout << "max : " << max << std::endl;
   
    return 0;
}



/* Template instance 

First instantiated from: insights.cpp:19 
#ifdef INSIGHTS_USE_TEMPLATE
template<>
double maximum<double>(double a, double b)
{
  return (a > b) ? a : b;
}
#endif


*/