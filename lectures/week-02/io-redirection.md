# I/O Redirection

## CSCI 1061U

**Faisal Qureshi**

Unix Bash Shell allows I/O redirection via `<`, `>>` and `>` commands.

More info [here](http://www.tldp.org/LDP/abs/html/io-redirection.html)

## Redirecting `stdout` to a file

Use `>` command.

- `> filename` -- truncates file "filename" to zero-length; if file doesn't exist, create a zero-length file.  All stdout commands, such as `printf`, `cout`, etc. will write to the file "filename"
	- Example: `ls > directory-listing.txt`
- `>> filename` -- creates a zero-legnth file if one doesn't already exist.  If a file exists, contents will be appended to it.  All stdout commands, such as `printf`, `cout`, etc. will write to the file "filename"
	- Example: `ls > directory-listing.txt; ls >> directory-listing.txt`

## Redirecting file contents to `stdin`

Use `<` command

- `< filename` -- contents in the file are provided to `stdin` functions (`scanf`, `cin`, etc.)  in the program.

Consider the following program (prog.cpp).

~~~cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	char c;

	cout << "Enter an integer: ";
	cin >> n;
	cout << "Enter a char: ";
	cin >> c;
	
	cout << "integer is " << n << " and character is " << c << endl;
	
	return 0;
}
~~~

Assume we have the following file (input.txt)

~~~txt
232 r
~~~

When we execute the program as follows, the output is:

~~~bash
$ g++ prog.cpp -o prog
$ ./prog < input.txt
Enter an integer: 
Enter a char:
integer is 232 and character is r
$
~~~

Notice that the user didn't have to enter an integer or a character.  Despite the fact that these items needed to be entered via `stdin`--since `cin` was used to read it.  Instead the `<` command tied file "input.txt" to the stdin.  Consequently, `cin` in the program took the required values (an integer and a character) from this file.

This is a great way to automate program testing.   Since user doesn't have to respond to any prompts from the program.

Note that `./prog < input.txt` doesn't mean that `<` and `input.txt` are passed as command line arguments.  If the intention is to pass these items as command line arguments then use the following command `./prog \< input.txt`.  The backslash character `\` is the escape character that we use to tell the Bash shell that `<` should be treated as a character and not as a means to redirect a file to `stdin`.