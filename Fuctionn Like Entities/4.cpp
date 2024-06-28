/*memset */


/*Answer
memset is a C++ function that copies a single character for a specified number of times to an object. It is useful for filling a number of bytes with a
 given value starting from a specific memory location. The syntax for memset is:
void* memset( void* str, int ch, size_t n);
where str is a pointer to the object to copy the character, ch is the character to copy, and n is the number of bytes to copy. The function returns a pointer to the
 destination string.
The function converts the value ch to unsigned char and copies it into each of the first n characters of the object pointed to by str. If the object is not trivially-copyable 
(e.g., scalar, array, or a C-compatible struct), the behavior is undefined. If n is greater than the size of the object pointed to by str, the behavior is undefined.
The time complexity of memset is O(N) and the auxiliary space complexity is O(1).
Here is an example of using memset in C++:
*/
C++
// C++ program to demonstrate memset
#include <cstring>
#include <iostream>
using namespace std;
int main() {
char str[] = "geeksforgeeks";
memset(str, 't', sizeof(str));
cout << str;
return 0;
}
Output:
ttttttttttttttt



Note: We can use memset() to set all values as 0 or -1 for integral data types also. It will not work if we use it to set as other values. 
The reason is simple, memset works byte by byte.
Although memset is a useful function, it is not very flexible when filling memory with different data types and value
s. The std::fill function is a better alternative available in the STL Algorithm library.*/





#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    // problem 1.
    /*int a[10]={0};
    cout<<a[5]<<endl;
    
    int b[10]={21};  // method wrong ... and luckily valid for only 0 (zero )
    cout<<b[5]<<endl;  */
    
    // problem 2.
   /* int n ; cin>>n;
    int a[n]={0};
    cout<<a[5]<<endl; */
    
    // solution of these problem
    // memset ()
    int n;
    cout<<"Input the size of array"<<endl;
    cin>>n;
    int a[n]; // block name --- a
    memset(a,0 ,sizeof(a));  // value --> 0 & -1
    cout<<a[4]<<endl;
    
    int val[9];
    memset(val, -1 , sizeof(val));
    for(int i=0;i<9;i++)
    {
        cout<<val[i]<<" ";
    }
    cout<<endl;
    
}