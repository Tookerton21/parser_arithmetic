
## Equation Parser

### What Does it do

Takes an equation from the user in the form of a string. It will then Parse this string and if valid return an interger value. Uses a recursive top Down approach to Parse the equation.

### Known limitations

* Works with only + and *
* Numbers must be an integer and sum must be within an the limitations of an integer for negative and positive.
* Multiplication must be explicitley stated with * sign between the two numbers.

### How to use

can create an instance of ```Equation t``` with or without any paramaters for the constructor. To parse any equation after instantiation then must call ```parsStr(string)```. To get what the result from after parsing the string call ```getRes()``` which returns and integer of type int.

### Known Bugs
    * (3/3/19) equations that start with a negative number in parenthesis are not getting parrsed correctly.