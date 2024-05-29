// Decltype auto

/*And this lecture we're going to learn about Decltype Auto.
And this is a mechanism we have to avoid the duplication of our expression.
We had in the last lecture where we were using Decltype as a trailing return type. This is duplicated here.

The logic here to compute the maximum is duplicated and sometimes we don't really want this, so we
have a syntax to avoid this and all you have to do is say Decltype auto in the place of your return
type here in our function template.*/

/*
DECLTYPE AUTO Limitation :
 can't split code into declaration and definition 
*/

#include <iostream>

template <typename T, typename P> 
decltype(auto) maximum(T a, P b){
    return (a > b) ? a : b;
}


int main(){
    int x{7};
    double y{45.9};

    auto result = maximum(x,y);
    std::cout << "max : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;
   
    return 0;
}