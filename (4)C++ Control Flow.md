#Flow of Program Control in C++

####Amal Saeed


In this tutorial, we will learn how to write and use control statements in C++. As noted in my first C++ tutorial, I will be using my *C++ Programming* 2e as the primary source for tutorial 4's information. Information found and/or referenced elsewhere will be noted.


#####Conditional Statements

######One-Condition (if/else)     
The `if` statement contains a section of code (the controlled statement), that will *only* be executed if a certain condition evaluates to true. The else is to provide an alternative course of action, should the certain condition turn out false. The general syntax is below, followed by an example:  
```
if (condition)
  controllStatement; //for one statement
else
  controllStatement;

//OR

if (condition) {
  statement1;
  statement2;  //need braces for multiple statements
}
else {
  statement1;
  statement2;
}
```
```
int clouds = 70;
if (clouds > 50)
  cout<<"There are many clouds out today.";
else
  cout<<"There aren't many clouds out today.";
```
Although you technically don't need braces in the above examples, it is good practice (for readability and no ambiguity) to use them around the statements in your if/else conditions. You can also use `else if` to provide other alternatives. Remember your semicolons at the end of statements!
```
int clouds = 40;
if (clouds > 50)
  cout<<"There are many clouds out today.";
else if (clouds > 20)
  cout<<"There are handful of clouds out today.";
else
  cout<<"There are only a few clouds out today.";
```

######Multi-Condition (if/else)
You can have multiple conditions in `if/else` statements, using logical operators. The or operator is represented by `||` and is used in my example below; *only one* of the operands must be true in order for it to return true and execute the statements. The and operator is represented by `&&` and *both* operands must be true in order for the statements to execute. The equal operator is represented by `==` two equal signs (i.e. `if (clouds == 35)`), and the not equal operator is `!=` (i.e. `if (clouds != 35)`). C++ also has the greater-than and less-than operators (i.e. `if (clouds <= 35)`) and (i.e. `if (clouds >= 25)`). 
```
int clouds = 35;
if (clouds > 30 || clouds < 50)
  cout<<"There are handful of clouds out today.";
else
  cout<<"There aren't many clouds out today.";
```

Remember when I mentioned braces can eliminate ambiguity in your if/else statements earlier? Well, this can solve a big problem that many people run into, called the *dangling else*. The *dangling else* is a problem that occurs when you don't use braces with your conditional statements; if you have an if statement, nested inside an if statement, and then an else statement, and you did not use braces, it becomes ambiguous which if statement the else is associated with. C++, like Java, solves this problem by forcing the else to associate with the nearest preceeding if statment that does NOT cause a syntax error, and is not in a block (within braces). However, the best way to avoid issues like these is to simply use braces and indentation in your conditional statements so it is very clear what conditions go with what.
```
int clouds = 35;
if (cloudy==false)
if (clouds > 30 || clouds < 50)
  cout<<"There are handful of clouds out today.";
else  //DANGLING ELSE
  cout<<"There aren't many clouds out today.";
```
C++ will read this *dangling else* with the second if statement. If that is what you want, write it correctly - as seen below:
```
int clouds = 35;
bool cloudy(false);
    if (cloudy==false) {
        if (clouds > (30) || clouds < 50) {
            cout<<"There are handful of clouds out today.\n";
        } else {  //DANGLING ELSE
            cout<<"There aren't many clouds out today.\n";
        }
    }
```   
Source: http://www.mathcs.emory.edu/~cheung/Courses/561/Syllabus/2-C/dangling-else.html

The **conditional operator** is a way to write a simple piece of code in a simpler, more concise manner.
```
if(x > y) {
  z = y;
}
else {
  z = x;
}
```
The above code can be simplified into the following format:
```
condition ? expression1 : expression2  
      //With valid conditions, and valid expressions only. If true, will evaluate to expression1, and if false, expression2.

z=(x>y) ? y : x
```

#####Short-circuit evaluation  
Short-circuit evaluation or short-circuit logic, is when the compiler only evaluates the first condition in a multi-condition statement, if possible, like with the logical or || operator. This makes the compiler more efficient. Let's test if C++ uses short-circuit logic!
```
int clouds = 567;
    if (clouds > 20 || clouds < 50) { 
        cout<<"Short circuit.\n";
    }
    return 0;
```
This code prints out Short circuit, proving that the C++ compiler does indeed use short-circuit logic.


#####Loops

######while
- will continuously execute until a particular condition becomes false
```
while(condition)
  controlledStatement;
```

###### do while
- executes some code, and then tests the condition; always executes at least once
```
do {
  controlledStatement;
} 
while(condition);
```

######for
- an iteration statement that performs its own loop maintenance
```
for (initialization; condition; expression;) {
  controlledStatement;
}
```
```
for (int i=0; i<10; i++) {
  cout<< count << " ";
}
```
Output:
0 1 2 3 4 5 6 7 8 9


#####Switch-Case Statement
Or use continue to evaluate all of them?
The `switch` statement is a powerful tool, that is often the simplest and most elegant method to use when coding for multiple different choices/ possibilities. It enables you to test one variable against certain values and respond differently to each one. You can understand how writing multiple `if-else` statements would be cumbersome.
Here is the general syntax of the `switch` statement.
```
switch(expression) {
  case expr1:  //expression1
    controlledStatement;
    break;
  case expr2:
    controlledStatement;
    break;
  case expr3:
    controlledStatement;
    break;
}
```
The `break` keyword exits the nearest enclosing switch/ iteration statement, and is only used in switch/ iteration statements. C++ requires the `break` statement, otherwise, it will continue executing the statements in the following cases until it finds another `break;`. Observe the following (sparse) menu example:
```
int menuChoice = 3;
switch(menuChoice) {
  case 1:
    cout<<"You chose 1!\n";
    break;
  case 2:
    cout<<"Fritatas it is.\n";
    break;
  case 3:
    cout<<"Breakfast for dinner!\n";
    break;
}
cout<<"You have exited the switch statement.\n";
```
This program, when executed, will print:  
Breakfast for dinner!
You have exited the switch statement.

The `default` case sets a default statement in the `switch` statement.
```
int menuChoice = 3;
switch(menuChoice) {
  default:
    cout<<"You have the menu.\n";
  case 1:
    cout<<"You chose 1!\n";
    break;
  case 2:
    cout<<"Fritatas it is.\n";
    break;
  case 3:
    cout<<"Breakfast for dinner!\n";
    break;
}
cout<<"You have exited the switch statement.\n";
```


#####Break and/or Continue Statements
The `break` statement can also be used in `if-else` statements, to exit the loop. An example program is below:
```
#include <iostream>
using namespace std;
int main() {
    int number, sum = 0;  // can declare and initialize multiple variables (of the same type) in one line

    while (true) {     // will always be true
        cout<<"Enter a number: ";
        cin>>number;  // user input
        
        if (number != 0) {
            sum += number;
        }
        else {
            break;    // terminates the loop if number = 0
        }

    }
    cout<<"Sum = "<<sum;
    return 0;
}
```  
The `continue` statement is used to skip certain conditions in a loop. An example program is below:
```
#include <iostream>
using namespace std;
int main() {
    for (int i = 1; i <= 10; ++i) {
        if ( i == 6 || i == 9) {
            continue;  // causes the loop to skip printing out when i=6 and when i=9
        }
        cout<<i<<"\t";  // puts a tab between each number printed
    }
    return 0;
}
```
Source: http://www.programiz.com/cpp-programming/break-continue


####Note
I have created a fopc.cpp file with all the loops and Flow of Program Control statements, and attached it to my repository. I have commented out all the statements, except the first one-condition if-else statement. All the statements are within the main function - just un-comment whichever ones you want to test. You can download the file and try running it yourselves in your compiler! Play around with the statements too - see what works and what doesn't work!


