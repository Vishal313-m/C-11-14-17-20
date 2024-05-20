// Input OUTPUT PARAMETER 

/* how we can use function parameters to get data out of the function.
Here is a simple example and we have three functions here.
We have Max, STR, Max, ent and Max double.
And you notice that we have three parameters for each of these functions.
The first two parameters are going to be input.
They are going to get data and the function.
And the third one is going to be the output parameter and it is going to get data out of the function.
Let's focus on Max STR here and really drive the point home.
The key idea here is that for the third parameter we are using a modifiable reference and if we use
a reference, the changes we do inside the function are also going to be visible on the outside.
And we explicitly left out the const that we have on the other parameters because we want to be able
to modify the output variable here inside the function.
If we marked the third parameter as const, we would get a compiler error.*/


#include <iostream>
#include <string>

void max_str(const std::string& input1, const std::string input2,
			std::string& output)
{
	if(input1 > input2){
		output = input1;
	}else{
		output = input2;
	}
}

void max_int( int input1, int input2,int& output){
	if(input1 > input2){
		output = input1;
	}else{
		output = input2;
	}
}

void max_double( double input1, double input2,double* output){
	if(input1 > input2){
		*output = input1;
	}else{
		*output = input2;
	}
}


int main(){

	std::string out_str;
	std::string string1("Cassablanca");
	std::string string2("Bellevue");

	max_str(string1,string2,out_str);
	std::cout << "max_str : " << out_str << std::endl;


   
    int out_int;
    int in1{45};
    int in2{723};
    max_int(in1,in2,out_int);
    std::cout << "max_int : " << out_int << std::endl;
    

   double out_double;
   double in_double1{45.8};
   double in_double2{76.9};
   max_double(in_double1,in_double2,&out_double);
   std::cout << "max_double : " << out_double << std::endl;
   
    return 0;
}