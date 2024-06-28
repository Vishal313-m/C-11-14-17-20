//Implement Shared Ptr


#include<iostream>
using namespace std;

template<typename T>
class sharedptr
{


  private:
        T* res;
        int* counter;
       
       void incrementcounter()
       { 
           if(counter){
             (*counter)++; 
             }
       }

       void decrementcounter()
       {
          
          if(counter){
            (*counter)--;
    

    /*If we do a substraction what if countrer value is zero ,Suppose two object is pointing to the same resource ,
    one object is started pointing to someone else ,now only one object remaining , this also went so its counter become zero  so what will happen to that particular resource, it should get deleted */
            if((*counter)==0){     //  
                if(res){
                    delete res;
                    delete counter;
                    res = nullptr;
                    counter = nullptr;
                }
            }
          }
       }

  public:
       //default constructor 
       shared(T*ptr = nullptr): res(ptr), counter(new int(1))
       {
             cout<<"Ctor was called\n";
       }


    // copy Constructor 
       sharedptr<T>(const shared<T> &ptr)
       {
          res= ptr.res;
          counter = ptr.counter;
          incrementcounter();
       }

   //Copy assignment operator 

   sharedptr<T>& operator=(const sharedptr<T>& ptr){

     if(this!=&ptr){
        decrementcounter();
        res=ptr.res;
        counter = ptr.counter;
        
     }
     return *this;
   }

    // Move Constructor 
       sharedptr<T>(shared<T>&&ptr)
       {
          res= ptr.res;
          counter = ptr.counter;
          ptr.res = nullptr;
          ptr.counter = nullptr;

       }
 
       
       //Move assignment operator 

   sharedptr<T>& operator=(const sharedptr<T>&& ptr){

     if(this!=&ptr){
        decrementcounter();
        res=ptr.res;
        counter = ptr.counter;
         ptr.res = nullptr;
         ptr.counter = nullptr;
     }
     return *this;
   }

   
   void reset(T*ptr){
    decrementcounter();
    res = ptr;
    counter = new int(1);
   }


   int get_count(){
    
     if(counter){
        return (*counter);
     }
     return -1;
   }

   T* operator->(){
    return res;
   }

   T& operator*(){
    return (*res);
   }
  
    T* get(){
         return res;
    }

    ~sharedptr(){
        decrementcounter();
    }
}


int main()
{
    sharedptr<int> ptr1; //defualt ctor 

    shared<int> ptr2(new int(10)); //parameterized ctor 

    sharedptr<int> ptr3(ptr2);  // Copy Constructor 

    ptr3 = ptr2;   // Copy Assignment Operator 

    sharedptr<int> ptr4(std::move(ptr1)); // Move Copy Constructor 

    ptr2 = std::move(ptr3);     // Move Copy Assignment Operator 


   ptr1.reset();

   ptr1.reset(new int(6));

   cout<<(*ptr1);  // Implementing *operator 

   ptr1->func(); // Implementing -> operator 

   ptr1.get();  // It will give a raw pointer 

   ptr1.get_count(); // Number of objects pointing to the same resource 

   //dtor
}