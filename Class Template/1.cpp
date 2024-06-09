// CLASS TEMPLATE 

/* - All member function definition moved into the header file ,the compiler needs to see them
there to generate proper template instances */

/* - Operator << set up as an non friend free standing global function .At the  moment we don't have enough tools to deal with problems that could pop up 
if we used our good streamInsertable interfaces which be friends global  operator <<*/

/*  Operator << is no longer a friend, so it will access BoxContainer private data through public helper getter methods*/


/* A template is only instantiated once , it is reused every time the type is needed in  your code */

/* Template instance is created for a given type  only once and Only methods that are used are instantiated */

/* Also , all the class members are inline by default ,so we are safe from ODR issues if the template header is included in many files */ // Go and check on cppinsights 


#ifndef BOX_CONTAINER_H
#define BOX_CONTAINER_H

#include <iostream>

template <typename T>
class BoxContainer 
{
	static const size_t DEFAULT_CAPACITY = 5;  
	static const size_t EXPAND_STEPS = 5;
public:
	BoxContainer(size_t capacity  = DEFAULT_CAPACITY);
	BoxContainer(const BoxContainer& source);
	~BoxContainer();

	// Helper getter methods
	size_t size( ) const { return m_size; }
	size_t capacity() const{return m_capacity;};
	
	T get_item(size_t index) const{
		return m_items[index];
	}
	
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
	size_t m_capacity{10};
	size_t m_size;
};

//Free operators
template <typename T>
BoxContainer<T> operator +(const BoxContainer<T>& left, const BoxContainer<T>& right);

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



/* CPP File */

#include "boxcontainer.h"


/*main */

include <iostream>
#include "boxcontainer.h"



class Point{
    friend std::ostream& operator<<(std::ostream& out, const Point& operand);
    public : 
    Point(double x, double y) : m_x(x) , m_y(y){
        
    }
    //The default constructor must be there for bags of Points to be able
    //initializable with the new T[] statement in the BoxContainer<T> constructor.
    Point() : m_x(0.0), m_y(0.0){  
    }
    
private : 
    double m_x{};
    double m_y{};
};

std::ostream& operator<<(std::ostream& out, const Point& operand){
    out << "Point [ x : " << operand.m_x << ",y : " << operand.m_y << "]";
    return out;
}


int main(){

	//int
	std::cout << "BoxContainer of int : " << std::endl;
	BoxContainer<int> int_box;
	int_box.add(33);
	int_box.add(44);
	std::cout << "int_box : " << int_box << std::endl;
	
	//double
	std::cout << std::endl;
	std::cout << "BoxContainer of double : " << std::endl;
	BoxContainer<double> double_box;
	double_box.add(100.11);
	double_box.add(200.22);
	std::cout << "double_box : " << double_box << std::endl;
	
	//Point
	std::cout << std::endl;
	std::cout << "BoxContainer of Point : " << std::endl;
	BoxContainer<Point> point_box;
	point_box.add(Point(20.1,20.2));
	point_box.add(Point(200.22,300.33));
	std::cout << "point_box : " << point_box << std::endl;
	
	//std::string
	std::cout << std::endl;
	std::cout << "BoxContainer of std::string" << std::endl;
	BoxContainer<std::string> string_box;
	string_box.add("Hello");
	string_box.add("World");
	std::cout << "string_box : " << string_box << std::endl;
	
	//char
	std::cout << std::endl;
	std::cout << "BoxContainer of char" << std::endl;
	BoxContainer<char> char_box;
	char_box.add('H');
	char_box.add('e');
	char_box.add('l');
	char_box.add('l');
	char_box.add('o');
	char_box.add('o');
	std::cout << "char_box : " << char_box << std::endl;

	//------------------------------------------------------

    std::cout << std::endl;
	std::cout << "Trying out all the methods: " << std::endl;
	
	BoxContainer<int> int_box1;
	int_box1.add(10);
	int_box1.add(21);
	int_box1.add(44);
	
	std::cout << "int_box1 : " << int_box1 << std::endl;
	
	int_box1.add(10);
	int_box1.add(55);
	int_box1.add(10);
	std::cout << "int_box1 : " << int_box1 << std::endl;
	
	int_box1.remove_item(55);
	std::cout << "int_box1 : " << int_box1 << std::endl;
	
	size_t removed = int_box1.remove_all(10);
	std::cout << removed  << " items removed" << std::endl;
	std::cout << "int_box1 : " << int_box1 << std::endl;
	
	//Copy construct
	std::cout << std::endl;
	std::cout << "Copy construction" << std::endl;
	BoxContainer<int> int_box2(int_box);
	std::cout << "int_box : " << int_box << std::endl;
	std::cout << "int_box2 : " << int_box2 << std::endl;
	
	//Copy assign
	std::cout << std::endl;
	std::cout << "Copy assignment" << std::endl;
	int_box2 = int_box1;
	std::cout << "int_box1 : " << int_box1  << std::endl;
	std::cout << "int_box2 : " << int_box2 << std::endl;
	
	std::cout << std::endl;
	std::cout << "operator+= : " << std::endl;
	int_box2 += int_box; 
	std::cout << "int_box : " << int_box  << std::endl;
	std::cout << "int_box2 : " << int_box2 << std::endl;
	
	
	std::cout << std::endl;
	std::cout << "operator+" << std::endl;
	BoxContainer<int> int_box3;
	int_box3.add(100);
	int_box3.add(200);
	
	BoxContainer<int> int_box4;
	int_box4 = int_box2 + int_box3;
	std::cout << "int_box4 : " << int_box4 << std::endl;

	std::cout << "END." << std::endl;


    return 0;
}