/*Rvalue REference */


/*In rvalue reference is the way to tell the compiler to not destroy the temporary value you get in your expression because
you might need to use that temporary value later throughout the execution of your C++ program*/



/* It is a way to extend the lifetime of temporary values */
/* ravlue references are marked with two ampersand && */


int x{5};
iny y{10};

int &&result = x+y; -- extended the lifetime of temporary value

std::cout<<result<<std::endl;  //15

putting a lock on a temporary value and preventing the compiler from destroying that because you need to use that later in C++ program