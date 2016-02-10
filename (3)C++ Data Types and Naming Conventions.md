#C++ Data Types and Naming Conventions

####Amal Saeed     



In this tutorial, we will be experimenting with how different data types are represented and manipulated in C++. I will be writing all of my C++ code in Xcode.


Let's start with variables!

A **variable** reserves a memory location in your computer which represents and stores a value for use in your program. All variables have an **identifier** - the name by which it is referred to, its **type** - which defines which operations can be performed on the variable, and the **data** it holds.

The C++ compiler requires us to provide the data type for *each* variable declared. The four basic types of variables are:  
- Boolean
- Character (surrounded by single quotes '') / String (surrounded by double quotes "")
- Integer (short, long, signed, unsigned)
- Floating point (float, double, long double)

Now, in order to name a variable, called the **identifier**, the following rules must be followed:   
- The name must start with a letter or underscore (_)  
- Every other character can be a letter, underscore, or number  
- Identifiers can be as long as you want  
- You can't use any keywords as variable names (such as int, string, etc.)   
- C++ *is* case-sensitive (`num` is different from `Num`)

  Beyond these base rules, you should keep in mind that identifiers should be descriptive, practical, and useful to its purpose in your program. Variable names are usually, in best practice, all lowercase, but camel case (i.e. variableName) or Pascal case (i.e. VariableName) can be used for multiple word names; these rules are enforced by programmers, to make variable names easier to read and understand. Also, do not start your identifiers with two underscores as they are often reserved for special system variables - this is enforced by the rules of C++ as it will throw an error.

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

####Creating variables in C++

**String**
```
#include <string> //<string> library to use strings; otherwise, <iostream> works as it includes the <string> library
using namespace std;

int main() {
  string test = "I'm learning C++";
  return 0;
}
```

**Character**
```
char test = 'a';
```

**Boolean**    
Only ever true or false. With integers, 0 is false and 1 or any non-zero value is true.
```
bool a = false;
bool b = true;

```

**Integer**   
Signed integers can hold both positive and negative values, meanwhile, unsigned integers can only hold positive values. Short types have half of the default size and long have twice the default size.
```
int x = 47;
unsigned long int y = 23;
```

**Floating Point**     
These data types can hold a real number, like 420.0 -3.33 or 0.03324, and can have a varying number of digits before and after the decimal point. They are always signed - so unlike with ints that have to specify, floating point data types always have the capability to hold both positive and negative values.
```
double temp = 4.21; //Double is 8 bytes long
float cel = 32.2; //Float is 4 bytes long
```

**Arrays**   
They are used to store a collection of variables of the same type.
```
int myArr[5]; //Declare the type, int, and size, 5, of the array, a
int myArr[5] = {12, 47, 66, 71, 84}; //Initialize the array a, with five integers inside the braces

int b[] = {11, 45, 62, 70, 88}; //Without initializing the size, the array is created just big enough to hold the values

cout<< b[0]<< endl; //Outputs 11, as 11 is the 0th index of array b. Index in arrays always starts at 0.
b[2] = 24;  //Assigns the value of 42 to the third element in the array b - 62 is now 42
```

**Hash**


It is important to note the data types that can be manipulated together. For example, you cannot add a char type to an int: `x = "5" + 6;` because you have to define the variable, so if it is now `int x = "5" + 6;` it still cannot be even compiled because it throws the error that adding 'int' to a string does append to the string, and it gives the same error if I assign x to a char data type.

Can you/ can you not add ints and floats, etc. ? 

How do type conversions work in C++?


C++ is a **statically-typed** language, which means that the data type of a variable is fixed at its declaration - for example: `int x = 2;` means x is an integer type and holds the numeric value of 2. Then if you type `string y = "5";`, you cannot set `x=y;` because x and y are of different, incompatible data types. You cannot perform that operation on int and string data types. It it also **weakly-typed**, meaning errors in your code are caught and brought to your attentions (a red line or exclamation point next to the error) while there is a problem, rather than notifying you at compile or runtime.
