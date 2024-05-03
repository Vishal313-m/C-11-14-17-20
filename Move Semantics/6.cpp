/* Passing by rvalue reference */

/*If by any chance , an rvalue happens to be assigned a name , it's treated by the compiler as if it's an LVALUE.In other words , if its assigned or copy assigned from 
,the copy constructor or the copy assignment operator will be called */


/*If by any chance you assign a name to your Rvalue, the Rvalue is going to be treated by the compiler
as a Lvalue because by design or by definition, an L value is something that has a name and that
you can grab the address of and use some kind of pointer or reference to manage it.

So the moment something has a name in your C++ program, if and if that happens to be an Rvalue,
that's going to become a Lvalue.

And you need to be careful about this.
If you give a name to your lvalue and try to pass it to functions or do whatever you are going to be doing a copy semantics.*/

#include<iostream>

class Item{
    friend std::ostream& operator<<( std::ostream& out, const Item& operand);
public : 
    Item() : m_data{new int} {
    }
    Item(int value) : m_data{new int(value)}{
    }
    //Copy Members
    Item( const Item& source) : m_data{new int}{
        std::cout << "Item copy constructor copying data..." << std::endl;
        *m_data =(*source.m_data);
    }
    Item& operator=(const Item& right_operand){
        std::cout << "Item copy assignment operator copying data..." << std::endl;
        if (&right_operand != this){
            
            *m_data =(*right_operand.m_data);
        }
        return *this;
    }
    
    //Move Members
    Item( Item&& source){
        std::cout << "Item move constructor moving data..." << std::endl;
        //Steal the pointer
        m_data = source.m_data;
        
        //Reset the source pointer
        source.m_data = nullptr;
    }
    Item& operator=(Item&& right_operand){
        std::cout << "Item move assignment operator moving data..." << std::endl;
        if (&right_operand != this){
            
            //Steal the pointer
            m_data =right_operand.m_data;
            
            //Reset the source pointer
            right_operand.m_data = nullptr;
        }
        return *this;
    }
private : 
    int * m_data{nullptr};
};

std::ostream& operator<<( std::ostream& out, const Item& operand){
    out << "Item : [" << (*operand.m_data) << "]";
    return out;
}


Item get_value(){
    return Item(22);
}


void do_something( Item&& item){
    std::cout << "Do something move version called..." << std::endl;
   //Item internal = item;
    Item internal = std::move(item);
   std::cout << "internal : " << internal << std::endl;
}



int main(){

	/*

	Item&& rvalue_ref {get_value()};

    Item item1;
    item1 = rvalue_ref   // copy assignment operator called ,rvalue_ref temporary has a name , compiler treated it as an Lvalue


	item1= std::move(rvalue_ref);  // calls the move assignment operator 

	std::cout << "-------" << std::endl;

    */

    
    
    /*
    //Passing to a function 

     Item&& rvalue_ref {get_value()};
     do_something(rvalue_ref); // compiler error ,can't pass an Lvalue . Again ,our temporary has a name ,its treated like an Lvalue and can't 
                                 be passed where an rvalue is expected . hence the error




	do_something(std::move(rvalue_ref));


  */
    return 0;
}