/* CAPTURING THE THIS POINTER */


/*In this lecture, we're going to explore some problems that might come up.
If you have a lambda function in a member function of a class and you try to use the member variables
of that class, and we're going to see solutions to that.
We will start with this simple example.
Here we have a class and this class is going to have a simple member variable which is named creatively
some member function.
Inside our member function, we're going to have a lambda function and this lambda function is going
to try and have access to the member variables of the class here.
Now some of you might go on and try to create an object of this class and try to call this member function,
but you are going to get a compiler error that says that you shouldn't really be able to access member
variables from a lambda function which is inside the class like we are doing here.
So what is wrong here?
Well, the problem is that by default a lambda function doesn't have the this pointer from the class
captured and the C plus plus compiler doesn't have a way to access this member variables because it
doesn't have access to the this pointer.
We can solve this problem by capturing the this pointer in our class and we can do something like this.
And this is going to make this work because now the compiler has access to the this pointer from the
body of this lambda function here and everything is going to fall into place.*/

#include <iostream>


class Item{
public : 

    Item(int a, int b)
        : m_var1{a}, m_var2{b}
    {}
    void some_member_func(){
		              //&
        auto func = [this](){
            std::cout << "member vars :" << m_var1 << "," << m_var2 << std::endl;
        };
        func();
    };
private : 
    int m_var1;
    int m_var2;
};


int main(){

    Item item1(10,20);
    item1.some_member_func();
    
    return 0;
}