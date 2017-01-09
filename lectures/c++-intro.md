# Lecture 1 Notes: Introduction


### Why Use a Language Like C++?

- __Maintainability__: modifying code is easier when it entails just a few text edits, instead of rearranging hundreds of processor instructions. C++ is object oriented (more on that in Lectures 7-8), which further improves maintainability.
- __Portability__: different processors make different instructions available. Programs writ­ ten as text can be translated into instructions for many different processors; one of C++’s strengths is that it can be used to write programs for nearly any processor.





## Hello World
2 #include <iostream>
6
~~~



Token type | Description/Purpose | Examples
-----------|---------------------|----------
 Keywords | Words with special meaning to the compiler | int, double, for, auto
 Literals | Basic constant values whose value is specified directly in the source code |  "Hello, world!", 24.3, 0, ’c’
## Line-By-Line Explanation
- Lines beginning with `#` are preprocessor commands, which usually change what code is actually being compiled. `#include` tells the preprocessor to dump in the contents of another file, here the iostream file, which defines the procedures for input/output.
- `int main() {...}` defines the code that should execute when the program starts up. The curly braces represent grouping of multiple commands into a block. More about this syntax in the next few lectures.
- `cout <<` : This is the syntax for outputting some piece of text to the screen. We’ll discuss how it works in the lecture.
- Namespaces: In C++, identifiers can be defined within a context – sort of a directory of names – called a namespace. When we want to access an identifier defined in a namespace, we tell the compiler to look for it in that namespace using the scope resolution operator (`::`). Here, we’re telling the compiler to look for `cout` in the `std` namespace, in which many standard C++ identifiers are defined. A cleaner alternative is to add `using namespace std;` below line 2.  This line tells the compiler that it should look in the std namespace for any identifier we haven’t defined. If we do this, we can omit the `std::` prefix when writing cout. This is the recommended practice.
- Strings: A sequence of characters such as Hello, world is known as a string. A string that is specified explicitly in a program is a string literal.
- Escape sequences: The `\n` indicates a newline character. It is an example of an escape sequence – a symbol used to represent a special character in a text literal. Here are all the C++ escape sequences which you can include in strings:
   Escape Sequence | Represented Character
   ----------------|-----------------------
  
9. Note that every statement ends with a semicolon (except preprocessor commands and blocks using `{}`). Forgetting these semicolons is a common mistake among new C++ programmers.

-  Logical: used for “and,” “or,” and so on. More on those in the next lecture.
-  Bitwise: used to manipulate the binary representations of numbers. More on these later.
   Type Names | Description | Size | Range
   -----------|-------------|------|------
  bool | Boolean (true/false). Indi­cated with the keywords true and false. | 1 byte | Just true (1) or false (0).
  double | “Doubly” precise floating point number. | 8 bytes | +/- 1.7e +/- 308 ( 15 digits)
Notes on this table:
      
- There are actually 3 integer types: short, int, and long, in non-decreasing order of size (int is usually a synonym for one of the other two). You generally don’t need to worry about which kind to use unless you’re worried about memory usage or you’re using really huge numbers. The same goes for the 3 floating point types, float, double, and long double, which are in non-decreasing order of precision (there is usually some imprecision in representing real numbers on a computer).
- The sizes/ranges for each type are not fully standardized; those shown above are the ones used on most 32-bit computers.

An operation can only be performed on compatible types. You can add 34 and 3, but you can’t take the remainder of an integer and a floating-point number.

An operator also normally produces a value of the same type as its operands; thus, 1 / 4 evaluates to 0 because with two integer operands, / truncates the result to an integer. To get 0.25, you’d need to write something like 1 / 4.0.
2 using namespace std;
5 int x;
7 cout << x/3 << ’’ << x*2;
9 }

2 using namespace std;
5 int x;
9 }



