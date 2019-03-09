#include<cstdlib> 
#include<vector>
#include<string>
#include<iostream>
#include"equation.h"
#include"utility.h"

using namespace std;

const int SIZE = 7;
struct Test {
    string testCase;
    int expected;
};

void check(string str, int one, int two){
    cout << str << endl;

    if(one == two)
        cout << "valid" << endl;
    else{
        cout << "Invalid" << endl;
        cout << "Expected: " << one << " Res: " << two << "\n" << endl;
    }
}
int main(){
    Test test[SIZE] = {{"-2*(2+2)", -8},{"1+1", 2}, {"(3 + 4) * 6", 42}, {"(1*4)+(5*2)", 14}, {"-10 * (4+-2)", -20}, {"i*2+1", 0}, {"1*20+p", 20}};
    Equation equation;

    for(int i=0; i<SIZE; ++i){
        check(test[i].testCase, test[i].expected, equation.parseStr(test[i].testCase));
    }


    
    return 0;
}