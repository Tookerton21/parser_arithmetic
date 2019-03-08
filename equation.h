#include<cstdlib> 
#include<string>
#include<vector>
#include<map>
#include <iostream>

using namespace std;

class Equation {
    public:

        Equation();
    
        //funtions
        int parseStr(string); //pass string to compute the equation

    protected:
        //Var declaritoin
        vector<char> vec; //char vector from the string passed in
        int pos;    //positon to access in the vecor
        int res;    //store result
        

        void stringToVec(string); //converst the string to the a vector of chars
        int getDig();   //Get the digit from the vector that its currently working on
        int product(); //calculate the product of the equation  
        int sum();  //calculate the sum of the equation
        int number(); // get the number to include multidigit numbers in the equation

};