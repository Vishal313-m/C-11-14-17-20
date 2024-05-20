Implicit conversion with pointers 


#include <iostream>

void print_sum(int* param1, int* param2){
	std::cout << "sum : " << (*param1 + *param2) << std::endl;
}

int main(){

    int a{3};
    int b{12};

    print_sum(&a,&b);  // It will work fine 


    double c{4.5};
    double d{5.6};

     
      print_sum(&a,&b); // give compiler error can't convert from double* to int*
    return 0;