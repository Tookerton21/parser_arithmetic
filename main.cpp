#include<cstdlib> 
#include<vector>
#include<string>
#include<iostream>
#include"equation.h"
#include"helper.h"

using namespace std;

struct Test {
    string testCase;
    int expected;
} tester;

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
    string str;
    int expected = 0;
    int res = 0;
    Equation equation;

    //Test 1
    str = "1+1";
    expected = 2;
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );

    
    //Test 2
    str = "(3+4)*6";
    expected = 42;
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );

    
    //test 3
    str = "(1*4)+(5*2)";
    expected = 14;
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );
    
    
    
    //test 4
    str = "1(4)";
    expected = 4;
    
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );



    //Test 5
    str = "4+10";
    expected = 14;
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );

    //test 6
    str = "-100 * 2";
    expected = -200;
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );

    //test 7
    str = "(-2*2)+2";
    expected = -2;
    equation.parseStr(str);
    res = equation.getRes();
    check(str,expected, res );
 
 /*
    //test 8
    str = "(-10+2)";
    expected = -8;
    equation = Equation(str);
    res = equation.getRes();
    check(str,expected, res );
*/

    return 0;
}