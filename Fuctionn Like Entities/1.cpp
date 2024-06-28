/* Function pointer stores the address of another function  */


#include<iostream>
using namespace std;


int add(int a , int b )
{
    return a+b;
}

int main()
{
    int (*fun)(int , int ) = add;
      
    int c = fun(1 , 2);
    cout<<c;
    
    
}



/*CALLBACK FUNCTION */


#include<iostream>
using namespace std;


void A1()
{
    cout<<"A1 is called"<<endl;
}

void A2()
{
    cout<<"A2 is called"<<endl;
}

void B(void (*p)())
{
    (*p)();
}
int main()
{
   B(&A1);
   B(&A2);
    
}

/*OUTPUT

A1 is called
A2 is called


 */

