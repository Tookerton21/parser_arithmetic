#include <stdlib.h> 
#include <vector>

class Helper {
    public:
     static int getNum(char[]); //go from char array to integer
     static bool isValidDig(char); //checks to see if a char is a valid digit [0-9]
     static bool isNeg(std::vector<char>& , int); //checks if the section of a vecor is a a negative number
     static bool isMult(std::vector<char>& , int); //checks to see if we are working with multiplication or not
};