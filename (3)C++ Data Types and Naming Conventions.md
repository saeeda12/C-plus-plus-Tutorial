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

  Beyond these base rules, you should keep in mind that an identifier should be descriptive, practical, and useful to its purpose in your program. Variable names are usually, in best practice, all lowercase, but camel case (i.e. variableName) or Pascal case (i.e. VariableName) are used for multiple word names; these rules are enforced by programmers, to make variable names easier to read and understand (especially when debugging!). Also, do *not* start your identifiers with two underscores as that is often reserved for special system variables - this is enforced by the rules of C++ as it will throw an error.

The syntax for declaring variables is `variable_type identifier;`. **Make sure your statements always end in a semicolon!**
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
You must include the `<string>` library to use strings; otherwise, `<iostream>` works and is preferred as it includes the `<string>` library.
```
#include <string> 
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
Signed integers can hold both positive and negative values, meanwhile, unsigned integers can only hold positive values. Short types have half of the default size (2 bytes) and long is slightly larger than ints which are 4 bytes - however, it has become convention to define `int` and `long` to be the same size on standard computers (Lee, Chapter 2, page 33).
```
int x = 47;

unsigned long int y = 23056;
 is the same as
unsigned long y = 23056;
```    
Because `unsigned long int` can get cumbersome to write, you can use **typedef** to shorten the data type name.
```
typedef unsigned long int ulong;
ulong radius = 476;
```

**Floating Point**     
These data types can hold a real number, like 420.0 -3.33 or 0.03324, and can have a varying number of digits before and after the decimal point. They are always signed - so unlike with ints that have to specify, floating point data types always have the capability to hold both positive and negative values.
```
double temp = 4.21; //Double is 8 bytes long
float cel = 32.2; //Float is 4 bytes long
```

**Arrays**   
They are used to hold a set of data of the same type, and can store any data type.
```
int myArr[5]; //Declare the type, int, and size, 5, of the array, a
int myArr[5] = {12, 47, 66, 71, 84};  //Initialize the array a, with five integers inside the braces

int b[] = {11, 45, 62, 70, 88}; //Without initializing the size, the array is created just big enough to hold the values

cout<< b[0]<< endl; //Outputs 11, as 11 is the 0th index of array b. Index in arrays always starts at 0.
b[2] = 24;  //Assigns the value of 42 to the third element in the array b - 62 is now 42
```

**Hash**   
A hash table is implemented as an array of linked lists - kind of like a multidimensional array. In a two-dimensional array, for instance, the elements consist of rows of a fixed length. In a hash table, however, the elements (buckets) can expand or shrink to accommodate a virtually infinite number of table entries. A **hash function** decides where to store and retrieve items in a hash table. It takes in an item key as its parameter and returns an index location for that particular item, primarily with modulo arithmetic. **1)** It accepts a single parameter of type Key, **2)** returns a value of type size_t that represents the hash value of the parameter; **3)** for two parameters k1 and k2 that are equal, **4)** std::hash<Key>()(k1) == std::hash<Key>()(k2), while for two different parameters k1 and k2 that are not equal, the probability that std::hash<Key>()(k1) == std::hash<Key>()(k2) should be very small, approaching 1.0/std::numeric_limits<size_t>::max().
```
#include <iostream>
#include <functional>
#include <string>

int main () {
  char a[] = "Test";
  char b[] = "Test";
  std::string s1 (a);
  std::string s2 (b);

  std::hash<char*> ptr_hash;
  std::hash<std::string> str_hash;

  std::cout << "same hashes:\n" << std::boolalpha;
  std::cout << "a and b: " << (ptr_hash(a)==ptr_hash(b)) << '\n';
  std::cout << "s1 and s2: " << (str_hash(s1)==str_hash(s2)) << '\n';

  return 0;
}
```    
Sources: http://www.cplusplus.com/reference/functional/hash/ and http://en.cppreference.com/w/cpp/utility/hash

It is important to learn which data types can and cannot be manipulated together. For example, you cannot add a char type to an int: `x = '5' + 6;` because you have to define the variable, so if it is now `int x = '5' + 6;` it still cannot be even compiled because it throws the error that adding 'int' to a string does append to the string, and it gives the same error if I assign x to a char data type.

####How do type conversions work in C++?
A type conversion is the process of converting a value from one data type to another. In **implicit/automatic type conversion, or coercion**, the compiler automatically transforms one fundamental data type into another.     

A **numeric promotion** is when a value from one type is converted into a value of a larger *similar* data type; also called **widening**, though this term is usually reserved for integers. This type conversion is safe, and never results in the loss of data or precision. For example, an int can be widened into a long, or a float promoted into a double:   
```
long l(64);  //widens the integer 64 into a long
double d(0.12f);  //promotes the float 0.12 into a double
```   
Two subsets of numeric promotions: **integral promotion** involves the conversion of integer types narrower than int (bool, char, unsigned char, signed char, unsigned short, signed short) to an integer (if possible) or an unsigned int. **Floating point promotion** involves the conversion of a float to a double.   

A **numeric conversion** is when we convert a value from a larger type to a similar smaller type, or between different types. Conversions come with a risk - that the compiler will alert you to - as they may result in the loss of data.
```
double d = 3;  //converts integer 3 to a double
short s = 2;  //converts integer 2 to a short
```      

**Explicit type conversion** uses a type casting operator (a cast) to tell the compiler to perform a specific request by the programmer to do a type conversion. **Typecasting** is making a variable of one type, such as an int, act like another type, a char, for one single operation.    

A **C-style cast** standard C programming, casts are done via the () operator, with the name of the type to cast to inside.
```
int i1 = 10;
int i2 = 4;
float f = (float)i1 / i2;
```
In the above program, we use a float cast to tell the compiler to promote i1 to a floating point value. Because i1 is a floating point value, i2 will then be promoted to a floating point value as well, and the division will be done using floating point division instead of integer division! C-style casts should generally be avoided because they are not checked by the compiler at compile time!

A **static cast** casting operator is called static_cast. It is used to convert a char into an int so that std::cout prints it as an integer instead of a char:
```
char c = 97;
std::cout << static_cast<int>(c) << std::endl; // prints 97, not 'a'
```
static_cast is best used to convert one fundamental type into another.
```
int i1 = 10;
int i2 = 4;
float f = static_cast<float>(i1) / i2;
```   
The main advantage of static_cast is that it provides compile-time type checking, making it harder to make an inadvertent error. Static_cast is also (intentionally) less powerful than C-style casts, so you can’t inadvertently remove const or do other things you may not have intended to do.


C++ is a **statically-typed** language, which means that the data type of a variable is fixed at its declaration - for example: `int x = 2;` means x is an integer type and holds the numeric value of 2. Then if you type `string y = "5";`, you cannot set `x=y;` because x and y are of different, incompatible data types. You cannot perform that operation on int and string data types. It it also **weakly-typed**, meaning errors in your code are caught and brought to your attentions (a red line or exclamation point next to the error) while there is a problem, rather than notifying you at compile or runtime.
