#include "equation.h"
#include <cstdlib> 
#include "utility.h"

//Constructor no parameters
Equation::Equation(){
    pos = 0;
}

//Allow parsing multiple string for equation
int Equation::parseStr(string str){
    //Reset all vars to 0 and parse string 
    pos = 0;
    
    //Collect the convert vector to 
    Utility::stringToVec(str, vec);

    return sum();
}

//Gets the digit of the equation 
int Equation::getDig(){
    
   //Safety that wont execute if if we are out of the boundaries of the vector
   if (pos >= vec.size()){
       return 0;
   }
   
   //If we are in a parenthesis we calculate everything inside of the parenthesis
    else if(vec[pos] == '('){
        ++pos;//consume the left parenthesis
        int num = sum();//calculate the sum 
        ++pos; //increment past the close parenthesis
        return num;
    }

    
    //Ensure that the digit is a valid number [0-9], along with check if the number is neg && increment pos to move to the next position
    else if((vec[pos] >= '0' && vec[pos] <= '9') || Utility::isNeg(vec, pos)){
        int num = number();
         return num;
    } 
   
   //if the its an invalid then cout a message and return 0;
    else{
        cout<<"expected A digit" << endl;
       return 0;
    }
}

//calculate the product of the equation
int  Equation::product(){
    int num1 = getDig(); //get the digit of the first number

    //look for the second number if one for multiplication
    while(vec[pos] == '*'){
        pos++;
        int num2 = product();
        num1 *= num2;
    }

    return num1;
}

//calculate the sum of the equation
int Equation::sum(){
    int num1 = product(); //get the first number

    while(vec[pos] == '+'){ //find the second number for addition if one
        ++pos;
        int num2 = product();
        num1 += num2;
    }
 
    return num1;
}

//find the number in the vector, used to find multi-digit numbers
int Equation::number(){
   char temp[12];
   int start = pos;
   int end = start;

    while((vec[pos] >= '0' && vec[pos] <= '9') || Utility::isNeg(vec, pos)){
        ++end;
        ++pos;
    }
    //Test to see that the number is within the constraints of the temp array if not just return 0
    if(end-(start+1) > 12){
        std::cout << "Number is too large!!" << endl;
        return 0;
    }
    else {
        std::copy(vec.begin() + start, vec.begin() + end, temp);
    }
    int num =  atoi(temp);
    temp[0] = '\0';

    return num;
}
