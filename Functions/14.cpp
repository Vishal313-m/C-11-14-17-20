// DEfault Arguments 


#include <iostream>

void compute( int age = 27 , double weight = 72.4, double distance = 12.5);
void greet_teacher(std::string_view name_sv = "teacher" , int homeworks =12,
    int exams = 4, double pass_rate = 0.5, std::string_view first_dpmt = "Computer Sce");


int main(){

    //compute();

	//Call and use default arguments
    greet_teacher();
    greet_teacher("Mr Bean");
    greet_teacher("Mr Hamston",7);
    greet_teacher("Mr Walker",7,3);
    greet_teacher("Mr Paku",7,3,0.7);
    greet_teacher("Mr Kojo",7,3,0.7,"Applied Mathematics");

   
    return 0;
}

void compute( int age   , double weight , double distance  ){
	std::cout << "Doing computations on age : " << age 
		<< " weight : " << weight 
		<< " and distance : " << distance << std::endl;
}

void greet_teacher(std::string_view name_sv,int homeworks,
                    int exams, double pass_rate, std::string_view first_dpmt){
    std::cout << std::endl;
    std::cout << "Good morning " << name_sv << "!" << std::endl;
    std::cout << "In the past semester, we had " << homeworks << " homeworks, and "
                << exams << " exams. The pass rate was around : " << pass_rate << std::endl;
    std::cout << "The best performing department is : " << first_dpmt << std::endl;
}

/*

OUTPUT 


Good morning teacher!
In the past semester, we had 12 homeworks, and 4 exams. The pass rate was around : 0.5
The best performing department is : Computer Sce

Good morning Mr Bean!
In the past semester, we had 12 homeworks, and 4 exams. The pass rate was around : 0.5
The best performing department is : Computer Sce

Good morning Mr Hamston!
In the past semester, we had 7 homeworks, and 4 exams. The pass rate was around : 0.5
The best performing department is : Computer Sce

Good morning Mr Walker!
In the past semester, we had 7 homeworks, and 3 exams. The pass rate was around : 0.5
The best performing department is : Computer Sce

Good morning Mr Paku!
In the past semester, we had 7 homeworks, and 3 exams. The pass rate was around : 0.7
The best performing department is : Computer Sce

Good morning Mr Kojo!
In the past semester, we had 7 homeworks, and 3 exams. The pass rate was around : 0.7
The best performing department is : Applied Mathematics








*/