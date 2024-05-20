The main function in C++ can take two optional parameters:

argc (argument count): This is an integer that represents the number of command-line arguments passed to the program, 
including the program name itself. For example, if you run the program with the command ./program arg1 arg2, then argc will be 3.

argv (argument vector): This is an array of strings that holds the command-line arguments. 
argv is the program name, argv[1] is the first argument, argv[2] is the second argument, and so on.
 The last element, argv[argc], is always a null pointer.


Here's a simple example to illustrate how to use these parameters:
cpp
#include <iostream>

int main(int argc, char *argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}

If you compile this program and run it with the command ./program hello world, the output will be:
Number of arguments: 3
Arguments:
./program
hello
world

The argc and argv parameters allow you to pass information to the program when it starts,
 which can be useful for things like configuration options or file paths


 -----why number of arguments here 3?


 The number of arguments is 3 because the program name itself is counted as the first argument.
Here's a breakdown of what's happening:
When you run the program with the command ./program hello world, the shell passes three arguments to the program:
./program (the program name)
hello (the first argument)
world (the second argument)

Inside the main function, argc (argument count) is set to the number of arguments passed to the program,
 including the program name itself. So, in this case, argc is 3.


The argv (argument vector) array holds the actual arguments. argv is always the program name,
 argv is the first argument, argv is the second argument, and so on. The last element, argv[argc], is always a null pointer.
So, when you run ./program hello world, the argc variable is set to 3, and the argv array looks like this:
argv = "./program"
argv = "hello"
argv = "world"
argv = nullptr (null pointer)
This is why the output shows "Number of arguments: 3" and lists the arguments as ./program, hello, and world.


