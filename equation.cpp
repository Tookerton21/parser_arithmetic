#include "equation.h"
#include <cstdlib> 
#include "helper.h"

Equation::Equation(){
    pos = 0;
    res = 0;
}
Equation::Equation(string st){
    str = st;
    stringToVec();

    //Get the Min operands into the map
    opers['+'] = true;
    opers['*'] = true;

    //set pos = 0;
    pos = 0;

    //set result = 0;
    res = 0;

    //call calcSum()
    res = calcSum();
}

void Equation::setStr(string s){
    str = s;
    pos = 0;
    res = 0;
    stringToVec();
}

void Equation::parseStr(){
    res = calcSum();
}

void Equation::parseStr(string s){
    this->pos = 0;
    this->res = 0;
    this->str = s;
    stringToVec();
    //cout << "INSIde PASRESTR\n";
    //cout << "string: " << str << endl;
    //cout << "vec: ";
    //for(auto const& x: vec){
    //    cout << x << " ";
    //}
    //cout << endl;
    res = calcSum();


}
//Public Function to return the result of the parsing of the Sum
int Equation::getRes(){
    return res;
}

//Main driver to the parser and calls each of the helper function recursively
int Equation::calcSum(){
    int res = sum();

    return res;
}

void Equation::print(){

  for(char const& x: vec){
      cout << x;
  }
  cout << endl;
}

void Equation::stringToVec(){
    if(vec.size() > 0){
        this->vec.erase(vec.begin(), vec.end());
    }

    for(int i=0; i<str.length(); ++i){
        //eliminate ws
        if(str[i] != ' '){
            this->vec.push_back(str[i]);
        }
    }
}

int Equation::getDig(){
   if (pos >= vec.size()){
       return res;
   }
   
    else if(vec[pos] == '('){
        ++pos;
        int num = sum();
        ++pos;
        return num;
    }

    else if(vec[pos] == ')'){
       ++pos;
       return res;
    }
    
    //Ensure that the digit is a valid number [0-9] && increment pos to move to the next position
    else if(Helper::isValidDig(vec[pos]) || Helper::isNeg(vec, pos)){
        int num = number();
       
         return num;
    } 
   
    
    
    
    else{
        cout<<"expected A digit" << endl;
    }
}

int  Equation::product(){
    int num1 = getDig();
    //cout << "PR num1: " << num1 << endl;
    while(Helper::isMult(vec, pos)){
        pos++;
        int num2 = product();
       // cout << "PR num2: " << num2 << endl;
        num1 *= num2;
    }
    return num1;
}

int Equation::sum(){
    int num1 = product();
    //cout << "num1" << endl;
    while(vec[pos] == '+'){
        ++pos;
        int num2 = product();
       // cout << "NUM2: " << num2 << endl;
        num1 += num2;
    }
 
    /*
    if(vec[pos] == '*'){
        int num2 = product();
        num1 *= num2;
    }
    */
    return num1;
}

int Equation::number(){
    int num = 0;
    int i = 0;
    char arr[11];

    while(Helper::isValidDig(vec[pos]) || Helper::isNeg(vec, pos)){
        arr[i] = vec[pos];
        ++i;
        ++pos;
    }
    
    num = Helper::getNum(arr);
    
    return num;
}

int Equation::parenth(){
    while(vec[pos] != ')'){

    }
}