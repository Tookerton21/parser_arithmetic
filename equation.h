#include<cstdlib> 
#include<string>
#include<vector>
#include<map>
#include <iostream>

using namespace std;

class Equation {
    public:

        Equation();
    
        //functions
        int parseStr(string); //pass string to compute the equation

    protected:
        //Var declaration
        vector<char> vec; //char vector from the string passed in
        int pos;    //position to access in the vector
        int res;    //store result
        
        //Functions
        int getDig();   //Get the digit from the vector that its currently working on
        int product(); //calculate the product of the equation  
        int sum();  //calculate the sum of the equation
        int number(); // Convert char array that we are looking at into an int

};