// Underflow vs Overflow

When we assign  a value that is out of range of the declared data type of the variable 

-> If the (absolute ) value is too big , we call it overflow 

-> If the value is to small, we call it underflow 


-128 to 127 



-128,.......-2, -1 , 0 ,1 ,2 ,.......................127

ch= -129  -> underflow                                           ch = 128 -> Overflow


// https://www.youtube.com/watch?v=JdEWCntMTN0   --IMP video
#include <iostream>

int main(){

    
    unsigned short s =0;
    std::cout << s << std::endl;
    s--;
    std::cout << s << std::endl;  // underflow  s= 65535
    
    s++;
     std::cout << s << std::endl;  //overflow s =0;



     // one more example 
     unsigned char s{55};
    s=261;  //store in more than can fit in memory :overflow
    s=-1; // store in a negative number :underflow
}



#include <iostream>

int main(){

    //Overflow 

    unsigned char data {250};

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    ++data; 
    std::cout << "data : " << std::hex <<  static_cast<int>(data) << std::endl; // 255

    ++data;  // Overflow
    std::cout << "data : " << static_cast<int>(data) << std::endl; // 256

    std::cout << std::dec ;


    data = 1;

    --data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

    --data;
    std::cout << "data : " << static_cast<int>(data) << std::endl;

   
    return 0;
}