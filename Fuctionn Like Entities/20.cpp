/*std::function is simply a wrapper that lets you store the callable object ->(The callable object is anything that we can call like a function ) 

for example - lambda function , functor ,  a normal function these are all callable */



/*1 - BASIC USAGE */

#include<iostream>
#include<functional>


void foo(int x)
{
    std::cout<< x<< std::endl;
}

int main()
{
    std::function<void(int)> f= foo;
    f(5);
}




/*2- std::function with lambdas*/

#include<iostream>
#include<functional>



int main()
{
    std::function<void(int)> f= [](int x){ std::cout<< x << std::endl; };

   // auto foo = [](int x){ std::cout<< x << std::endl; }; // deduce in compile time

    f(5);
}





/* 3- std::function with functor */


#include<iostream>
#include<functional>


int main()
{     
    struct S
    {
        void operator ()(int x)
        {
            std::cout << x <<std::endl;
        }
    };

    S s;
    std::function<void(int)> f= s;
    f(5);
}





/* 4- std::function as a parameter in a function  */



#include<iostream>
#include<functional>


void foo( std::function<void(int)> func)
{
    func(5);
}

int main()
{
    auto lambda = [](int x){ std::cout<< x << std::endl; };

    foo(lambda);


}


/*Another use of std::function is to create a containers that can store callable objects  */

#include<iostream>
#include<vector>
#include<functional>
using namespace std;

int main()
{
    vector<function<void(int)>>  vf;

    vf.push_back([](int x){ std::cout<< x << std::endl; });
    vf.push_back([m=5](int x){ std::cout<<  m << x << std::endl; });

    vf[0](5);
    vf[1](10);
/*
output
5

5 10

*/
}








/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/



#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <iostream>

template <typename T>
class BoxContainer
{
	friend std::ostream& operator<< <T> (std::ostream&, const BoxContainer<T>&);
	
	static const size_t DEFAULT_CAPACITY = 5;  
	static const size_t EXPAND_STEPS = 5;

public:
    BoxContainer(size_t capacity = DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer<T>& source);
	BoxContainer(BoxContainer&& source); // Move constructor
	~BoxContainer();

	// Helper getter methods
	size_t size( ) const { return m_size; }
	size_t capacity() const{return m_capacity;};
	
	T& get_item(size_t index) const{
		return m_items[index];
	}
	
	//Method to add items to the box
	void add(const T& item);
    void add(T&& item); // Move version of the add method
	bool remove_item(const T& item);
	size_t remove_all(const T& item);
    
	//In class operators
	void operator +=(const BoxContainer<T>& operand);
	void operator =(const BoxContainer<T>& source) ; // Copy assignment operator
	void operator=(BoxContainer<T>&& source); // Move assignment operator

private : 
	void expand(size_t new_capacity);	
   
    void invalidate(){
        m_items = nullptr;
        m_size =0;
        m_capacity =0;
    }
 
private : 
    T * m_items;
    size_t m_capacity;
    size_t m_size;
};

//Free operators
template <typename T>
BoxContainer<T> operator +(const BoxContainer<T>& left, const BoxContainer<T>& right);

// definition
template<typename T>
std::ostream& operator<<(std::ostream& out, const BoxContainer<T>& operand)
{
	out << "BoxContainer : [ size :  " << operand.m_size
		<< ", capacity : " << operand.m_capacity << ", items : " ;
			
	for(size_t i{0}; i < operand.m_size; ++i){
		out << operand.m_items[i] << " " ;
	}
	out << "]";
    
    return out;
}


//Definitions moved into here
template <typename T>
BoxContainer<T>::BoxContainer(size_t capacity)
{
	m_items = new T[capacity];
	m_capacity = capacity;
	m_size =0;
}


//Copy constructor
template <typename T>
BoxContainer<T>::BoxContainer(const BoxContainer<T>& source)
{
	std::cout << "BoxContainer copy constructor called. Copying " 
			<< source.m_size << " items..." << std::endl;
	//Set up a new box
	m_items = new T[source.m_capacity];
	m_capacity = source.m_capacity;
	m_size = source.m_size;
	
	//Copy the items over from source 
	for(size_t i{} ; i < source.size(); ++i){
		m_items[i] = source.m_items[i];
	}
}


//Move constructor
template <typename T>
BoxContainer<T>::BoxContainer(BoxContainer&& source){

    // Check for construction from self:
    if (this == &source)
            return;
            
    m_items = source.m_items;
    m_size = source.m_size;
    m_capacity = source.m_capacity;
    
    //Remember to invalidate source
    source.invalidate();
}

template <typename T>
BoxContainer<T>::~BoxContainer()
{
	std::cout << "BoxContainer object destroyed" << std::endl;
	delete[] m_items;
}


template <typename T>
void BoxContainer<T>::expand(size_t new_capacity){
	std::cout << "Expanding to " << new_capacity << std::endl;
	T *new_items_container;

	if (new_capacity <= m_capacity)
		return; // The needed capacity is already there
	
	//Allocate new(larger) memory
	new_items_container = new T[new_capacity];

	//Copy the items over from old array to new 
	for(size_t i{} ; i < m_size; ++i){
		new_items_container[i] = m_items[i];
	}
	
	//Release the old array
	delete [ ] m_items;
	
	//Make the current box wrap around the new array
	m_items = new_items_container;
	
	//Use the new capacity
	m_capacity = new_capacity;
}

template <typename T>
void BoxContainer<T>::add(const T& item){
	if (m_size == m_capacity)
		//expand(m_size+5); // Let's expand in increments of 5 to optimize on the calls to expand
		expand(m_size + EXPAND_STEPS);
	m_items[m_size] = item;
	++m_size;
}

template <typename T>
void BoxContainer<T>::add( T&& item){
    std::cout << "Move version of add called..." << std::endl;
    if (m_size == m_capacity)
        expand(m_size + EXPAND_STEPS);
    //m_items[m_size] = item;
    m_items[m_size] = std::move(item);
    ++m_size;    
}


template <typename T>
bool BoxContainer<T>::remove_item(const T& item){
	
	//Find the target item
	size_t index {m_capacity + 999}; // A large value outside the range of the current 
										// array
	for(size_t i{0}; i < m_size ; ++i){
		if (m_items[i] == item){
			index = i;
			break; // No need for the loop to go on
		}
	}
	
	if(index > m_size)
		return false; // Item not found in our box here
		
	//If we fall here, the item is located at m_items[index]
	
	//Overshadow item at index with last element and decrement m_size
	m_items[index] = m_items[m_size-1];
	m_size--;
	return true;
}


//Removing all is just removing one item, several times, until
//none is left, keeping track of the removed items.
template <typename T>
size_t BoxContainer<T>::remove_all(const T& item){
	
	size_t remove_count{};
	
	bool removed = remove_item(item);
	if(removed)
		++remove_count;
	
	while(removed == true){
		removed = remove_item(item);
		if(removed)
			++ remove_count;
	}
	
	return remove_count;
}

template <typename T>
void BoxContainer<T>::operator +=(const BoxContainer<T>& operand){
	
	//Make sure the current box can acommodate for the added new elements
	if( (m_size + operand.size()) > m_capacity)
		expand(m_size + operand.size());
		
	//Copy over the elements
	for(size_t i{} ; i < operand.m_size; ++i){
		m_items [m_size + i] = operand.m_items[i];
	}
	
	m_size += operand.m_size;
}

template <typename T>
BoxContainer<T> operator +(const BoxContainer<T>& left, const BoxContainer<T>& right){
	BoxContainer<T> result(left.size( ) + right.size( ));
	result += left; 
	result += right;
	return result;	
}



template <typename T>
void BoxContainer<T>::operator =(const BoxContainer<T>& source){
		std::cout << "BoxContainer copy assignment operator called. Copying " 
			<< source.m_size << " items..." << std::endl;
	T *new_items;

	// Check for self-assignment:
	if (this == &source)
            return;

	// If the capacities are different, set up a new internal array
	//that matches source, because we want object we are assigning to 
	//to match source as much as possible.

	if (m_capacity != source.m_capacity)
	{ 
	    new_items = new T[source.m_capacity];
	    delete [ ] m_items;
	    m_items = new_items;
	    m_capacity = source.m_capacity;
	}
	
	//Copy the items over from source 
	for(size_t i{} ; i < source.size(); ++i){
		m_items[i] = source.m_items[i];
	}
	
	m_size = source.m_size;
}


//Move assignment operator
template <typename T>
void BoxContainer<T>::operator=(BoxContainer&& source){
    
    std::cout << "BoxContainer move assignment operator called. Moving " 
            << source.m_size << " items..." << std::endl;	
    // Check for self assignment
    if (this == &source)
            return;
    
    m_items = source.m_items;
    m_size = source.m_size;
    m_capacity = source.m_capacity;
    
    //Remember to invalidate source
    source.invalidate();
}


//Definitions moved in the header

#endif // BOX_CONTAINER_H






/*main.cpp*/


#include <iostream>
#include <functional>
#include "boxcontainer.h"


//Function pointer
char encrypt(const char& param){
    return static_cast<char> (param + 3);
}

//Functor
class Decrypt
{
public:
    char operator()( const char& param){
         return static_cast<char> (param - 3);
    }
};


//Modifying a BoxContainer of strings
BoxContainer<std::string>& modify(BoxContainer<std::string>& sentence,
                                        //char(*modifier) (const char&)){
                                  std::function<char(const char&)> modifier){
    for(size_t i{}; i < sentence.size() ; ++i){
            
        //Code below relies on get_item() to return a reference
        //Loop through the word modifying each character 
        for(size_t j{} ; j < sentence.get_item(i).size(); ++j){
            sentence.get_item(i)[j] = modifier(sentence.get_item(i)[j]);
        }
    }
    return sentence;
}

std::string get_best (const BoxContainer<std::string>& sentence,
        // bool(*comparator)(const std::string& str1, const std::string& str2)){
        std::function<bool(const std::string& str1,const std::string& str2)> comparator){

    std::string best = sentence.get_item(0);
    for(size_t i{}; i < sentence.size() ; ++i){
            
        if(comparator(sentence.get_item(i),best)){
            best = sentence.get_item(i);
        }
            
    }
        
    return best;
}

//Function pointer
bool larger_in_size (const std::string& str1, const std::string& str2){
    if(str1.size() > str2.size())
        return true;
    else 
        return false;
}


int main(){

    //Basic usage of std::function : storing function like entities
    //in a unified way.
    std::function<char(const char&)> my_modifier;

    //Function pointer
    my_modifier = encrypt;
    std::cout << "A encrypted becomes : " << my_modifier('A') << std::endl; // D

    //Functor
    Decrypt decrypt;
    my_modifier = decrypt;
    std::cout << "D decrypted becomes : " << my_modifier('D') << std::endl;


    //Lambda function
    my_modifier = [](const char& param){
        return static_cast<char> (param + 3);
    };
    std::cout << "A encrypted becomes : " << my_modifier('A') << std::endl; // D



    std::cout << "--------" << std::endl;

    //Storing function like entities in a collection
    std::cout << std::endl;
    std::cout << "Collection of function like entities : " << std::endl;
    
    BoxContainer<std::function<char(const char&)>> func_entities;
    func_entities.add(encrypt); // Function pointer
    func_entities.add(decrypt); // Functor
    func_entities.add([](const char& param){ // Lambda function
        return static_cast<char> (param + 3);
    });
    
    for(size_t i{}; i < func_entities.size() ; ++i){
        std::cout << "result " << i << ". D transformed becomes : " << 
                func_entities.get_item(i)('D') << std::endl;
    }


    std::cout <<"--------" << std::endl;

    //std::function as callback 
    std::cout << std::endl;
    std::cout << "Modifying the quote : " << std::endl;
    BoxContainer<std::string> quote;
    quote.add("The");
    quote.add("sky");
    quote.add("is");
    quote.add("blue");
    quote.add("my");
    quote.add("friend");
    std::cout << "Initial : " <<  quote << std::endl;
    std::cout << "Encrypted : " << modify(quote,encrypt) << std::endl;
    std::cout << "Decrypted : " << modify(quote,decrypt) << std::endl;


    std::cout << "----------" << std::endl;

    std::cout << std::endl;
    std::cout << "Gettting the best : " << std::endl;
    
    auto  greater_lexicographically = [](const std::string& str1, const std::string& str2){
    return (str1>str2);
    };
    
    std::cout << "larger in size : " << get_best(quote,larger_in_size) << std::endl;
    std::cout << "greater lexicographicaly : " 
            << get_best(quote,greater_lexicographically) << std::endl;



  
    
    return 0;
}