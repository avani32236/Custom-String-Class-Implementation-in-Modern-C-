# Custom-String-Class-Implementation-in-Modern-C-
This project implements a user-defined STRING class in C++ that mimics and extends the functionality of standard string handling. It demonstrates object-oriented programming concepts, dynamic memory management, and operator overloading, along with custom implementations of common string operations.

Features
Dynamic memory allocation for string storage
Constructor, copy constructor, and destructor implementation
Operator overloading:
Assignment (=)
Concatenation (+)
Comparison (<, >, ==, <=, >=, !=)
Subscript ([])
Input/Output (>>, <<)
Custom string manipulation functions:
Find character (strchr, strrchr)
String length calculation
String reversal
Substring search
Convert to uppercase and lowercase
Copy and partial copy (strcpy, strncpy)
Compare strings (strcmp, strncmp)
Concatenation (strcat, strncat)
Implementation Details
The class uses a character pointer (char *p) to store string data dynamically, allowing flexible memory usage and manual control over allocation and deallocation .
Friend functions are used to implement various string operations outside the class while still accessing private data members.

 How It Works
User inputs two strings.
Various operations are performed:
Assignment and concatenation
Character modification using subscript operator
String comparisons
Execution of multiple string functions (search, reverse, case conversion, etc.)
Results are displayed on the console.

Concepts Covered
Object-Oriented Programming (OOP)
Operator Overloading
Friend Functions
Dynamic Memory Allocation
String Manipulation in C++

Purpose

This project is designed for learning and practicing:

Core C++ concepts
Manual implementation of string operations
Understanding how built-in string libraries work internally
Note

This is an educational implementation and does not replace the standard std::string class, but helps in understanding low-level string handling and memory management.
