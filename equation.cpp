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
    int dig = (int)getDig();

    res = parseProduct();
    res = parseSum();

    return res;
}

void Equation::print(){
  cout << "String: " << str << endl;
  cout << "Vec: ";
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
    //Ensure that the digit is a valid number [0-9] && increment pos to move to the next position
    if(vec[pos] >= '0' && vec[pos] <='9'){
        ++pos;
        cout << "tester: " << (vec[pos-1] - '0') << endl;
        return (vec[pos-1] - '0');
    }
   
    else{
        cout<<"expected A digit" << endl;
    }
}

int  Equation::parseProduct(){
    int num1 = getDig();
    while(vec[pos] == '*'){
        ++pos;
        int num2 = getDig();
        num1 *= num2;
    }
    return num1;
}

int Equation::parseSum(){
    int num1 = parseProduct();
    cout<<"Num1: "<< num1<<endl;
    while(vec[pos] == '+'){
        ++pos;
        int num2 = parseProduct();
      cout<<"Num2: " << num2 << endl;
        num1 += num2;
    }

    return num1;
}