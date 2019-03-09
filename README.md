
## Equation Parser

### What Does it do

Takes an equation from the user in the form of a string. It will then Parse this string and if valid return an interger value. Uses a recursive top Down approach to Parse the equation.

### Known limitations

* Works with only + and *
* Numbers must be an integer and sum must be within an the limitations of an integer for negative and positive.
* Multiplication must be explicitly stated with * sign between the two numbers.

### How To Test Main Program

There is a tester main.cpp file that will run through a few test cases, print out the string that we wish to parse and valid/invalid.

```c++ -std=c++11 main.cpp equation.cpp helper.cpp```
```./a.out```

### How to use

can create an instance of ```Equation t;``` without any parameters for the constructor. To parse any equation after instantiation then you must call ```int num = t.parsStr(string)```.

### Known Bugs
    * (3/3/19) equations that start with a negative number in parenthesis are not getting parsed correctly.
        **(3/4/19) Bug has been fixed. was found in the number() function in equation.cpp. There set the first element to a null terminating char '\0'.

### Update
    * (3/7/19) Took out unnecessary functions, and variables along with taking out all attempts of trying to do multiplication with parenthesis.
    * (3/8/19) Took out the unnecessary files from the Git Repo