// AUTo type deduction 


#include <iostream>


int main(){

    //Type deduction with auto : Just a copy

	double some_var{55.5};
	
	auto x = some_var;
	
	std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl;
	std::cout << "sizeof(x) : " << sizeof(x) << std::endl;
	std::cout << "&some_var : " << &some_var << std::endl;
	std::cout << "&x : " << &x << std::endl;
    std::cout << " some_var : " << some_var << std::endl;
    std::cout << " x : " << x << std::endl;





	double some_var = 55.5; //double
	
	double& some_var_ref {some_var};
	
	auto y = some_var_ref; // y is not deduced as a reference to double
						   // it's just a double that contains the value 
						   // in some_var_ref
	++y;
					
	std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl; // 8
	std::cout << "sizeof(some_var_ref) : " << sizeof(some_var_ref) << std::endl; // 8
	std::cout << "sizeof(y) : " << sizeof(y) << std::endl; // 8
	std::cout << "&some_var : " << &some_var << std::endl; // 0xabc123
	std::cout << "&some_var_ref : " << &some_var_ref << std::endl ;// 0xabc123
	std::cout << "&y : " << &y << std::endl;  // 0xaab543
	std::cout << "some_var : " << some_var << std::endl; //55.5
	std::cout << "some_var_ref : " << some_var_ref << std::endl; // 55.5
	std::cout << "y : " << y << std::endl; // 56.5



   // True reference deduction

   	double some_var = 55.5; //double
    double& some_var_ref {some_var};

	
	auto& z = some_var_ref; // z is deduced as a double reference
	++z;
	
	std::cout << "sizeof(some_var) : " << sizeof(some_var) << std::endl; // 8
	std::cout << "sizeof(some_var_ref) : " << sizeof(some_var_ref) << std::endl; // 8
	std::cout << "sizeof(z) : " << sizeof(z) << std::endl; // 8
	std::cout << "&some_var : " << &some_var << std::endl;// 0xabc123
	std::cout << "&some_var_ref : " << &some_var_ref << std::endl;// 0xabc123
	std::cout << "&z : " << &z << std::endl;// 0xabc123
	std::cout << "some_var : " << some_var << std::endl; // 56.5
	std::cout << "some_var_ref : " << some_var_ref << std::endl; //56.5
	std::cout << "z : " << z << std::endl; // 56.5



	//Constness is preserved with properly deduced references.

	const double some_other_var {44.3};
	
	const double& const_ref {some_other_var};
	
	auto& p = const_ref;
	
	std::cout << "some_other_var : " << some_other_var << std::endl;
	std::cout << "const_ref : " << const_ref << std::endl;
	std::cout <<  "p : " << p << std::endl;
	
	//++p; // Compiler error
	
	std::cout << "some_other_var : " << some_other_var << std::endl;
	std::cout << "const_ref : " << const_ref << std::endl;
	std::cout <<  "p : " << p << std::endl;


	//Constness doesn't matter with non reference deduction
	const double i_am_const {71.2};
    const double& my_ref {i_am_const};

	auto q = my_ref; // q is a separate variable, initialized with the
							// value in i_am_const.
	++q;// Can modify q without a problem. It's a copy.
	




	
   
    return 0;
}



Quiz 


Question 3:
Considering the code below

#include <iostream>
 
int main(){
 
    unsigned int age1{21};
    unsigned int& age_ref{age1};
    auto& age2{age_ref};
 
    std::cout << "age1 : " << age1 << " age2 : " << age2 << std::endl;
    ++age2;
    std::cout << "age1 : " << age1 << " age2 : " << age2 << std::endl;
 
    return 0;
}
what will be the output?


option 1 - age1 : 21        age2: 21 
           age1: 22        age2: 22 


option 2  - age1 : 21        age2: 21 
           age1: 21        age2: 22 


OPtion 2 is correct
Yes. You got this right! age2 will just deduce another separate variable containing a copy of the value in age1. 
Incrementing age2 will only affect age2 and nothing else. Hence the output here.





Quiz 2 


Question 2:
Considering the code below

#include <iostream>
 
int main(){
 
    unsigned int age1{21};
    unsigned int& age_ref{age1};
    auto age2{age_ref};
 
    std::cout << "age1 : " << age1 << " age2 : " << age2 << std::endl;
    ++age2;
    std::cout << "age1 : " << age1 << " age2 : " << age2 << std::endl;
 
    return 0;
}
what will be the output?


what will be the output?


option 1 - age1 : 21        age2: 21 
           age1: 21       age2: 21


option 2  - age1 : 21        age2: 21 
           age1: 21        age2: 22 

Option 2 is correct 


Yes. You got this right! age2 will deduce a copy, 
so doing any modifications through it like ++age2 won't affect anything else but age2 alone. Hence the output here.




Quiz 3 


Question 3:
Considering the code below

#include <iostream>
 
int main(){
 
    unsigned int age1{21};
    unsigned int& age_ref{age1};
    auto& age2{age_ref};
 
    std::cout << "age1 : " << age1 << " age2 : " << age2 << std::endl;
    ++age2;
    std::cout << "age1 : " << age1 << " age2 : " << age2 << std::endl;
 
    return 0;
}
what will be the output?

option 1 - age1 : 21        age2: 21 
           age1: 21       age2: 21


option 2  - age1 : 21        age2: 21 
           age1: 22        age2: 22 


           Option 2 is correct 
 Yes. You got this right! age2 will deduce a true reference to what is referenced by age_ref.
  So changes applied through age2 will be visible both in age_ref and age1. Hence the output here.



  Quiz 4 


  onsidering the code below

#include <iostream>
 
auto multiplty(double& a, double & b){
    return a*=b;
}
 
int main(){
 
    auto value1{10.0};
    auto value2{20.0};
 
    auto result = multiplty(value1,value2);
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
    ++result;
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
 
    return 0;
}
what will be the output?


result :200 value1: 200 value2 :20 
result :201 value1: 200 value2 :20 -------This is the correct Option 


Yes. You got this right. The function is doing naked auto return type deduction, 
so we're just grabing a copy of what's returned and returning that to the caller of the function.
 In main we're storing that return value in the result local variable. So result is just a "COPY".
  Any modification we do through result in main won't have any effect of value1 or value3, it'll just affect result. Hence the print out here.



  quiz 5 

  Question 5:
Considering the code below

#include <iostream>
 
auto multiplty(double& a, double & b){
    return a*=b;
}
 
int main(){
 
    auto value1{10.0};
    auto value2{20.0};
 
    double& result = multiplty(value1,value2);
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
    ++result;
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
 
    return 0;
}
what will be the output?

The code won't compile 


Yes. You got this right! The function is doing naked auto return type deduction, so it's returning a copy. 
But we're trying to treat that returned copy as a reference in main and the compiler won't like that. Hence the compiler error!



Quiz 6 


Question 6:
Considering the code below

#include <iostream>
 
auto& multiplty(double& a, double & b){
    return a*=b;
}
 
int main(){
 
    auto value1{10.0};
    auto value2{20.0};
 
    double& result = multiplty(value1,value2);
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
    ++result;
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
 
    return 0;
}
what will be the output?


result :200 value1: 200 value2 :20 
result :201 value1: 201 value2 :20 -------This is the correct Option 


Yes. You got this right! The function is doing true reference return type deduction and we're grabing the return value and storing that in a reference.
 result can safely be used to affect value1 which is where we've stored the result in the body of the function. 
 Take a good look at the compund assignment operator in there, it may have thrown you off!



 Question 7:
Considering the code below

#include <iostream>
 
auto& multiplty(double& a, double & b){
    return a*=b;
}
 
int main(){
 
    auto value1{10.0};
    auto value2{20.0};
 
    double result = multiplty(value1,value2);
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
    ++result;
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
 
    return 0;
}
what will be the output?


result :200 value1: 200 value2 :20 
result :201 value1: 200 value2 :20 -------This is the correct Option 


Yes. You got this right. The function is properly duducing a returned reference, but on function call, we are storing the result in a non reference variable,
 and that's just taking a copy of the referenced value and storing that in result.
  Since result is just a copy, changes applied through it won't be visible in value1. Hence the print out here.



  Question 8:
Considering the code below

#include <iostream>
 
auto& multiplty(double& a, double & b);
 
int main(){
 
    auto value1{10.0};
    auto value2{20.0};
 
    double result = multiplty(value1,value2);
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
    ++result;
    std::cout << "result : " << result << " value1 : " << value1 << " value2 : " << value2<< std::endl;
 
    return 0;
}
 
auto& multiplty(double& a, double & b){
    return a*=b;
}
what will be the output?


The code won't compile -- This is  the correct Option 



Yes. You got this right! As we're trying to do return type deduction from a function return type.
The compiler needs to see the full definition and peak at your return statements before the point where the function is called.
 Our definition is showing up after the main function and compilation will fail here.
