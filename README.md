# hangman-in-c
Hangman Game in C is a simple C program which I have designed to demonstrate procedure-oriented programming, different application formats and syntaxes of C programming language. It is a popular word guessing game where the player endeavours to construct a lost word by speculating one letter at a time. After a certain number of guesses, the game finishes and the player lose. The game also finishes when the player accurately distinguishes all the letters of the secret word within number of guesses allocated by the host. For instance, if the maximum tries are 5 and the user guesses it in less than 5 guesses, they win otherwise they lose.

The project involves use of both inbuilt and user defined functions. It also requires concepts of looping, string manipulation and control statements. The most frequently used control statements in this Hangman Game are if, else as well as iterative statements such as while and for loop.
The user defined functions perform the following operations -

1. declare and initialize the variables, compares string entered by user with string to be guessed.

2. replace string selected by compiler with “*” using for loop, encodes the string and the letters are revealed as and when the user guesses them correctly.
 
3. calculate the number of letters matched, check the matches and the number of wrong guesses, which shouldn’t exceed the number of maximum tries (5 in this case).
