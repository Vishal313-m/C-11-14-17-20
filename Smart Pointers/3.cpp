include<iostream>
using namespace std;

template<class T>
class UniquePtr {

    private:
        T* _ptr = nullptr;


  public:
 
 //Default Constructor 
  UniquePtr() : _ptr(nullptr)
  {

  }

  // Parameterized constructor 
  explicit UniquePtr(T* ptr = nullptr) : _ptr(ptr)
  {
    cout<<"Ctor"<<endl;
  }

// Copy constructor and assignment operator are deleted
  UniquePtr(const UniquePtr& other ) = delete;
  UniquePtr& operator= (const UniquePtr& other ) = delete;


  //Move Constructor   release()- returns a pointer to the managed object and releases the ownership
   
   UniquePtr(UniquePtr&& right) : _ptr(right.release())
   {

   }
   
   template<class U>
  UniquePtr(UniquePtr<U>&& right) : _ptr(right.release())
   {

   }


// Move AssignMent operator 
 
 UniquePtr& operator= (UniquePtr&& right)
 {
    reset(right.release());
    return *this;
 }
 
 
   template<class U>
  UniquePtr& operator= (UniquePtr<U>&& right)
 {
    reset(right.release());
    return *this;
 }



   ~UniquePtr()
   {
       cout<<"destructor is called"<<endl;
    reset();
   }


  T* release()
  {
    auto oldPtr = _ptr;
    _ptr = nullptr;
    return oldPtr;
  }


  void reset(T*newPtr = nullptr)
  {
    auto oldPtr = release();
    _ptr = newPtr;
    if(oldPtr !=nullptr)
    {
        delete oldPtr;
    }
  }


    // Swap two unique_ptr objects
   void swap(UniquePtr& other)
   {
    std::swap(this->_ptr , other._ptr);
   }
   

  T* get() const {return _ptr;}

  /*This is the arrow operator that returns the raw pointer managed by the unique_ptr. It's used to access members of the managed object as if it were a regular pointer.*/
   /*unique_ptr<MyClass> ptr(new MyClass());
ptr->myMethod(); // Access a member of the managed object
*/
  T* operator->() const { return get();}


  
    // Dereference operators

    /*
    unique_ptr<int> ptr(new int(42));
     int value = *ptr; */
  T& operator* () const {return *get();}

 
 
  explicit operator bool()
  {
    return get()!= nullptr;
  }



  };
  
  class ResourceBase{
      public:
      ResourceBase()
      {
          cout<<"In ResouceBase::Constructor"<<endl;
      }
      
      virtual ~ResourceBase(){
          cout<<"In ResourceBase::Destructor"<<endl;
      }
      
      
      virtual void print()
      {
          cout<<"Base print called"<<endl;    
          }
  };
  
  
  class Resource : public ResourceBase
  {
      public:
      Resource() : ResourceBase()
      {
          cout<<"In Resource::Constructor "<<endl;
      }
      
      virtual ~Resource()
      {
          cout<<"In Resource::Destructor"<<endl;
      }
      
      virtual void print()
      {
          cout<<"Derived Print Called"<<endl;
      }
  };
  class A{
      
      inline static int object {};
      
      int myNum{};
      
      public:
      A()
      {
          myNum =++object;
          cout<<"constructing object Number "<<myNum << endl;
      }
      
      
      ~A()
      {
          cout<< "Destructing object Number "<<myNum <<endl;
      }
      
  };
  
  
  int main()
  {
      /*
      auto a1 = new A;
      UniquePtr<A> uptr{a1};
      
       auto a2 = new A;
      uptr.reset(a2);
      cout<<"Exiting MAin"<<endl;
      */
      /*
      UniquePtr<ResourceBase> uptr{new Resource};
      cout<<"Exiting Main"<<endl;
      */
      
        UniquePtr<int> ptr1(new int(2));
  }