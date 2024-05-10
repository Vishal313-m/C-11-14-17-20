// CONSTANT EXPRESSIONS 

/*Constexpr is evaluated when your application is being compiled and the result of this expression is going to be stored in a  binary and reused whenever that binary 
is executed by somebody */

/*We can take some heavy computations and move them at compile time .And we use the keyword  constexpr for to say that the computation is going to be done at compile time*/


/*If possible move the potentially heavy computations at compile time */
/*The heavy computation is done once by the developer and users running the application can benefit from the results of the computation done at compile time */

/* -------  If we don't do it at compile time ,it is going to ve done every time somebody runs executable binary .and this can be bad because everybody who uses your 
application is going to pay the price for the computation */
/*It may  be a heavy computation that is going to take a lot of CPU Cycles from our program so to optimize we can move this computations ar compile time*/

/*Constant expressions is also constants ,so you can't reassign values to them */
#include <iostream>


int main(){

	constexpr int SOME_LIB_MAJOR_VERSION {1237};
	
	constexpr int eye_count {2};  // It is like a const variable ->we cannot change the value 
	
	constexpr double PI {3.14};

    //eye_count = 4;
	
	std::cout << "eye count : " << eye_count << std::endl;
	std::cout << "PI : " << PI << std::endl;


	//int leg_count {2}; // Non constexpr
	                    // leg_count is not known at compile time
	//constexpr int arm_count{leg_count}; // Error 


	constexpr int room_count{10};
	constexpr int door_count{room_count};// OK
	
	const int table_count{5};
	constexpr int chair_count{ table_count * 5};// Works


   // static_assert( SOME_LIB_MAJOR_VERSION == 123);

   // int age = 5;
   // static_assert( age == 5);

    std::cout << "App doing its thing..." << std::endl;


   
    return 0;
}


/*

Static_assert - Static assertions are a way to check if a condition is true when the code is compiled . The condition that needs to be checked is a constant expression 
   constexpr int SOME_LIB_MAJOR_VERSION {123};
 static_assert( SOME_LIB_MAJOR_VERSION == 123);

SYNTAX
static_assert(constant_expression ,message )

 Static assert is used to make assertions at compile time. When the static assertion fails, the program simply doesn't compile. 
 This is useful in different situations, like, for
  example, if you implement some functionality by code that critically depends on unsigned int object having exactly 32 bits. You can put a static assert like this

static_assert(sizeof(unsigned int) * CHAR_BIT == 32);
in your code. On another platform, with differently sized unsigned int type the compilation will fail,
 thus drawing attention of the developer to the problematic portion of the code and advising them to re-implement or re-inspect it.

For another example, you might want to pass some integral value as a void * pointer to a function (a hack, but useful at times)
 and you want to make sure that the integral value will fit into the pointer

int i;

static_assert(sizeof(void *) >= sizeof i);
foo((void *) i);
You might want to asset that char type is signed

static_assert(CHAR_MIN < 0);
or that integral division with negative values rounds towards zero

static_assert(-5 / 2 == -2);
And so on.

Run-time assertions in many cases can be used instead of static assertions, but run-time assertions only work at run-time
 and only when control passes over the assertion. For this reason a failing run-time assertion may lay dormant, undetected for extended periods of time.

Of course, the expression in static assertion has to be a compile-time constant. It can't be a run-time value.
 For run-time values you have no other choice but use the ordinary assert.



*/