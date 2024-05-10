// STATIC ASSERION 




What is static assertion?

Static assertions are a way to check if a condition is true when the code is compiled.
 If it isn’t, the compiler is required to issue an error message and stop the compiling process. The condition that needs to be checked is a constant expression.

Performs compile-time assertion checking
Syntax:
static_assert( constant_expression, string_literal ); 
How has static assertion been done prior to C++ 11 standard?

Prior to the C++ 11 standard the primary mean of producing a compile-time error message was via the #error directive,
 which causes the implementation to produce a diagnostic message that includes the message that followed it. For example:


// Static assertion using #error directive 
#include <iostream> 
using namespace std; 
#if !defined(__geeksforgeeks) 
#error "Geeksforgeeks hasn't been defined yet". 
#endif 
int main() 
{ 
    return 0; 
} 
Error: Geeksforgeeks hasn’t been defined yet.
What is the problem with #error directive?

The #error directive works well with simple tasks. However, it fails when compile time assertion needs to be 
done for complex tasks such as checking the size of a data type using the sizeof operator.
 It is because the tokens such as ‘sizeof’ are not converted to source tokens until
  after the preprocessing translation stage at which point you can no longer use preprocessing directives.

How to do static assertion since C++ 11 standard?

The C++ 11 standard introduced a feature named static_assert() which can be used to test a software assertion at the compile time.

Syntax:

static_assert( constant_expression, string_literal );  
Parameters:
constant_expression: An integral constant expression 
that can be converted to a Boolean.
string_literal: The error message that is displayed 
when the constant_expression parameter is false. 
The ‘constant_expression’ parameter represents a software assertion (a condition that you expect to be
 true at a particular point in your program) that needs to be checked during the compile time. If the condition is true, 
 the static_assert declaration has no effect. If the condition is false, the assertion fails, the compiler displays 
 the message in string_literal parameter and the compilation fails with an error. It is, however, important to note that the string_literal parameter is optional.

Example:


// CPP code to demonstrate 
// static assertion using static_assert 
#include <iostream> 
using namespace std; 
  
template <class T, int Size> 
class Vector { 
    // Compile time assertion to check if 
    // the size of the vector is greater than 
    // 3 or not. If any vector is declared whose 
    // size is less than 4, the assertion will fail 
    static_assert(Size > 3, "Vector size is too small!"); 
  
    T m_values[Size]; 
}; 
  
int main() 
{ 
    Vector<int, 4> four; // This will work 
    Vector<short, 2> two; // This will fail 
  
    return 0; 
} 
Output:

error: static assertion failed: Vector size is too small!
In the above code, we’ve created a template class named vector
 where we don’t wanna allow a vector to be created whose size is less than 4. Therefore, inside the template body,
  we put a static_assert statement to check if the vector being made is of size>3. In case of failure, 
  the assertion will fail with the error message: ” Vector size is too small”.

This is exactly what happens in the declaration of the vector class object ‘two’. The size passed to it is ‘2’,
which fails the condition to be checked, therefore producing the compile time error, and thus halting the compilation process.

What are the advantages of static_assert over #error?

Unlike #error, assertion using static_assert takes place after the preprocessing translation stage. 
Therefore, it is possible to check for the size of a datatype with sizeof using static_assert.

// Datatype 
#include <iostream> 
  
using namespace std; 
// No error produced. 
// The program compiles well because 
// the size of long datatype is 8 bytes 
static_assert(sizeof(long) == 8,  
ode relies on 'long' being exactly 8 bytes"); 
int main() 
{ 
    return 0; 
} 
Libraries can detect common usage errors at compile time.
Implementations of the C++ Standard Library can detect and diagnose common usage errors, improving usability.
Declaration Scopes

static_assert can be used in namespace scope, class scope, as well as block scope. The examples of each of the aforementioned scopes are as follows:

------------------------------------------------------Namespace scope:-----------------------------------------------

// CPP program to illustrate 
// declaring static_assert in namespace scope 
#include <iostream> 
static_assert(sizeof(void*) == 8,  
"DTAMDL(*LLP64) is not allowed for this module."); 
int main() 
{ 
    cout << "Assertion passed.  
    The program didn't produce an error"; 
    return 0; 
} 
Output:

assertion passed. The program didn't produce an error


------------------------------------------------Class scope:---------------------------------------

// CPP program to illustrate class scope in 
// static assertion using static_assert 
#include <iostream> 
using namespace std; 
  
template <class T, int Size> 
class Vector { 
    // Compile time assertion to check if 
    // the size of the vector is greater than 
    // 3 or not. If any vector is declared whose 
    // size is less than 4, the assertion will fail 
    static_assert(Size > 3, "Vector size is too small!"); 
  
    T m_values[Size]; 
}; 
  
int main() 
{ 
    Vector<int, 4> four; // This will work 
    Vector<short, 2> two; // This will fail 
  
    return 0; 
} 
Output:

error: static assertion failed: Vector size is too small!

---------------------------------Block scope:---------------------------------------------

// CPP program to illustrate 
// declaring static_assert in block scope 
template <typename T, int N> 
void f() 
{ 
    static_assert(N >= 0, "length of array a is negative."); 
    T a[N]; 
} 
int main() 
{ 
    // assertion fails here 
    // because the length of the array passed 
    // is below 0 
    f<int, -1>(); 
    return 0; 
} 
Output:

error: static assertion failed: length of array a is negative.



------------------------------Erroneous static_assert--------------------------

The constant_expression passed in static_assertion needs to be a valid expression. For example, consider the following code:

// CPP program to illustrate 
// demonstrating an erroneous static_assert declaration 
int main() 
{ 
    static_assert(1 / 0, "never shows up!"); 
    return 0; 
} 

Output:
prog.cpp:5:2: error: non-constant condition for static assertion
  static_assert(1 / 0, "never shows up!");
  ^
In the above piece of code, the expression ‘1/0‘ is not a valid constant expression.
 Therefore, When this is compiled, instead of showing the string literal in the static_assert declaration, 
 the compiler issues an error message indicating that the divisor must not be zero.