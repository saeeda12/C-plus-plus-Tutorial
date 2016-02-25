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
You can also use `else if` to provide other alternatives. Remember your semicolons at the end of statements!
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

Short-circuit evaluation? Dangling else?

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
The `break` keyword exits the nearest enclosing switch/ iteration statement, and is only used in switch/ iteration statements. Observe the following (sparse) menu example:
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


#####Break and/or Continue Statements aka how can you exit loops

