/* we are going to explore how we can set up a free standing non-member global operator functions and make them a friends of our class template.
That's going to be useful, especially if our operator functions need to access private data from our
class templates and we will be using the stream output operator as a use case here.

So again, the reason we are doing this is because this will give us the ability to set up a bunch of
operators and this is really something you need to do a lot.*/



ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <iostream>


//Forward declare friends : These forward declarations are needed for successful compilation on 
//all major compilers : GCC,Clang,MSVC.
template <typename T> class BoxContainer;
template <typename T> std::ostream& operator<<( std::ostream&, const BoxContainer<T>& );


template <typename T>
class BoxContainer
{
	//Good explanation on templates and friends : 
	//		: https://isocpp.org/wiki/faq/templates#template-friends
	
	//The problem
	//friend std::ostream& operator<< (std::ostream&, const BoxContainer<T>&); this will give error we are not telling that our friend func is templated func

	//Either of these solutions will need the friend function template predeclared. More info in the shared isocpp link.
	friend std::ostream& operator<< <> (std::ostream&, const BoxContainer<T>&);
	//friend std::ostream& operator<< <T> (std::ostream&, const BoxContainer<T>&);
	
	static const size_t DEFAULT_CAPACITY = 5;  
	static const size_t EXPAND_STEPS = 5;
public:
	BoxContainer(size_t capacity = DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer<T>& source);
	~BoxContainer();
	
    /*

We also have another solution, as we have seen in the slides, and that is not putting in any implementation on the outside.
So we can take this out completely and put the entire implementation inside our class definition so we can go in our class definition here 
and put in the implementation for our output stream Operator. Mind your steps. This is not going to make this guy a member function.
It is just a weird arrangement we have in C++ to have this function have access to private member
variables from an object like this so we can access m size m capacity m items directly, but this won't
have access to member variables directly without going through an object name. And this proves that this is not a regular member function.

Let's try and for example, increment M size directly and show you that this is going to give us a weird compiler error.
This is not going to work.

So let's pass this through GCC and we will have a compiler error saying that m size is not accessible
from this friend function here because it is really not a member, so you shouldn't do this.
So let's take this out.
And if we take this out and compile again, we will see that compilation is going to work fine now.

	friend std::ostream& operator<<(std::ostream& out, const BoxContainer<T>& operand)
	{
		out << "BoxContainer : [ size :  " << operand.m_size
			<< ", capacity : " << operand.m_capacity << ", items : " ;
				
		for(size_t i{0}; i < operand.m_size; ++i){
			out << operand.m_items[i] << " " ;
		}
		out << "]";
		
		return out;
	}


	*/
	

	// Helper getter methods
	/*
	size_t size( ) const { return m_size; }
	size_t capacity() const{return m_capacity;};
	
	T get_item(size_t index) const{
		return m_items[index];
	}
	*/
	
	//Method to add items to the box
	void add(const T& item);
	bool remove_item(const T& item);
	size_t remove_all(const T& item);
	//In class operators
	void operator +=(const BoxContainer<T>& operand);
	void operator =(const BoxContainer<T>& source);
private : 
	void expand(size_t new_capacity);	
private : 
	T * m_items;
	size_t m_capacity;
	size_t m_size;
	
};

//Free operators
template <typename T>
BoxContainer<T> operator +(const BoxContainer<T>& left, const BoxContainer<T>& right);


/*
template < typename T>
inline std::ostream& operator<<(std::ostream& out, const BoxContainer<T>& operand){
    
	out << "BoxContainer : [ size :  " << operand.size()
		<< ", capacity : " << operand.capacity() << ", items : " ;
			
	for(size_t i{0}; i < operand.size(); ++i){
		out << operand.get_item(i) << " " ;
	}
	out << "]";
    
    return out;
}
*/




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

template <typename T>
BoxContainer<T>::BoxContainer(const BoxContainer<T>& source)
{
	//Set up the new box
	m_items = new T[source.m_capacity];
	m_capacity = source.m_capacity;
	m_size = source.m_size;
	
	//Copy the items over from source 
	for(size_t i{} ; i < source.size(); ++i){
		m_items[i] = source.m_items[i];
	}
}

template <typename T>
BoxContainer<T>::~BoxContainer()
{
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
	T *new_items;

	// Check for self-assignment:
	if (this == &source)
            return;
/*
	// If the capacities are different, set up a new internal array
	//that matches source, because we want object we are assigning to 
	//to match source as much as possible.
	*/
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


//Definitions moved in the header

#endif // BOX_CONTAINER_H




#include <iostream>
#include "boxcontainer.h"



int main(){

    BoxContainer<int> int_box;
    int_box.add(1);
    int_box.add(2);
    int_box.add(10);
    int_box.add(15);

    std::cout << "int_box : " << int_box << std::endl;
   
    return 0;
}