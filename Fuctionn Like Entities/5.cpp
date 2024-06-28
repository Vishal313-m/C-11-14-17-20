The memcpy() function in C and C++ is used to copy a block of memory from one location to another. Unlike other copy functions, 
the memcpy function copies the specified number of bytes from one memory location to the other memory location regardless of the type of data stored.

It is declared in <string.h> header file. In C++, it is also defined inside <cstring> header file.

Syntax of memcpy
The memcpy function is declared as:

void *memcpy(void *to, const void *from, size_t numBytes);
Parameters
to: A pointer to the memory location where the copied data will be stored.
from: A pointer to the memory location from where the data is to be copied.
numBytes: The number of bytes to be copied.
Return Value
This function returns a pointer to the memory location where data is copied.
Example of memcpy
Below is the C program to show the working of memcpy()


// C program to demonstrate working of memcpy
#include <stdio.h>
#include <string.h>
 
int main()
{
    char str1[] = "Geeks";
    char str2[] = "Quiz";
 
    puts("str1 before memcpy ");
    puts(str1);
 
    // Copies contents of str2 to str1
    memcpy(str1, str2, sizeof(str2));
 
    puts("\nstr1 after memcpy ");
    puts(str1);
 
    return 0;
}
Output
str1 before memcpy 
Geeks

str1 after memcpy 
Quiz







Important Points about memcpy()
memcpy() doesn’t check for overflow or \0.
memcpy() leads to undefined behaviour when source and destination addresses overlap.
Note: memmove() is another 