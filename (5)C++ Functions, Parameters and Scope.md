#Functions, Parameters and Scope

###Amal Saeed


In this tutorial, we will learn how to write functions, how to pass parameters (or arguments) to them, and the scope and naming rules in C++.


####Declaring Functions
A **function** is a segment of code that performs a task, or tasks, and once written, can be called and used over and over again to perform that task. For example, you could write a function that calculates the area of a triangle, and then call that function whenever you want to calculate a triangle's area. Let's start with the first step of the function syntax: declaring a function! The function declaration, also known as a prototype, tells the compiler that a function exists. The general syntax is below:
```
return_type function_name(argument_list);
//OR
void function_name();
```
Above, `return_type` is the type of data that the function returns, and `argument_list` is the list of arguments - variable declarations - that the function requires, and is *not* required. If there is no return value, you type `void`. And always remember the semicolon! Let's explore with a simple multiplication function.
```
// Multiplication function
int mult(int a, int b);
```
Here, there is a return type - `int`, `mult` is the function name, and there are two arguments, separated by commas - `int a, int b`. And you finish the declaration with a semicolon! 

Now, from this function declaration, we need to define the function. The task we want `mult` to perform is multiplying together two integer numbers. The code block in which we will define `mult`'s task will be enclosed in braces {}. 
```
int mult(int a, int b) {
  code;
  return int;
}
```
We don't need a semicolon at the end of the function declaration because we are also defining it. Because our function returns a value of type `int`, it must have a return statement that returns a value of the same `return_type`, whereupon the functions terminates. Void functions can have a simple `return;` or `return 0;` statement at the end of the function that does not return anything, but it is not required. Xcode requires that you write `return = 0`, so that is what I will do, but your compiler might not require that. In the code inside the function, it is best to put any variable declarations at the beginning of the code block - it is easiest to find that way.

The `mult` function's definition is below. It simply returns the product of `a` and `b`. 
```
// Function definition
int mult(int a, int b) {
  return a * b;
}
```

The third step is calling the function! When you call a function, you tell the computer to start executing another section of code - the code block in the function - before continuing with the rest of the program. The syntax is below:
```
function_name(data1, data2, ... , dataN);
//OR
function_name();
```
`data1`, etc. must be of the same type (or a type that can be easily converted. For example, if the argument type is `int`, then you can call the function and pass a `float` or `double` type value as the argument, and it would convert to an `int`. This is called a cast); it must also be in the same order as the arguments in the function definition. It must also have the same number of arguments as in the function definition. 

The `mult` function call is below:
```
// Function call
mult(5, 43);
```
This multiplies together 5 and 43.

A function must obviously be declared *or* defined before it can be called. If the function definition is at the end of the program, which is perfectly fine, and you call the function before it, you need to put its declaration at the beginning of the program so the computer knows that the function exists. Otherwise, the function definition can simply be placed at the beginning of the program, and that's that! A sample program is below:
```
// Multiplication program

#include <iostream>

// Function declaration
int mult(int a, int b);

int main(void) {
  using std::count;
  using std::cin;
  int num1, num2;  // Declare two integer variable in the same line
  cout << "Enter a number: ";
  cin >> num1;
  cout << "Enter another number: ";
  cin >> num2;
  cout << "\n The product of these two numbers is: " << mult(num1, num2) << ". \n";  // A \n means a newline
}

// Function definition
int mult(int a, int b) {
  return a * b;
}
```
You can place a function call inside a print statement, as seen in the last line of `main`.


####Recursive Functions

**Recursion** is when a function calls itself inside its own function definition. 

The program below (with the function definition at the beginning) demonstrates a recursive function, called `numbers`, which increments the `int` number so long as it is less than 9, and prints the number with every increment. In this program, we used recursion, as opposed to writing a `for` loop. 
```
#include <iostream>
using namespace std;

int numbers(int i) {  // Function
  cout << "Number: " << i << endl;
  i++;
  if(i<9) {
    numbers(i);  // Recursion!
  }
  return i;
}

int main() {  // Main
  int i = 0;
  numbers(i);  // Function call
}
```
In `main`, I created another `i` variable, which is local *only* to `main`, and will not interfere with the `int i` passed as an argument in `numbers`'s parameters. I set it to 0, and then called the function; I also could have called the function like `numbers(0);` starting `i` at 0, which is also valid and easier, but this is an important lesson about **variable scope** which we will learn about next. 


####Scope
There are four categories of where variables can be accessed based on where they are declared. They include: inside the `main` function, in another function, in a block of code (i.e. loops, anything within {}), and in code outside functions. 

1. If a variable is declared outside a function - outside any block of code - it is considered a **global variable**. Its scope and lifetime (how long the variable lasts) are from the declaration to the end of the source file. 
2. If a variable is declared within a block of code, it is considered a **local variable** and its scope and lifetime are confined to within the code block.
3. If a variable is declared within the argument_list of a function declaration/ definition, it is called a **parameter**, and its scope and lifetime are until the end of the function. 

**Note:** Functions cannot access variable declared within the `main` function unless the variables are passed as arguments to the function. Also, if a variable is declared within a code block that is nested inside another code block, the scope of the variable is restricted to the inner code block.

Now, in C++, **global variables** and **local variables** can have the same name, which can cause some confusion because all operations performed on the variable will actually be performed on the local variable; thus, the local variable is said to *shadow* the global variable. If you want to use the global variable only, use the **scope resolution operator** (::) before the variable, as seen below:

```
int x;  // Global variable

int main(void) {
  int x;  // Local variable
  ::x = 10;  // Scope resolution operator, references the global variable
  return = 0;
}
```
Nevertheless, the best practice is to give all of your variables different names!


####Passed by Reference or Value?
In **pass by value**, the local parameters are copies of the original arguments passed in, and changes made in the function to these variables do not affect the original variables. In **pass by reference**, the local parameters are references to the storage locations of the original arguments passed in, and changes made to these variables in the function do affect the original variables, and no copy is made so the overhead (time, storage) is saved.

The programs below test if C++ is passed by value or reference.

```
#include <iostream>
#include <string>

using namespace std;

void func(int x) {
    x = 9*7;
}
int main(){
    int a = 40;
    func(a);
    cout<<"a = "<< a << "\n";
    return 0;
}
```
Output:
```
a = 40
```
Another example program to test if C++ is pass by value or reference:
```
#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 5;  // New function, new variable
    double y = 10;
    
    cout << "x = " << x << "\n";  // Value of x
    
    x = y;
    cout << "Set value of y to x to test if C++ is a pass by reference language \n";
    
    cout << "x = " << x << "\n";  // Print x to see if the value changed to the value of y
    
    y = 3*4;
    
    cout << "x = " << x <<"\n";
    
    return 0;
}
```
Output:
```
x = 5
Set value of y to x to test if C++ is a pass by reference language 
x = 10
x = 10
```
Because the value of x did not change when I set y to `3*4`, even though I set x to y, variables in C++ are pass by value. And in the first program, it did not affect the value of a when I called `func(a)` on it, a stayed 40, as instantiated in main.

**Verdict:** C++ is pass by value.

However, variables *can* be specifically **passed by reference**, using the `&` unary operator in front of the variable name. Using the same program from the first pass by value/reference test, I will make `x` into a reference variable.
```
#include <iostream>
#include <string>

using namespace std;

void func(int &x) {  // Reference variable
    x = 9*7;
}
int main(){
    int a = 40;
    func(a);
    cout<<"a = "<< a << "\n";
    return 0;
}
```
Output:
```
a = 63
```
This program outputs `a = 63` because we specified that the function parameter is a reference rather than a normal variable. After the function call, the value of `a` changed to what is declared in the function, `func`. A reference to a variable is treated exactly the same as a variable itself, so any changes made to the reference are passed through to the argument!

But wait! References allow the function to change the value(s) of its argument(s), which can be bad! If we don't want a function to change the value of its argument and also don’t want to pass by value, you can pass by **const reference**.
```
void ref(const int &value) {  // const reference
  value = 4; // Cannot do this now!
}
```
Using a **const reference** doesn't allow the variable being referenced to be changed through the reference, so if used, the function will not change the argument!

You can also use **reference parameters** to return multiple values, even though functions can only have one return value. Observe the same program used above, but tweaked:
```
#include <iostream>
#include <string>
using namespace std;

void ref(int &x, int &y, int z) {  // 2 reference value variables, 1 pass by value variable
    x = 4 * 7;
    y = 9;
    z *= x + y;
}

int main() {
    int x = 5;  // New variable
    int y = 10;  // New variable
    int z = 7;  // New variable
    
    ref(x, y, z);
    
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";
    cout << "z = " << z << "\n";
   
```
Output:
```
x = 28
y = 9
z = 7  // If we had passed in z as a reference variable (&z), this would have read z = 259
```

Actually, calling the function with multiple reference or pass by value variables in the parameters will return multiple values.

Source: https://www.cs.fsu.edu/~myers/c++/notes/references.html

####Assignments

If I run the following code in my compiler: 
```
#include <iostream>
#include <string>

#include <stdio.h>  //to use
#include <string.h> // memcpy
using namespace std;

int main() {
  
  char a[] = {'c','a','t'};
  char b[] = {'d','o','g'};
  a = b;  // ERROR
  b[1] = 'u';
  cout << "a: " << a << "\n";
  cout << "b: " << b << "\n";
}
```
The compiler in Xcode gives an error when I try to set a to b using `a = b;`. It will say "array type char[3] is not assignable." Arrays cannot be assigned to one another in C++, unlike primitive data types like `int` or `string`. 

However, I can assign the arrays to each other, and print them, using the following techniques.
```
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    
    std::array<char, 3> a = {'c', 'a', 't'};  // Declare <type, size> then the array name
    std::array<char, 3> b = {'d', 'o', 'g'};
    
    a = b;  // This works!
    
    b[1] = 'u';
    
    cout <<"a = " << a.data() << "\n";
    cout <<"b = " << b.data() << "\n";
    
}
```
Output:
```
a = dog
b = dug
```
**std::array** is a cool alternative to built-in, fixed arrays, and it is memory efficient. Just keep note of the syntax difference.

**Source:** 
http://www.learncpp.com/cpp-tutorial/6-15-an-introduction-to-stdarray/



