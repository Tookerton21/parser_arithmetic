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

    //set if there is a prev number to 0;
    isPrev = false;

    //call calcSum()
    res = calcSum();
}

void Equation::setStr(string s){
    str = s;
    stringToVec();
}

void Equation::parseStr(){
    res = calcSum();
}

void Equation::parseStr(string s){
    str = s;
    stringToVec();
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
    for(int i=0; i<str.length(); ++i){
        //eliminate ws
        if(str[i] != ' '){
            vec.push_back(str[i]);
        }
    }
}

int Equation::getDig(){
   // int temp = 0;
    /*if(Helper::isValidDig(vec[pos]) && vec[pos+1] == '('){ */
   if (pos > vec.size()){
       return res;
   }
    //Ensure that the digit is a valid number [0-9] && increment pos to move to the next position
    else if(Helper::isValidDig(vec[pos]) || Helper::isNeg(vec, pos)){
        int num = number();
       
        //cout << "num: " << num << endl;
        /*
        if(vec[pos] == ')')
            ++pos;
        */
         return num;
    } 
    else if(vec[pos] == '('){
        ++pos;
        int num = calcSum();
        ++pos;
       // cout << "NUMBER: " << num << endl;
        return num;
    }
    /*
    else if(vec[pos] == ')'){
       ++pos;
       cout << "returning: " << res << endl;
       return res;
    }
    */
    else{
        cout<<"expected A digit" << endl;
    }
}

int  Equation::product(){
    int num1 = getDig();
    while(Helper::isMult(vec, pos)){
        pos++;
        int num2 = product();
        num1 *= num2;
    }
    return num1;
}

int Equation::sum(){
    int num1 = product();
   
  // cout << "looking for +: " << vec[pos] << endl;
    while(vec[pos] == '+'){
        pos++;
        int num2 = product();
        num1 += num2;
    }
    //cout << "LETS SEE: " << num1 << endl;

    if(vec[pos] == '*'){
        int num2 = product();
        num1 *= num2;
    }
    //cout << "NUM1" <<num1 << endl;
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
    
    cout << "Number: " << num << endl;
    //indicate that there will be multiplication happening due to there being a number next to parenthesis
    if(vec[pos] == '('){
        isPrev = true;
        prev = num;
    }
    
    return num;
}