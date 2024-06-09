Inline Static variable 

Motivation for inline variables 

In C++11/14, if you wanted to add a static data member to a class , you needed to declare it and define it in a corresponding cpp __FILE__

For eXAMPLE 

// A HEADER FILE 

struct OtherType{
 
 static int classCounter;
};

// Implementation CPP FILE

int OtherType::classCounter = 0;


As you can see above ,classCounter is an int and you have to write it twice: in a header file and then in the CPP File 


/*Inline static variables in C++17 allow you to define static variables within a class without needing to define them separately in a CPP file.
 This provides a more convenient and concise way to work with static class members.*/

 /*Here are the key points about inline static variables in C++17:
Initialization: You can initialize the static variable directly within the class definition, 
even with a runtime value. This eliminates the need for a separate definition in a CPP file. 

One Definition Rule: Multiple definitions of an inline static variable across different translation units are allowed,
 as the compiler will merge them into a single object in the final program. This is an exception to the One Definition Rule. 

Linkage: Inline static variables at namespace scope have external linkage by default, unlike non-inline const variables which have internal linkage.

Performance: Defining static variables inline can provide a slight performance benefit by reducing the need for separate definitions
and potentially improving inlining opportunities. However, the main advantage is the improved code organization and convenience. */



class MyClass {
public:
    MyClass() { ++num; }
    ~MyClass() { --num; }

    inline static  int num = 10;
};

int main() {
    cout << "The static value is: " << MyClass::num << endl;
    return 0;
}