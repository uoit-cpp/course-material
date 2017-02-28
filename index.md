# Instructor: Faisal Qureshi

__Office:__ UA4032  
__Phone:__ 905-721-8668 x 3626  
__Email:__ faisal.qureshi@uoit.net

# News and such

- **New location:**  Starting Tuesday, Jan 17, lectures will take place in UA1120.  
- **Midterm will take place on Feb. 14 in class.**  The midterm will contain both a written portion and a programming component.  Please ensure that your laptops are able to edit and compile CPP programs.  You will not be allowed to access the internet or existing code on your computer.  You are encouraged to prepare a 1 page (letter, 2-sided) CPP cheatsheet that you can bring to the midterm.  You will be allowed to use this cheatsheet during the programming part of the midterm.  The midterm will cover everything that we discuss till Friday, Feb. 10. 

# General Info

## Teaching Assistants

- Mohammadamin Beirami
- Robert deBruyn
- Tony Joseph
- Luisa Rojas

## Lecture times

- Tuesday, 11:10 am in UL9
- Friday, 12:40 pm in UL9

## Lab sessions

Each student will be assigned one of the following 4 lab sections.  All labs cover the same material.

- Wednesday, 6:40 pm to 9:30 pm, Simcoe Building J123-A (__Luisa__)
- Friday, 8:10 am to 11:00 am, Simcoe Building J123-A (__Mohammadamin__)
- Friday, 5:10 pm to 8:00 pm, Simcoe Building J123-A (__Tony__)
- Thursday, 6:40 pm to 9:30 pm, Simcoe Building J123-A (__Robert__)

Scheduling information is available here [https://uoit.ca/mycampus/available-courses.php](https://uoit.ca/mycampus/available-courses.php)

## Office Hours

- Tuesday, 12:30 pm to 2 pm in UA4032
- Or by appointment

# Grading

Work | Weight
-----|-------
Class participation and exercises |  10%
Lab participation and completion | 20%
Midterm exams (2) | 24%
Assignments (3) | 20%
Final exam | 26%

A student must get 40% in the final exam to pass the course. 

## Important Dates

Work | Dates
-----|------
Assignment 1 | Jan 23 – Feb 5 (revised Feb 7)
Assignment 2 | Feb 20 – Mar 5
Assignment 3 | Mar 20 – Apr 2
Midterm 1 | Feb 14 in class
Midterm 2 | Mar 14 in class


# Syllabus

Course syllabus is available [here](syllabus.pdf)

# Resources

Introduction to C++ course available at the MIT Open Courseware contains an excellent collection of notes.  You can find these [here](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-096-introduction-to-c-january-iap-2011/lecture-notes/).  

Coding videos are available [here](https://www.youtube.com/playlist?list=PLxXSLsFiK684ncgWP0Aqe-5l5VfthqaOp).  Source code for these videos is available at Github [here](https://github.com/programming-workshop-2/coding-videos.git).

We will be _programming_ during each lecture.  Please bring your laptop to class.  Please ensure that you are able to edit, compile and execute C++ programs via commandline interface.

This course deals with C++ programming.  There are many online C++ help resources.  I encourage you to make use of these resources.  As far as books are concerned, I find the following textbook to be exceedingly useful.

_Absolute C++, 6th Edition_ by Walter Savitch.

Students are encouraged to take their own notes during lectures.

# Important

- Please use your uoit.net email address to sign up for course Slack channel [https://uoit-w17-csci1061.slack.com/signup](https://uoit-w17-csci1061.slack.com/signup)
- All work needs to be submitted via [Blackboard](http://uoit.blackboard.com)

# Lectures


### Week 1 (Jan 9)

- Topics: variables, control flows, loops and conditions, reading and writing text files
	- [CSCI 1060U review and introduction](lectures/week-01/c++-intro)
	- [File I/O](lectures/week-01/c++-fileio)
- Live coding 
	- [ave.cpp](lectures/week-01/ave.cpp)
	- [ave1.cpp](lectures/week-01/ave1.cpp)
	- [cmdline arguments](lectures/week-01/cmd.cpp)
	- [text-file-read](lectures/week-01/file-read.cpp)
	- [text-file-write](lectures/week-01/file-write.cpp)

### Week 2 (Jan 16) 

- Topics: pointers, dynamic memory allocation, variable scoping, binary representation, bitwise operators
	- [Command line arguments](lectures/week-02/cmdline-arguments)
	- [IO redirection](lectures/week-02/io-redirection)
- Jottings
	- [Jan 17](lectures/week-02/note-2017-01-17.pdf) 
	- [Jan 20](lectures/week-02/note-2017-01-20.pdf)
- Bit-wise operators 
	- [binary-one-byte.cpp](lectures/week-02/binary-one-byte.cpp)
	- [binary.cpp](lectures/week-02/binary.cpp)
- A command line calculator
	- [calc.cpp](lectures/week-02/calc.cpp)

### Week 3 (Jan 23)

- Topics: binary files, read/write, seekg/tellg and seekp/tellp
	- [C++ struct](lectures/week-03/cpp-struct)
- Jottings: 
	- [Jan 24](lectures/week-03/note-2017-01-24.pdf)
	- [Jan 27](lectures/week-03/note-2017-01-27.pdf)
- Live coding
	- [Calc with text log](lectures/week-03/calc2.cpp)
	- [Text log reader](lectures/week-03/sherlock.cpp)
	- [Calc with binary log](lectures/week-03/calc2-bin.cpp)
	- [Binary log reader](lectures/week-03/watson.cpp)
	- [Read/write files](lectures/week-03/rw.cpp)
	- [String streams](lectures/week-03/ss.cpp)
	- [C++ struct](lectures/week-03/struct.cpp)

### Week 4 (Jan 30)

- Topics: multi-file C++ programs, Makefile 
	- [Slides](lectures/week-04/makefiles/csc1061u-makefiles.pdf)
	- [Dealing with Multiple Files](lectures/week-04/dealing-with-multiple-files)
- Example code
	- [Makefile ex. 1](lectures/week-04/makefiles/src/Makefile)
	- [Makefile ex. 2](lectures/week-04/makefiles/src/Makefile2.make)
	- [Makefile ex. 3](lectures/week-04/makefiles/src/Makefile3.make)
	- [Makefile ex. 4](lectures/week-04/makefiles/src/Makefile4.make)
	- [greetings.cpp](lectures/week-04/makefiles/src/greetings.cpp)
	- [greetings.h](lectures/week-04/makefiles/src/greetings.h)
	- [main.cpp](lectures/week-04/makefiles/src/main.cpp)
	
### Week 5 (Feb 6)

- Topics: classes, constructors, destructors, etc.
	- [vec2 class ver. 1](lectures/week-05/vec2)
- File copy exercise
	- [Exercise](exercises/file-copy/file-copy-exercise) 
	- [Solution](exercises/file-copy/file-copy.cpp)

### Week 6 (Feb 13)

- Midterm, Feb 14., in class
- Topics: const and friend functions, insertion and extraction operators
	- [vec2 class ver. 2](lectures/week-06/vec2-v2) 

_Reading week break_

### Week 7 (Feb 27)

- Topics: more about classes
- Dynamic array exercise
	- [Exercise](exercises/dynamic-array-class/dynamic-array-exercise-part1) 

### Week 8 (Mar 6)

### Week 9 (Mar 13)

### Week 10 (Mar 20)

### Week 11 (Mar 27)

### Week 12 (Apr 3)

# Labs

- Week 1, no lab this week
- Week 2, Setup
	- [Handout](labs/lab1-setup)
	- Solution 
		- [average.cpp](labs/lab1-setup/average.cpp)
		- [average.h](labs/lab1-setup/average.h)
		- [lab1.cpp](labs/lab1-setup/lab1.cpp)
		- [helloworld.cpp](labs/lab1-setup/helloworld.cpp)
- Week 3, Caesar cipher
	- [Handout](labs/lab2-caesar-cipher)
	- Solution
		- [cf.cpp](labs/lab2-caesar-cipher/cf.cpp) 
- Week 4, C++ struct
	- [Handout](labs/lab3-struct)
	- Solution sketch
		- [add-employee.cpp](labs/lab3-struct/add-employee.cpp) 
		- [prn-employee.cpp](labs/lab3-struct/prn-employee.cpp) 
- Week 5, Multi-file programs
	- [Handout](labs/lab4-multifile)
	- Solution
		- [Makefile](labs/lab4-multifile/Makefile)
		- [main.cpp](labs/lab4-multifile/main.cpp)
		- [count.cpp](labs/lab4-multifile/count.cpp)
- Week 6, No lab this week.  Its midterm week.
- Week 7, Reading week
- Week 8, 3-Dimensional vector class
	- [Handout](labs/lab5-class-vec3) 

# Assignments

- Assignment 1
	- [Handout](assignments/a1), this needs to be submitted via Blackboard.
	- [Solution](assignments/a1-solution)
- Assignment 2
	- [Handout](assignments/a2), this needs to be submitted via Blackboard.	
	