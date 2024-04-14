/* RAII - Resource Acquisition in initialisation */

#include<iostream>
using namespace std;

class Wrapper
{
    private:
    
    int *mem;


    public:

    Wrapper(int *a) : mem(a)
    {
        cout<<"inside ctor\n";
    }
  
    
    ~Wrapper()
    {
        cout<<"dtor\n";
        delete mem;
    }
};

int main()
{
    Wrapper obj (new int(10));

}

/*  OUTPUT 



inside ctor
dtor


Inside of writing rawpointer , I will use wrapper object . It will go inside the constructor we are initialising our raw pointer inside this constructor 
that't why resource acquistion in initialisation , when object goes out of scope , it will be deleted automatically by destructor.

*/