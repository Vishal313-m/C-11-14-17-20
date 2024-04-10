/* Virtual Destructor */

#include<iostream>
using namespace std;

class Animal
{
    public:
    Animal()
    {
        cout<<"Animal Constructor is Called "<<endl;
        
    }
    
    ~Animal()
    {
        cout<<"Animal Destructor is Called"<<endl;
    }
};

class Feline : public Animal
{
    public:
    Feline()
    {
        cout<<"Feline Constructor is Called "<<endl;
    }
    
    ~Feline()
    {
        cout<<"Feline Destructor is Called"<<endl;
    }
};

class Dog : public Feline
{
    public:
    Dog()
    {
        cout<<"Dog Constructor is Called"<<endl;
    }
    
    ~Dog()
    {
        cout<<"Dog Destructor is Called"<<endl;
    }
};

int main()
{
    Animal *basePtr = new Dog();
    delete basePtr;
}


/*
OUTPUT
Animal Constructor is Called 
Feline Constructor is Called 
Dog Constructor is Called
Animal Destructor is Called   


So we are going to use an animal pointer to manage a dog object like this.And when it is time to release the memory for this object, we may be tempted to call the delete operator
on our animal pointer here, but this is only going to call the destructor for the base class.

And hopefully you can see the problem here because our destructors are not virtual.The compiler is going to use static binding to decide which destructor to call.
So it is going to look at the type of our pointer.It is going to see that it is an animal pointer and it is going to decide to call the destructor for animal here.

*/


/* Virtual Destructor :- Deleting a derived class object using a pointer of base class type that has a non virtual destructor results in undefined behaviour
To Correct this situation , the base class should be defined with a virtual destructor 
*/

#include<iostream>
using namespace std;

class Animal
{
    public:
    Animal()
    {
        cout<<"Animal Constructor is Called "<<endl;
        
    }
    
   virtual  ~Animal()
    {
        cout<<"Animal Destructor is Called"<<endl;
    }
};

class Feline : public Animal
{
    public:
    Feline()
    {
        cout<<"Feline Constructor is Called "<<endl;
    }
    
    virtual ~Feline()
    {
        cout<<"Feline Destructor is Called"<<endl;
    }
};

class Dog : public Feline
{
    public:
    Dog()
    {
        cout<<"Dog Constructor is Called"<<endl;
    }
    
     ~Dog()
    {
        cout<<"Dog Destructor is Called"<<endl;
    }
};

int main()
{
    Animal *basePtr = new Dog();
    delete basePtr;
}

/*
Animal Constructor is Called 
Feline Constructor is Called 
Dog Constructor is Called
Dog Destructor is Called
Feline Destructor is Called
Animal Destructor is Called
*/