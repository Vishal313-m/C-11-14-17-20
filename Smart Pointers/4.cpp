/* Unique pointers as function Parameters and return values */
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

class Person
{
public:
    Person(std::string name) : m_name{name}{
    }

    ~Person()
    {
        
    }
    
 void adopt_dog( std::unique_ptr<Dog> dog){
    std::cout << m_name << " just adopted the dog " << dog->get_name() << std::endl;
    }
private : 
    int m_age;
    std::string m_name;
};


void do_something_with_dog_v1( std::unique_ptr<Dog> d){
    d->print_info() ;
}


void do_something_with_dog_v2( const std::unique_ptr<Dog>& d){
    d->set_dog_name("Rior");
    d->print_info();
   // d.reset(); // Compiler error
}


std::unique_ptr<Dog> get_unique_ptr(){
    std::unique_ptr<Dog> p_dog = std::make_unique<Dog>("Function Local");
	std::cout << "unique_ptr address(in) : " << &p_dog << std::endl;
    return p_dog;  // The compiler does some optimizations and doesn't return a copy here
					// it's returning something like a reference to the local object.
					// We can prove this by looking at the address of objects in memory.
					// This is not standard behavior, some compilers may actually return 
					// by value by making a copy. The compilers have some freedom to choose
					// their own way to do things.
}

int main(){

 /*
	//Passing unique ptr to functions by value
	std::unique_ptr<Dog> p_dog_1 = std::make_unique<Dog>("Dog1");
    
	//Can't pass unique_ptr by value to a function : copies not allowed
    //do_something_with_dog_v1(p_dog_1);   // copy detected,


	do_something_with_dog_v1(std::move(p_dog_1)); // Ownership will move to the body
												// of the function and memory will be
												// released when function returns.
												// Not what you typically want.

    std::cout << "p_dog_1 : " << p_dog_1.get() << std::endl; 
    std::cout << "Hitting back the main function" << std::endl;

    
   ------- OUTPUT-------

Constructor for dog Dog1 called.
Dog [ name : Dog1 ]
Destructor for dog Dog1 called
p_dog_1 : 0
Hitting back the main function


*/

    std::cout << "------" << std::endl;
/*
    std::unique_ptr<Dog> p_dog_1 = std::make_unique<Dog>("Dog1");

    
    Person person1("John");
    person1.adopt_dog(std::move(p_dog_1)); // The same behavior when function is part of the class
    std::cout << "Doing something , p_dog_1 points to :  " <<p_dog_1.get() <<  std::endl;
    

----------------OUTPUT----------------
Constructor for dog Dog1 called.
John just adopted the dog Dog1
Destructor for dog Dog1 called
Doing something , p_dog_1 points to :  0

*/
 std::cout << "------" << std::endl;

/*
	//An implicit move is done when object is created in place as a temporary
	do_something_with_dog_v1(std::make_unique<Dog>("Temporary Dog"));


  ----------------  OUTPUT-------------------
Constructor for dog Temporary Dog called.
Dog [ name : Temporary Dog ]
Destructor for dog Temporary Dog called


*/

std::cout << "------" << std::endl;
//---------------------------------------------------------------------------
    /*
	//Can pass the std::unique_ptr parameter by reference.
	std::unique_ptr p_dog_2 = std::make_unique<Dog>("Dog2");
	p_dog_2->print_info();
	do_something_with_dog_v2(p_dog_2);
	std::cout << "-----" << std::endl;
	p_dog_2->print_info();



    OUTPUT 
Constructor for dog Dog2 called.
Dog [ name : Dog2 ]
Dog [ name : Rior ]
-----
Dog [ name : Rior ]
Destructor for dog Rior called
    */


//---------------------------------------------------------------------------
	//Returning unique ptr from function by value
/*
	std::unique_ptr<Dog> p_dog_3 = get_unique_ptr();
	std::cout << "delimiter" << std::endl;
	std::cout << "unique_ptr address(out) : " << &p_dog_3 << std::endl;

	 p_dog_3->print_info();


-------------- OUTPUT------------------------
Constructor for dog Function Local called.
unique_ptr address(in) : 0x7ffe32707d00
delimiter
unique_ptr address(out) : 0x7ffe32707d00
Dog [ name : Function Local ]
Destructor for dog Function Local called
*/


/*

    get_unique_ptr()->print_info();

    std::cout << "function done" << std::endl;

-----------OUTPUT-----------------------

Constructor for dog Function Local called.
unique_ptr address(in) : 0x7ffe2f3137b0
Dog [ name : Function Local ]
Destructor for dog Function Local called
function done
	
*/

   
    return 0;
}
