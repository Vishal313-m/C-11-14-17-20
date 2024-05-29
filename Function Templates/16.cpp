//C++ 20 CONCEPTS 

/* A Mechanism to place constraints on your template type parameters */

/*Concepts are a mechanism we can use to set up constraints or restrictions on the template parameters in our function templates.
For example, we can use this technique to say that we want our function to be only called with integers,
and if you call it with something that isn't an integer, it's going to give you a compiler error.*/



/*

void print_number( T n){
    //static_assert(std::is_integral<T>::value ,"print_number() can only be called with integral types" );
    static_assert(std::is_integral_v<T> ,"print_number() can only be called with integral types" );
    std::cout << "number : " << n << std::endl;
}


We have just said that we use them to place constraints on our template parameters, but we saw that
we could do something like that in the last chapter where we could use type traits and staticassert,
for example, if you look at the function here, it's going to print a number, but we have a requirement
for this number to be an integral type through the staticassert that we have here, we're going to see
that we can do something really similar with concepts, but it's going to be much cleaner and that the
logic to enforce our constraints is not going to be in the function body.

It's going to be somewhat in the function declaration, in the constraints that we put on the template parameter here.

*/

/*There are two sides to concepts in C plus plus there are standard built in concepts that come with the C plus plus programming language.
But if for some reason these happen not to be enough, you can build your own */


#include <iostream>
#include <concepts>

//Syntax1

template <typename T>
requires std::integral<T>
T add( T a, T b){
    return a + b;
}


//Syntax2

template <std::integral T>
T add( T a, T b){
    return a + b;
}


//Syntax3

auto add(std::integral auto a , std::integral auto b){
    return a + b;
}


//Syntax4
template <typename T>
T add( T a, T b) requires std::integral<T>{
    return a + b;
}

int main(){

   
	char a_0{10};
	char a_1{20};
	
	auto result_a = add(a_0,a_1);
	std::cout << "result_a : " << static_cast<int>(result_a) << std::endl;
	
	int b_0{11};
	int b_1{5};
	auto result_b = add(b_0,b_1);
	std::cout << "result_b : " << result_b << std::endl;


	double c_0 {11.1};
	double c_1 {1.9};
	auto result_c = add(c_0,c_1);
    std::cout << "result_c : " << result_c << std::endl;
 
  
    return 0;
}