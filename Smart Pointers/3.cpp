


#include<iostream>
using namespace std;

 template <typename T>
  class uniqueptr
  {

    private:
       
       T *res;



    public:
      
      uniqueptr (T* a = nullptr): res(a){
           cout<< "ctor";

      }

      uniqueptr(const uniqueptr<T>& ptr) = delete ;    // copy constructor 
      uniqueptr& operator= (const uniqueptr<T>& ptr) = delete ; // Copy assignment operator 
      
        uniqueptr(const uniqueptr<T>&& ptr)  { // Move Copy constructor 
            res = ptr.res;
            ptr.res = nullptr;
        }


       uniqueptr& operator= ( uniqueptr<T>&& ptr)  { // Move Assigment operator

            if(this ! = &ptr)
            {
                if(res){
                    delete res;
                }

            res = ptr.res;
            ptr.res = nullptr;
            }
              return *this;
        }
     

    T* operator->()
     {
        return res;
     }

    
    T& operator*()
    {
        return *res;
    }

          T* get()
        {
            return res;
        }

        void reset(T* newres = nullptr)
        {
            if(res){
                delete res;
            }
            res = newres;

        }

     ~uniqueptr(){
        cout<<"dtor\n";
        if(res)
        {
            delete res;
            res = nullptr;
        }
     } 
       
  };

  int main()
  {
         uniqueptr<int> ptr1(new int(2));
         //uniqueptr<int> ptr2(ptr1);  // Compilation error
        // uniqueptr<int> ptr3 = ptr1; // Compilation error
         uniqueptr<int> ptr4(new int(500));
         //ptr4=ptr3;  // Compilation error
         uniqueptr<int> ptr3 = std::move(ptr1);
         //ptr4 = std::move(ptr1);


        // ptr1->func();
         cout<< *(ptr1);
         ptr1.get();
         ptr1.reset(new int(30));


  }