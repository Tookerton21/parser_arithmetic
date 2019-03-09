#include <cstdlib>
#include <vector>
#include <string>

class Utility {
    public:
     static void stringToVec(std::string, std::vector<char> &);
     static bool isNeg(std::vector<char>& , int); //checks if the section of a vector is a a negative number
};