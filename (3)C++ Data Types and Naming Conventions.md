##C++ Data Types and Naming Conventions

#####Amal Saeed


In this tutorial, we will be experimenting with how different data types are represented and manipulated in C++.


Let's start with variables!

A **variable** reserves a memory location in your computer which represents and stores a value for use in your program. All variables have an **identifier** - the name by which it is referred to, its **type** - which defines which operations can be performed on the variable, and the **data** it holds.

The C++ compiler requires us to provide the data type for *each* variable declared. The four basic types of variables are: Boolean, character, integer, short, long, double, and floating-point types.

Now, in order to name a variable, called the **identifier**, the following rules must be followed:
1. The name must start with a letter or underscore _
2. Every other character can be a letter, underscore, or number
3. Identifiers can be as long as you want
4. You can't use any keywords as variable names (like int)
5. C++ *is* case-sensitive (Num is different than num)
  Beyond these base rules, you should keep in mind that identifiers should be descriptive, and useful to its purpose in your program. Variable names are usually, in best practice, all lowercase, but camel case is used for combined words (i.e. variableName). Also, do not start your identifiers with two underscores as they are often reserved for special system variables.

The syntax for declaring variables is `variable_type identifier;`. Make sure your statements always end in a semicolon!
```
int x;
```
If you want to assign a variable, keep the assigned value (the literal data) on the right side of the assignment (=) operator:
```
x = 5; //valid
5 = x; //not valid
```
If you want to do the previous two steps in one line, it is called **initializing the variable**:
```
int x = 5;
```
It is important to note the data types that can be manipulated together. For example, you cannot add a char type to an int: `x = "5" + 6;` because you have to define the variable, so if it is now `int x = "5" + 6;` it still cannot be even compiled because it throws the error that adding 'int' to a string does append to the string, and it gives the same error if I assign x to a char data type.

