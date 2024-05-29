//ZOOMING IN ON CONST 


/* For const objects you can only call const member functions */


/*const objects are completely non-modifiable(immutable) , the compiler won't allow calling a member function that modifies the const object in any way */


/*We are not allowed to modify the object in any way inside const member functions */


/* Just as we're not allowed  to directly modify the object inside a const member function 
we're not allowed to call a method that modifies the object indirectly either */



/* Any attempt to modify an object's member variable (direct or indirect ) from within a const member functions will result in a compiler error */


/*You cannot call any non-const memeber functions from within a const member function */