// https://www.youtube.com/watch?v=pIzaZbKUw2s



//other LInks
//https://www.youtube.com/watch?v=0GXnfi9RAlU
//https://www.youtube.com/watch?v=Bt3zcJZIalk
//https://www.youtube.com/watch?v=PNRju6_yn3o&t=1997s



#include<iostream>
#include<utility>


void inner(int&& x)
{
    std::cout<<"Rvalue x:"<<x<<"\n";
}

void inner(int& x)
{
    std::cout<<"Lvalue x:"<<x<<"\n";
}

template <typename T>
void wrapper(T&& arg)
{
    inner(std::forward<T>(arg));
}


int main()
{
    int x=5;
    wrapper(x);    // 'x' is an Lvalue , forwarded as an Lvalue
    wrapper(50);   // '50' is an Rvalue , forwarded as an rvalue
}

/*
OUTPUT

Lvalue x: 5
Rvalue x: 50


*/