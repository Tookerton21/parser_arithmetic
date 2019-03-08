#include "helper.h"
#include <cstdlib> 


//checks to see if the current char is a valid Digit or not
bool Helper::isValidDig(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }
    else{
        return false;
    }
}

//The only time that we will have a negative number with parsing + and * is when 
// '-' is the first element, after +, * or ( otherwise it will be negative
bool Helper::isNeg(std::vector<char>& vec, int pos){
    //Check to see if we are looking at the first element of the char array
   if(vec[pos] == '-'){
        if(pos == 0){
            return true;
        }
        else if(vec[pos-1] == '*' || vec[pos-1] == '+' || vec[pos-1] == '('){
            return true;
        }
        else{
            return false;
        }
   }
   else{
       return false;
   } 
}

