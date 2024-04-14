/* Unique Pointer and Arrays */

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
/*
     //Array allocated on the stack
     
     {
        std::cout << "Working with dog array on the stack" << std::endl;
        Dog dog_array[3] {Dog("Dog1"), Dog("Dog2") , Dog("Dog3")};
        for( size_t i {0}; i < 3 ; ++i){
            dog_array[i].print_info();
        }

     }

OUTPUT 
Constructor for dog Dog3 called.
Dog [ name : Dog1 ]
Dog [ name : Dog2 ]
Dog [ name : Dog3 ]
Destructor for dog Dog3 called
Destructor for dog Dog2 called
Destructor for dog Dog1 called
 
*/

/*
     //Array allocated on the heap
     
     {
        Dog * p_dog_array_raw = new Dog[3]{Dog("Dog4"), Dog("Dog5") , Dog("Dog6")};
     
        for( size_t i {0}; i < 3 ; ++i){
            p_dog_array_raw[i].print_info();
        }
        
        //If we don't delete explicitly like below. Have the line commented out, the memory
        //for the array won't be released and we won't see the destructors for Dogs 4~6 called.
        //If we delete explicitly, everything goes as expected and the destructors are called
        //when we exit this scope.
     
        delete[] p_dog_array_raw;
     }

OUTPUT
Constructor for dog Dog4 called.
Constructor for dog Dog5 called.
Constructor for dog Dog6 called.
Dog [ name : Dog4 ]
Dog [ name : Dog5 ]
Dog [ name : Dog6 ]
Destructor for dog Dog6 called
Destructor for dog Dog5 called
Destructor for dog Dog4 called

 */


/*
     //Array allocated on the heap with unique_ptr. Releases space for array automatically
     {
        auto arr_ptr = std::unique_ptr<Dog[]> ( new Dog[3]{Dog("Dog7"), Dog("Dog8") , Dog("Dog9")});
		
       // auto arr_ptr = std::make_unique<Dog[]>(3);// Works. Can't initialize individual elements
        //auto arr_ptr = std::make_unique<Dog[]>(3) {Dog("Dog7"), Dog("Dog8") , Dog("Dog9")};//Compiler error
        //auto arr_ptr = std::make_unique<Dog[]>{Dog("Dog7"), Dog("Dog8") , Dog("Dog9")};//Compiler error

        for (size_t i{0} ; i < 3 ; ++i){
            arr_ptr[i].print_info() ;
        }
         
     }


     std::cout << "Done!" << std::endl
     


OUTPUT 
Constructor for dog Dog7 called.
Constructor for dog Dog8 called.
Constructor for dog Dog9 called.
Dog [ name : Dog7 ]
Dog [ name : Dog8 ]
Dog [ name : Dog9 ]
Destructor for dog Dog9 called
Destructor for dog Dog8 called
Destructor for dog Dog7 called
Done!



OUTPUT --- Line 107 uncomment
Dog [ name : Puffy ]
Dog [ name : Puffy ]
Dog [ name : Puffy ]
Destructor for dog Puffy called
Destructor for dog Puffy called
Destructor for dog Puffy called
Done!



     */
	
   
    return 0;
}
