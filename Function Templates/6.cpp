// Function Template with multiple parameters 

/*
Mysterious Return type 

template <typename T , typename P> problematic_maximum(T a , P b)

So here you see we have two template parameters T and P, and we can use this in any way we want in our function declaration.

For example, here we have our function called problematic maximum, and it is going to take two template parameters.

The first one is going to be of type T, the second one is going to be of type P, and the compiler
is going to automatically deduce this from the parameters we try to call this function with.

But before we really see how we can call this function template, there is a problem.
So what's going to be the return type of this function template if we do things like this?

You notice I have left the return type empty on purpose because this is a problem and now we have a
few options, but most of them are going to be problematic.
One way we can do this is to return one of these template parameters as the return type, and this is the syntax we could use to do this.



template <typename T , typename P> P problematic_maximum(T a , P b)


But the problem is that now our return type depends on the order of the parameters in our function call. The return type is basically the second parameter here.

And if our function, for example, is called with INT and double, this is going to return double if
we call it with double and N, it is going to return and this is clearly bad design and we don't want something like this.

If you switch and return t, this is really not going to solve the problem.It's just going to change the order of the parameters.

We need a better solution.
*/



/*One way we can solve this is to set up a separate template parameter for the return type.
And now we can set up a function like this.

A better approach :Separate parameter for return type 

template <typename ReturnType , typename T , typename P>
ReturnType maximum(T a , P b )
{
    return (a>b)?a:b;
}
It's going to deduce T and P based on what we call our maximum function width.
It's going to deduce the return type based on the type of this expression we are doing in the function body.


With this set up here, we can try and call our maximum function. And here is a simple example.

A better approach : Explicit template arguments 

int max1 = maximum<int ,char,long>('c',12L)
std::cout << "max1 :" << max1 <<std::endl;


int max2 = maximum<int ,char>('d',12L)
std::cout << "max2 :" << max2 <<std::endl;



int max3 = maximum<int>('e' ,14L);
std::cout << "max3 :" << max2 <<std::endl;


So we're going to specify our return type as INT and T and P are going to be automatically deduced to be char and long here in the second call.
The return type is also going to be INT and we're going to specify the second parameter which is probably T in our function declaration.



int max4 = maximu('f' ,15L);  //  Compiler error:The compiler doesn't know how to deduce the return type 

*/





/*
The order of the arguments matters 

template <typename ReturnType , typename T , typename P>

//Possible calls 

int max1 = maximum<int , char , long>('c' ,12L);           //OK
int max2 = maximum<int ,char>('d',12L);                    //OK
int max3 = maximum<int>('e',14L);                          //OK
int max4 = maximum<int>('f' ,14L);                         //Error : return type can't be deduced






template<typename T , typename ReturnType , typename P >

//Possible Calls

int max1 = maximum<char, int,long>('c',12L);                 //OK
int max2 = maximum<char,int>('d',12L);                       //OK
int max3 = maximum<char>('e',14L);                           // Error : return type can't be deduced 
int max4 = maximum<char>('f',14L);                           //Error : return type can't be deduced 




template<typename T, typename P , typename ReturnType>

//Possible Calls

int max1 = maximum<char,long , int>('c',12L);                 //Ok
int max2 =maximum<char,long>('d',12L);                        //Error::return type can't be deduced
int max3 = maximum<char>('e',14L);                            //Error::return type can't be deduced
int max4 = maximum('f',14L);                                  //Error::return type can't be deduced             
*/


#include <iostream>

/*
//Problematic : return depends on the order of the template arguments : BAD!
template <typename T , typename P> 
P   maximum( T a, P b){
    return ((a > b) ? a : b);
}
*/

template <typename ReturnType, typename T , typename P> 
//template < typename T,typename ReturnType , typename P> 
//template < typename T, typename P,typename ReturnType > 
ReturnType   maximum( T a, P b){
    return ((a > b) ? a : b);
}


int main(){

    int a {5};
    double b{6.7};

    auto result = maximum <int>(a,b);
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl; 
    
    return 0;
}