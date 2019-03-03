#include<cstdlib> 
#include<string>
#include<vector>
#include<map>
#include <iostream>

using namespace std;

class Equation {
    public:
        string str;
        //const.
        Equation();
        Equation(string);
        //Test function to ensure that the strToVec is working properly 
        void print();
        int getRes();
        void setStr(string);
        void parseStr();
        void parseStr(string);

    protected:
        vector<char> vec; //char vector from the string passed in
        map<char, bool> opers; //map for the valid operands
        int pos;
        int res;

        int calcSum();
        void stringToVec();
        int getDig();
        int product();
        int sum();
        int number();
        int parenth();
};