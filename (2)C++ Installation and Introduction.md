##C++ Installation and Programming Environment
**Amal Saeed**

1. C++ can be installed on any operating system - Windows, Mac, or Unix/Linux.

2. First, we will need to install a compiler, as C++ is a compiled language. The most popular compiler is the GNU C/C++ Compiler. To install GCC on a Windows machine you need to install MinGW. To install MinGW, go to the [MinGW homepage](www.mingw.org), and follow the link to the MinGW download page. Download the latest version of the MinGW installation program, which should be named MinGW-<version>.exe. While installing MinGW, at a minimum, you must install gcc-core, gcc-g++, binutils, and the MinGW runtime, but you may wish to install more. Add the bin subdirectory of your MinGW installation to your PATH environment variable so that you can specify these tools on the command line by their simple names. When the installation is complete, you will be able to run gcc, g++, ar, ranlib, dlltool, and several other GNU tools from the Windows command line.
    If you are using Linux or UNIX then check whether GCC is installed on your system by entering the following command from the command line: $ g++ -v
If you have installed GCC, then it should print a message such as the following:
Using built-in specs.
Target: i386-redhat-linux
Configured with: ../configure --prefix=/usr .......
Thread model: posix
gcc version 4.1.2 20080704 (Red Hat 4.1.2-46)
If GCC is not installed, then you will have to install it yourself using the detailed instructions available [here](http://gcc.gnu.org/install/).
    Because I have a Mac, all I needed to do was install Xcode from the App Store, which includes the Xcode IDE and a compiler. 
      - http://www.tutorialspoint.com/cplusplus/cpp_environment_setup.htm

3. Next, choose a text editor to type your programs in - for example, Notepad on Windows, TextEdit or TextWrangler for Mac, and vi or vim for Unix/Linux. You can save these files with .cpp, .cp or .c extensions.
    a. C++ does not come with a recommended programming environment.

4. In Xcode, I can write all of my programs in the application. Go to File -> New Project, then click on Application under OS X, then choose Command Line Tool and hit next. And then you can name the project, and choose which language you would like to program in (Swift, Objective-C, C++, or C). This creates a folder, and a main.cpp file already written in C++ that executes a "Hello World!"; you can write your C++ code in the folder, as well as create new files. 

5. There is not a lot of boiler-plate code that you need to write in order to write a program, at least not as much as in Java.
    Here is a sample program - the first two lines are mandatory, as is int main(): 
`#include <iostream>using namespace std;int main() {cout << "Hello world!";return 0;}`

6. In C++, comments are written the same way as in Java. With two slashes: //this is a comment.
