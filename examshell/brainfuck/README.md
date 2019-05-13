# Brainfuck-Interpreter

Brainfuck is a minimalist language. It consists of an array of bytes 
(in our case, let's say 2048 bytes) initialized to zero, and a pointer to its first byte.

Every operator consists of a single character :
- '>' increment the pointer ;
- '<' decrement the pointer ;
- '+' increment the pointed byte ;
- '-' decrement the pointed byte ;
- '.' print the pointed byte on standard output ;
- '[' go to the matching ']' if the pointed byte is 0 (while start) ;
- ']' go to the matching '[' if the pointed byte is not 0 (while end).

Any other character is a comment.

-----------------------------------------------------------------------------------------------

This program is designed to answer to the rules mentioned above (no '-' and ',' rules).
It will take all of the command line arguments and print the corresponding output on a line.
It also checks if the input string has a valid format (i.e number of closing brackets is equal to the number of opening brackets).

Compile:<br />
clang -Wall -Wextra -Werror brainfuck.c -o brainfuck <br />
<br />
Run:<br />
./brainfuck String1 [String2] [String3]...<br />
<br />
Examples<br />
./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."<br />
./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>."<br />
./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>.]"<br />
<br />
Output:<br />
Hello World!<br />
Hi<br />
Invalid format.<br />
