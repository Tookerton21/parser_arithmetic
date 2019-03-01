#include "equation.h"
#include <cstdlib> 

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

//Public Function to return the result of the parsing of the Sum
int Equation::getRes(){
    return res;
}

//Main driver to the parser and calls each of the helper function recursively
int Equation::calcSum(){
    int res = parseSum();

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
    int temp = 0;

    if((vec[pos] >= '0' && vec[pos] <='9') && vec[pos+1] == '('){
        int left = vec[pos] - '0';
        ++pos;
        int res = calcSum();
        ++pos;
        return left*res;
    }
    //Ensure that the digit is a valid number [0-9] && increment pos to move to the next position
    else if(vec[pos] >= '0' && vec[pos] <='9'){
        ++pos;
        int  res = (vec[pos-1] - '0');
        return res;
    } 
    else if(vec[pos] == '('){
        ++pos; //increment pos
        int res = calcSum();
        ++pos; //increment for the ')'
        return res;
    }
    else{
        cout<<"expected A digit" << endl;
    }
}

int  Equation::parseProduct(){
    int num1 = getDig();
    while(vec[pos] == '*'){
        pos++;
        int num2 = getDig();
        num1 *= num2;
    }
    return num1;
}

int Equation::parseSum(){
    int num1 = parseProduct();
   
    while(vec[pos] == '+'){
        pos++;
        int num2 = parseProduct();
        num1 += num2;
    }

    return num1;
}