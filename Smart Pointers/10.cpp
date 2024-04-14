/* WEAK PTR - If we say unique_ptr is for unique ownership and shared_ptr is for shared ownership then weak_ptr is for non- ownership smart pointer */
/* It actually won't participate the ownership of the  object */
/* It actually reference to an object which is managed by shared ptr */


/*std::weak_ptr is a smart pointer in C++ that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr*/

#include<iostream>
#include<memory>

class Dog 
{
    
    public:
    
   Dog(std::string name_param) : dog_name(name_param){
    std::cout << "Constructor for dog " << dog_name << " called." << std::endl;
   }

    
     Dog() = default;
     
     
    
    ~Dog(){
    std::cout << "Destructor for dog " << dog_name << " called" << std::endl;;
    }
    
    
     std::string get_name() const{
        return dog_name;
    }
    
    void set_dog_name(const std::string & name){
        dog_name = name;
    }
	
	void print_info() const{
		std::cout << "Dog [ name : " << dog_name << " ]" <<  std::endl;
	}
    
private:
    std::string dog_name {"Puffy"};
    
    
    
};
int main(){

	//Playing with basic use of weak_ptr

    std::shared_ptr<Dog> shared_ptr_dog_1 = std::make_shared<Dog>("Dog1");
    std::shared_ptr<int> shared_ptr_int_1 = std::make_shared<int>(200);
    
    std::weak_ptr<Dog>  weak_ptr_dog_1 (shared_ptr_dog_1);
    std::weak_ptr<int>  weak_ptr_int_1 (shared_ptr_int_1);
       
       
     std::cout << "weak_ptr_dog_1.usecount : " << weak_ptr_dog_1.use_count() << std::endl;
     std::cout << "weak_ptr_int_1.usecount : " << weak_ptr_int_1.use_count() << std::endl;
     
     std::cout << "shared_ptr_dog_1.usecount : " << shared_ptr_dog_1.use_count() << std::endl;
     std::cout << "shared_ptr_int_1.usecount : " << shared_ptr_int_1.use_count() << std::endl;

    // No * , or -> operators you would expect from regular pointers
    //std::cout << "weak_ptr_dog_1 use count : " << weak_ptr_dog_1.use_count() << std::endl;
    /*
    std::cout << "Dog name : " << weak_ptr_dog_1->get_name() << std::endl; // Compiler error : No -> operator
    std::cout << "Pointed to value : " << *weak_ptr_int_1 << std::endl; // Compiler error : No * operator
    std::cout << "Pointed to address : " << weak_ptr_dog_1.get() << std::endl; // No get method
    */


	// To use a weak ptr you have to turn it into a shared_ptr with the lock method
	std::cout << std::endl;
    std::shared_ptr<Dog> weak_turned_shared = weak_ptr_dog_1.lock();
    std::cout << "weak_turned_shared use count : " << weak_turned_shared.use_count() << std::endl;
    std::cout << "Dog name : " << weak_turned_shared->get_name() << std::endl;
	std::cout << "Dog name : " << shared_ptr_dog_1->get_name() << std::endl;
/*
output

Constructor for dog Dog1 called.
weak_ptr_dog_1.usecount : 1
weak_ptr_int_1.usecount : 1
shared_ptr_dog_1.usecount : 1
shared_ptr_int_1.usecount : 1

weak_turned_shared use count : 2
Dog name : Dog1
Dog name : Dog1
Destructor for dog Dog1 called

*/
}


/* USE CASES OF WEAK PTR --  CYCLIC DEPENDENCY */
#include<iostream>
#include <memory>
#include <string>

class Person
{
public:
    Person() = default;
  
    Person(std::string name) : m_name{name} {
    std::cout << "Constructor for person  " << m_name << " called." << std::endl;
  }

    ~Person() {
    std::cout << "Destructor for person  " << m_name << " called." << std::endl;
   }
    
    //Member functions
    void set_friend(std::shared_ptr<Person> p){
		//The assignment creates a weak_ptr out of p
        m_friend = p;
    }
    
private : 
    std::shared_ptr<Person> m_friend; // Initialized to nullptr
    std::string m_name {"Unnamed"};
};

int main()
{   //Cycling dependency problem
	//Circular dependencies
	std::shared_ptr<Person> person_a = std::make_shared<Person>("Alison");
    std::shared_ptr<Person> person_b = std::make_shared<Person>("Beth");
    
    person_a->set_friend(person_b);
    person_b->set_friend(person_a);
	
    /*
    OUTPUT
    Constructor for person  Alison called.
   Constructor for person  Beth called.    
    */
    
    return 0;
}




/*let's talk about where it is used, because we have seen that you can't really use it to access the data that is pointed to.
You can't use the dereference operator or the pointer access operator. So there must be some use for the weak pointer.

And the main purpose of creating this type in C plus plus is to solve a problem referred to as cyclic dependency problem.
And to explain that problem, we're going to look at this class here.The class is called person.

And if you go down in the member variables, you're going to see that we have a member variable which
is going to store the name for the person, but we also have a shared pointer to person, which is going
to be pointing to the friend of this person object here.

So once we have a class like this, we can create objects of this class so we can create the first object
to be person A It is what you see here and we're going to use STD make shared to allocate space on the heap.

The name is going to be Alison and we're going to create a second person object, which is going to
be person B, the name is going to be Beth, as you see here.
And then we are going to say to person B to be the friend of person A, as you see here, and we're
going to set up person A to be the friend of person B, So this is the setup we do. So the situation here we're going to.

You have person A pointing to person B, and we're going to have person B pointing to person A. This is going to give us the situation we see here.
So person A, the name is going to be Alison. They are going to have a shared pointer member variable, which is going to be pointing to person B
and we're going to have a person, B whose name is going to be Beth and they are going to have a shared
pointer member variable, which is going to be pointing to person A.

The problem is going to come when these two guys are about to be released from memory.
So the C plus plus runtime is going to try and deallocate a person B, for example, when it tries to
do that, it's going to find that we have a person, A who is still pointing to person B, This is going
to prevent the reference count from decrementing all the way to zero to cause for person B to be released
from memory.

So the person B shared pointer is going to go out of scope. So this is going to be destroyed.

But what is pointed to is not going to be destroyed.This thing is going to stay in memory.
So the C plus plus time is going to leave this and then it's going to be turn for person A to be released
from memory.
And when the compiler tries to delete this, it's going to find that we still have a pointer pointing to person A here.
So the reference count is not going to go down to zero because somebody is still pointing to person A here.

So the pointer itself is going to go out of scope. But the data that we are pointing to in memory is not going to be released.
So the program is going to end and we will be leaking the memory for person A and person B here.
This is the problem we might have if we try and use shared pointers as member variables for our person class here.

So the problem is we have a member variable which is going to code for the reference count to be incremented 
if this guy is still around and that the reference count is never going to decrement all the way to zero.

And we're going to leak memory our pointers that we have on the next slide right here. So we are going to see the pointers here are going to go out of scope.
They are going to be destroyed, but the data on the heap is not going to be destroyed.

It's going to stay there and we are just going to leak this memory because we are using a shared pointer member variable. I hope this makes sense.
And one way to solve this problem is to change your class and change the member variable to be of weak
pointer type and not share the pointer type because this weak pointer is not going to be incrementing the reference count.

We're not going to have the same problem here.
The reference count is going to be decremented all the way to zero and we're not going to leak memory.
The destructors are going to be called for person and the problem is going to go away.*/


#include<iostream>
#include <memory>
#include <string>

class Person
{
public:
    Person() = default;
  
    Person(std::string name) : m_name{name} {
    std::cout << "Constructor for person  " << m_name << " called." << std::endl;
  }

    ~Person() {
    std::cout << "Destructor for person  " << m_name << " called." << std::endl;
   }
    
    //Member functions
    void set_friend(std::shared_ptr<Person> p){
		//The assignment creates a weak_ptr out of p
        m_friend = p;
    }
    
private : 
    std::weak_ptr<Person> m_friend; // Initialized to nullptr
    std::string m_name {"Unnamed"};
};

int main()
{
    //Cycling dependency problem
	//Circular dependencies
	std::shared_ptr<Person> person_a = std::make_shared<Person>("Alison");
    std::shared_ptr<Person> person_b = std::make_shared<Person>("Beth");
    
    person_a->set_friend(person_b);
    person_b->set_friend(person_a);
	
    /*
    OUTPUT 
Constructor for person  Alison called.
Constructor for person  Beth called.
Destructor for person  Beth called.
Destructor for person  Alison called.

    */
    
    return 0;
}