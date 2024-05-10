static_cast
The static_cast operator is the most commonly used casting operator in C++. It performs compile-time type conversion and is mainly used for explicit conversions
 that are considered safe by the compiler. 

Syntax of static_cast
static_cast <new_type> (expression);
where,

expression: Data to be converted.
new_type: Desired type of expression
The static_cast can be used to convert between related types, such as numeric types or pointers in the same inheritance hierarchy.



Example of static_cast
C++
// C++ program to illustrate the static_cast
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{

    int num = 10;

    // converting int to double
    double numDouble = static_cast<double>(num);

    // printing data type
    cout << typeid(num).name() << endl;

    // typecasting
    cout << typeid(static_cast<double>(num)).name() << endl;

    // printing double type t
    cout << typeid(numDouble).name() << endl;

    return 0;
}

Output
i
d
d

In this example, we have included the “typeinfo” library so that we can use typeid() function to check the data type. We have defined an integer variable
 ‘num’ and converted it into a double using static_cast. After that, we print the data types of variables and pass static_cast<double>(num) in typeid() function to check its 
 data type. we can see the output “i, d, d” is printed where ‘i’ denotes integer and ‘d’ denotes double.