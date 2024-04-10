/* POLYMORPHIC FUNCTIONS AND DESTRUCTORS */

/* DON'T CALL VIRTUAL(POLYMORPHIC) FUNCTIONS FROM CONSTRUCTORS AND DESTRUCTORS  */

#include <iostream>
class Base
{
public:
    Base()
    {
        std::cout << "Base constructor called" << std::endl;
    
    }
    virtual ~Base(){
        std::cout << "Base destructor called" << std::endl;
    }
    virtual void setup()
    {
        std::cout << "Base::setup() called" << std::endl;
        m_value = 10;
    }
    virtual void clean_up(){
        std::cout << "Base::clean_up() called" << std::endl;
    }
    int get_value()
    {
        return m_value;
    }
protected:
    int m_value;
};

class Derived : public Base
{
public:
    Derived()
        : Base()
    {
        std::cout << "Derived constructor called" << std::endl;
    }
    virtual ~Derived(){
        std::cout << "Derived destructor called" << std::endl;
    }

    virtual void setup() override
    {
        std::cout << "Derived::setup() called" << std::endl;
        m_value = 100;
    }
    virtual void clean_up() override{
        std::cout << "Derived::clean_up() called" << std::endl;
    }
};

int main(){

    Base * p_base = new Derived;
    delete p_base;
}

/*
Constructor and destructor call order 


Base constructor called
Derived constructor called
Derived destructor called
Base destructor called
*/

/*
 I want you to think about the order in which constructors and destructors are going to be called.
We have touched on this subject before and we are going to revisit this because it is really important
in terms of calling virtual functions in Destructors and Destructors.

So when we do something like this, the base part of this object is going to be built first. So we are going to call the base constructor first.
We're going to set up the base part of us. After that, we're going to set up the derived part of us and we're going to call the derived constructor.
And after the derived part of us is set up, we can use our object like we do always. So we're going to use our object to do whatever it is we want to do.

When the time comes for this object to be destroyed, we're going to destroy the derived part first,
and then we're going to destroy the base part first.Now that we have considered this order, try to think about the setup.

When we call a virtual function from a constructor, that's what we're going to look at First, the base constructor is going to be called, 
but notice that by the time we call the base constructor, the derived part of us won't be set up yet.
So if we try to call a virtual function in the base constructor, they want to be a derived part to call the most specialized method for.
So the compiler will notice that we don't have a derived part yet. We will be at this stage building the base part, and if we call a virtual polymorphic function, we
want the most specific part to be called, which should live in the derived part.
But we haven't done the derived part yet. We are still building the base part of us.
So the compiler is going to notice that we don't have a derived part and it is going to call the base version of our virtual function.

That's why we say that if you call a virtual function from a constructor or a destructor, you're going
to get static binding results.If you call a virtual function, you want the most specific version called, But we don't have that
yet in the base part because the derived part haven't been set up. That's why we get static binding results.
*/

/* LIKE THIS ---*/
#include <iostream>
class Base
{
public:
    Base()
    {
        std::cout << "Base constructor called" << std::endl;
        this->setup(); // Static binding
    }
    virtual ~Base(){
        std::cout << "Base destructor called" << std::endl;
    }
    virtual void setup()
    {
        std::cout << "Base::setup() called" << std::endl;
        m_value = 10;
    }
    virtual void clean_up(){
        std::cout << "Base::clean_up() called" << std::endl;
    }
    int get_value()
    {
        return m_value;
    }
protected:
    int m_value;
};

class Derived : public Base
{
public:
    Derived()
        : Base()
    {
        std::cout << "Derived constructor called" << std::endl;
    }
    virtual ~Derived(){
        std::cout << "Derived destructor called" << std::endl;
    }

    virtual void setup() override
    {
        std::cout << "Derived::setup() called" << std::endl;
        m_value = 100;
    }
    virtual void clean_up() override{
        std::cout << "Derived::clean_up() called" << std::endl;
    }
};


int main(){

    Base * p_base = new Derived;
    auto value = p_base->get_value();
   std::cout<<" Value :"<<value<<std::endl;

}

/*
OUTPUT
Base constructor called
Base::setup() called
Derived constructor called
Value :10
*/


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* To call the derived version we do Like this */

#include <iostream>
class Base
{
public:
    Base()
    {
        std::cout << "Base constructor called" << std::endl;
    }
    virtual ~Base(){
        std::cout << "Base destructor called" << std::endl;
    }
    virtual void setup()
    {
        std::cout << "Base::setup() called" << std::endl;
        m_value = 10;
    }
    virtual void clean_up(){
        std::cout << "Base::clean_up() called" << std::endl;
    }
    int get_value()
    {
        return m_value;
    }
protected:
    int m_value;
};

class Derived : public Base
{
public:
    Derived()
        : Base()
    {
        std::cout << "Derived constructor called" << std::endl;
    }
    virtual ~Derived(){
        std::cout << "Derived destructor called" << std::endl;
    }

    virtual void setup() override
    {
        std::cout << "Derived::setup() called" << std::endl;
        m_value = 100;
    }
    virtual void clean_up() override{
        std::cout << "Derived::clean_up() called" << std::endl;
    }
};


int main(){

    Base * p_base = new Derived;

    p_base->setup();

    auto value = p_base->get_value();
    std::cout << "value : " << value <<  std::endl; // 100

    p_base->clean_up();

    delete p_base;
   
    return 0;
}

/*
OUTPUT
Base constructor called
Derived constructor called
Derived::setup() called
value : 100
Derived::clean_up() called
Derived destructor called
Base destructor called



*/