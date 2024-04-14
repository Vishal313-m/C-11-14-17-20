/* SHARED POINTERS WITH ARRAYS */

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

	//C++17 only : Recommended
	std::shared_ptr<int[]> shared_ptr_int_arr_1( new int[10]{1,2,3,4,5,6,7,8});
	std::shared_ptr<Dog[]> shared_ptr_dog_arr_1( new Dog[10]{Dog("Dog1"),Dog("Dog2")});


	//Setting elements
	shared_ptr_int_arr_1[3] = 28;
	shared_ptr_dog_arr_1[1] = Dog("Fluzzy");

	//Read int array
	std::cout << std::endl;
	std::cout << "Reading data from arrays" << std::endl;
	std::cout << "Reading shared_ptr_int_arr_1: " << std::endl;
	for(size_t i{0}; i < 10 ; ++i){
		std::cout << "shared_ptr_int_arr_1[" << i << "] : " << shared_ptr_int_arr_1[i] << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Reading shared_ptr_dog_arr_1: " << std::endl;
	for(size_t i{0}; i < 10 ; ++i){
		std::cout << "shared_ptr_dog_arr_1[" << i << "] : " << shared_ptr_dog_arr_1[i].get_name() << std::endl;
	}
   
    return 0;
}


/*
OUTPUT
Constructor for dog Dog1 called.
Constructor for dog Dog2 called.
Constructor for dog Fluzzy called.
Destructor for dog Fluzzy called

Reading data from arrays
Reading shared_ptr_int_arr_1: 
shared_ptr_int_arr_1[0] : 1
shared_ptr_int_arr_1[1] : 2
shared_ptr_int_arr_1[2] : 3
shared_ptr_int_arr_1[3] : 28
shared_ptr_int_arr_1[4] : 5
shared_ptr_int_arr_1[5] : 6
shared_ptr_int_arr_1[6] : 7
shared_ptr_int_arr_1[7] : 8
shared_ptr_int_arr_1[8] : 0
shared_ptr_int_arr_1[9] : 0

Reading shared_ptr_dog_arr_1: 
shared_ptr_dog_arr_1[0] : Dog1
shared_ptr_dog_arr_1[1] : Fluzzy
shared_ptr_dog_arr_1[2] : Puffy
shared_ptr_dog_arr_1[3] : Puffy
shared_ptr_dog_arr_1[4] : Puffy
shared_ptr_dog_arr_1[5] : Puffy
shared_ptr_dog_arr_1[6] : Puffy
shared_ptr_dog_arr_1[7] : Puffy
shared_ptr_dog_arr_1[8] : Puffy
shared_ptr_dog_arr_1[9] : Puffy
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Fluzzy called
Destructor for dog Dog1 called




*/