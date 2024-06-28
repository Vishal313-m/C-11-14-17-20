/*Capture BY VALUE UNDER THE HOOD */

/*In this lecture, we are going to explore how capturing by value works under the hood for Lambda functions.
And we already know that lambda functions are modeled by using functors behind the scenes.
So this is really not going to be hard to understand.
Suppose we have a lambda function here which is going to be capturing by value and we are going to explicitly
capture A and B for use in the body of our lambda function.
You see, we have access to A and B here, but they are going to be captured by a value.
And what we have inside our lambda function here are really going to be copies of things we have onthe outside.

So we have our lambda function here, we can call it with ten and 20 and ten and 20 are going to be
our parameters that we pass to this lambda function here.
So we will have copies of them in the body and we will print them out as we see down here.

Now, once we set up this lambda function behind the scenes, the compiler is going to generate a functor,
which is going to really capture the data and store copies in member variables that we set up in our
functor here.
So we will set up a bunch of member variables that are going to store whatever it is we have captured
in our Lambda functions.
And the data is going to be passed in the parameters of the constructor that is going to be called when
the compiler creates an object of this functor here and everything is going to fall in place.
We can even improve this by using CP insights and seeing what the compiler generates behind the scenes.
But this is really the idea here, so we can even capture everything using the syntax we have here.
And what this is going to do.
This is going to set up a bunch of member variables which are going to store copies of the things that
we have captured.
One thing you should know is that we will only set up member variables for things we use in the body
of our lambda function.
You see, we have captured everything, but we want to set up a member variable to capture some other
var or some var here because they are not used in the body of our lambda function here.
So you should really know this.
If you capture everything, the compiler is only going to set up a member variables for the things you
actually use in the body of your lambda function.
Another thing I want to bring to your attention is that by default, we don't have the ability to modify
the data that we have captured in our lambda function by value.*/


#include <iostream>


int main(){

    int a{7};
    int b {3};
    int some_var{28};// Not captured by the [=] lambda, so it won't set up a member var 
                    // for this
    double some_other_var{55.5}; // Not captured by the [=] lambda, so it won't set up 
                                // a member var for this.

    //Capturing  everything by value 
    auto func = [=] (int c, int d)  {
        std::cout << "Captured values : " << std::endl;
        std::cout << "a : " << a << std::endl;
        std::cout << "b : " << b  << std::endl;
        
        std::cout << std::endl;
        
        std::cout << "Parameters : " << std::endl;
        std::cout << "c : " << c << std::endl;
        std::cout << "d : " << d << std::endl;
    };
    func(10,20);

    std::cout << "----" << std::endl;
    func(20,30);
   
    return 0;
}




/*
CPPINSIGHTS 


#include <iostream>

int main()
{
  int a = {7};
  int b = {3};
  int some_var = {28};
  double some_other_var = {55.5};
    
  class __lambda_14_17
  {
    public: 
    inline constexpr  void operator()(int c, int d) const
    {
      std::operator<<(std::cout, "Captured values : ").operator<<(std::endl);
      std::operator<<(std::cout, "a : ").operator<<(a).operator<<(std::endl);
      std::operator<<(std::cout, "b : ").operator<<(b).operator<<(std::endl);
      std::cout.operator<<(std::endl);
      std::operator<<(std::cout, "Parameters : ").operator<<(std::endl);
      std::operator<<(std::cout, "c : ").operator<<(c).operator<<(std::endl);
      std::operator<<(std::cout, "d : ").operator<<(d).operator<<(std::endl);
    }
    
    private: 
    int a;
    int b;
    
    public:
    __lambda_14_17(int & _a, int & _b)
    : a{_a}
    , b{_b}
    {}
    
  };
  
  __lambda_14_17 func = __lambda_14_17{a, b};
  func.operator()(10, 20);
  std::operator<<(std::cout, "----").operator<<(std::endl);
  func.operator()(20, 30);
  return 0;
}










*/