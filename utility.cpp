#include "utility.h"

void Utility::stringToVec(std::string str, std::vector<char>& vec){
    //if the vector has data in it erase the vector before we data in
    if(vec.size() > 0){
        vec.erase(vec.begin(), vec.end());
    }

    //For loop that iterates the string and adds it into the vec
    for(int i=0; i<str.length(); ++i){
        //eliminate ws is the string contains any
        if(str[i] != ' '){
            vec.push_back(str[i]);
        }
    }
}

//The only time that we will have a negative number with parsing + and * is when 
// '-' is the first element, after +, * or ( otherwise it will be negative
bool Utility::isNeg(std::vector<char>& vec, int pos){
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

