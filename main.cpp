#include<cstdlib> 
#include<vector>
#include<string>
#include<iostream>
#include"equation.h"

using namespace std;

int main(){
    vector<string> testCases;
  
    testCases.push_back("2(2) * 4");
    cout << testCases[0] << endl;
    Equation equation(testCases[0]);
    equation.print();
    cout << "Res: " << equation.getRes() << endl;
    return 0;
}