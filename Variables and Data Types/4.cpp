
C++ Type Modifiers
In C++ programming, type modifiers are used to change the meaning of the fundamental data types.

There are four type modifiers in C++:

short
long
signed
unsigned
Here's a brief summary:

Data Type	     Size (in Bytes)            	Meaning
signed int	    4	                            Used for integers (equivalent to int).
unsigned int	4	                            Can only store non-negative integers.
short	         2	                            Used for small integers. Range: -32768 to 32767
long	      at least 4	                    Used for large integers. Equivalent to long int.
unsigned long	   4	                        Used for large positive integers or 0. Equivalent to unsigned long int.
long long	       8	                        Used for very large integers. Equivalent to long long int.
unsigned long long	  8	                        Used for very large positive integers or 0. Equivalent to unsigned long long int.
long double	          8	                        Used for large floating-point numbers.
signed char	        1	                         Used for characters.  Guaranteed range -127 to 127.
unsigned char	      1	                        Used for characters. Range 0 to 255. 




- short type Modifier
We can use short for small integers (in the range −32,767 to 32,767). For example,

// small integer
short a = 12345;
Here, a is a short integer variable.

Note: short is equivalent to short int.

- long Type Modifier
If we need to store a large integer (in the range -2147483647 to 2147483647), we can use the type specifier long. For example,

// large integer 
long b = 123456;
Note: long is equivalent to long int.

The long type modifier can also be used with double variables.

// large floating-point number 
long double c = 0.333333333333333333L;
Note: To indicate long double, we use the L suffix. If we do not use the suffix L, it's a double value that is converted to long double (which may result in data loss).

-  long long
long can be repeated twice to create the long long type. This type is used for even larger numbers than long. long long type modifier can only be used with int.

For example,

// long long int
long long num = 12345678;


- signed and unsigned Modifiers

Signed variables can hold both positive and negative integers including zero. For example,

// positive valued integer 
signed int x = 23;

// negative valued integer
signed int y = -13;

// zero-valued integer
signed int z = 0;
Here,

x holds a positive-valued integer
y holds a negative-valued integer
z holds a zero-valued integer
Note:

By default, integers are signed. Hence instead of signed int, we can directly use int.
signed and unsigned can only be used with int and char types.
The unsigned variables can hold only non-negative integer values. For example,

// positive valued integer
unsigned int x = 2;
unsigned int y = 0;
Here,

x holds a positive-valued integer
y holds zero
In general, an int variable can store a range of values from -2,147,483,648 to 2,147,483,647.

Whereas an unsigned int variable can store a range of values from 0 to 4,294,967,295.


- signed, unsigned and plain char
C++ has 3 different char types:

char
signed char
unsigned char
In practice, there are basically only 2 types:

signed char (guaranteed range: -127 to 127)
unsigned char (guaranteed range: 0 to 256)
This is because different compilers treat char as either signed char or unsigned char according to their own preference.

Notes:

In in standard C++, char is not the same as signed char or unsigned char. The compilers ignore this for practicality.
When we only use char instead of its signed or unsigned variants, this type is known as plain char.
As you might have guessed, signed char can store both positive and negative integers, while unsigned char can only store positive integers (including 0).

// plain char
char plain_1 = 65;
char plain_2 = 0;

// plain char with negative value
// might cause problems with some compilers
char plain_3 = -56;

// signed char
signed char  sin_1 = 12;
signed char  sin_2 = 0;
signed char  sin_3 = -12;

// unsigned char
unsigned char  unsin_1 = 85;
unsigned char  unsin_2 = 0;
Here,

plain_1 holds a positive-valued integer
plain_2 holds a zero-valued integer
sin_1 holds a positive-valued integer
sin_2 holds a zero-valued integer
sin_3 holds a negative-valued integer
unsin_1 holds a positive-valued integer
unsin_2 holds a zero-valued integer
Note: It is preferable not to use plain char to perform numerical manipulations; signed char or unsigned char should be used for that instead. Plain char should only be used to store character values.