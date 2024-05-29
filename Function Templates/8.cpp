// DECLTYPE AND TRAILING RETURN TYPES 

/*decltype
decltype is used to deduce the type of an expression. It allows you to extract the type of a variable, object, or literal without evaluating the expression. */


/*Trailing Return Type
The trailing return type syntax allows you to specify the return type of a function after the parameter list, using the auto keyword followed by -> 
and the return type. This syntax is especially helpful when the return type depends on the function parameters or when using decltype.


template<typename T, typename U>
auto add(const T& lhs, const U& rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}*/

/*But if we are using Decltype as a trailing return type, this is going to allow us to split our code
into declaration and definition.*/

#include <iostream>

//Declaration
template <typename T, typename P>
auto maximum( T a, P b) -> decltype((a > b)? a : b) ;

int main(){

    //declytpe
    int a {9};
	double b{15.8};
	
                                                //Largest type is going to be deduced as return type
    /*                                          |    |     |
	std::cout << "size : " << sizeof(decltype((a > b)? a : b)) << std::endl;//4


    So if we look at the variables we have in here, A is of type INT and B is of type double. So B is larger.
    This is going to be deduced to be the type of double and we can use this expression to declare other variables.

    decltype((a > b)? a : b) c {7}; // Declaring other variables through declytype
    std::cout << "c : " << c << std::endl;
    std::cout << "sizeof(c) : " << sizeof(c) << std::endl; // 4
    */

   auto result = maximum(a,b);
   std::cout << "result : " << result << std::endl;
   std::cout << "sizeof(result) :" << sizeof(result) << std::endl;
    
    return 0;
}

//Definition
template <typename T, typename P>
auto maximum( T a, P b) -> decltype((a > b)? a : b) {
    return (a > b)? a : b;
}