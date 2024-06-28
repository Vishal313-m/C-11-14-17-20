/*   POINTER TO POINTER */


#include<iostream>
using namespace std;
int main()
{
    int val = 42;
    
    int *ptr = &val;
     int** ptr1 = &ptr;
     
      **ptr1 =32;
     cout<<**ptr1<<endl;
    
    
}
