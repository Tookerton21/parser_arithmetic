#include "equation.h"
#include <cstdlib> 
#include "helper.h"

//Constructor no parameters
Equation::Equation(){
    pos = 0;
    res = 0;
}

//Constructor with a parameter of type string
Equation::Equation(string st){
    str = st; //copy string over
    stringToVec(); //init the vector

    //Init vars
    pos = 0;
    res = 0;
    res = calcSum();
}

//Allow parsing multiple string for equation
void Equation::parseStr(string s){
    //Reset all vars to 0 and parse string 
    this->pos = 0;
    this->res = 0;
    this->str = s;
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

//Testing fuction to print the vector
void Equation::print(){

  cout << "vec: ";
  for(char const& x: vec){
      cout << x;
  }
  cout << endl;
}

//parse the string that was copied over to a vector char by char
void Equation::stringToVec(){
    //if the vector has data in it erease the vector before we data in
    if(vec.size() > 0){
        this->vec.erase(vec.begin(), vec.end());
    }

    //For loop that iterates the string and adds it into the vec
    for(int i=0; i<str.length(); ++i){
        //eliminate ws is the string contains any
        if(str[i] != ' '){
            this->vec.push_back(str[i]);
        }
    }
}

//Gets the digit of the equation 
int Equation::getDig(){
    
    //Safety that wont execute if if we are out of the boundries of the vecotor
   if (pos >= vec.size()){
       return res;
   }
   
   //If we are in a parenthesis we calculate everything inside of the parenth.
    else if(vec[pos] == '('){
        ++pos;//consume the left parenth
        int num = sum();//calculate the sum 
        ++pos; //increment past the close parenth
        return num;
    }

    
    //Ensure that the digit is a valid number [0-9], along with check if the number is neg && increment pos to move to the next position
    else if(Helper::isValidDig(vec[pos]) || Helper::isNeg(vec, pos)){
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

    //look for the secon number if one for multiplication
    while(Helper::isMult(vec, pos)){
        pos++;
        int num2 = product();
        num1 *= num2;
    }

    return num1;
}

//calculate the sum of the equation
int Equation::sum(){
    int num1 = product(); //get the first number
   //find the second number for addition if one
    while(vec[pos] == '+'){
        ++pos;
        int num2 = product();
        cout << num2 << endl;
        num1 += num2;
    }
 
    return num1;
}

//find the number in the vector, used to find multidigit numbers
int Equation::number(){
    int num = 0;
    int i = 0;
    char* arr = new char[11]; //uses 11 for max digits of an integer for pos and neg numbers

    //ensure that the array is wiped completley clean each time!! Otherwise can cause issues
    for(int i=0; i<11; ++i)
        arr[i] = '\0';

    while(Helper::isValidDig(vec[pos]) || Helper::isNeg(vec, pos)){
        arr[i] = vec[pos];
        ++i;
      
        ++pos;
    }
    
    num = Helper::getNum(arr);
    delete[] arr;

    return num;
}
