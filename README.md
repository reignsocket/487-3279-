Problem Description  
Businesses like to use phone numbers that are easy to remember. One way to make a phone number easy to remember is to write it as a word or phrase that is easy to remember. For example, if you need to call Waterloo University, you can call TUT-GLOP. Sometimes, only some of the numbers in the phone number are spelled into words. When you return to the hotel in the evening, you can order a pizza from Gino's by calling 310-GINO. Another way to make a phone number easy to remember is to group the numbers of numbers in a friendly way. You can order pizza from them by dialing Pizza Hut's "Three Ten" number 3-10-10-10  

The standard format for a telephone number is a seven-digit decimal number with a connector between the third and fourth digits. Dial
The dial provides a mapping from letter to number with the following mapping:
A, B, and C map to 2
D, E, and F map to 3
G, H, and I map to 4
J, K, and L map to 5
M, N, and O map to 6
P, R, and S map to 7
T, U, and V are mapped to 8
W, X, and Y map to 9
Q and Z are not mapped to any numbers, hyphens do not need to be dialed, and can be added and removed arbitrarily. TUT-GLOP standard
The standard format is 888-4567, the standard format for 310-GINO is 310-4466, and the standard format for 3-10-10-10 is 310-1010.
If two numbers have the same standard format, then they are equivalent (same dialing)
Your company is writing a phone book for a local company. As part of quality control, you want to check is
No two or more companies have the same phone number.
Input: The format of the input is that the first line is a positive integer specifying the number of numbers in the phone book (up to 100000).
Each of the remaining lines is a phone number. Each phone number consists of a number, uppercase letters (except Q and Z) and a connector
composition
Output: Produces a line of output for each duplicate number, the output is the standard format of the number followed by a space and then
Is the number of repetitions. If there are multiple duplicate numbers, they are output in ascending order of the number. If there are no duplicate numbers,  
  
Output one line:  
  
No duplicates.  
  
Input sample  
12  
4873279  
ITS-EASY  
888-4567  
3-10-10-10  
888-GLOP  
TUT-GLOP  
967-11-11  
310-GINO  
F101010  
888-1200  
-4-8-7-3-2-7-9-  
487-3279  
  
Output sample  
310-1010 2  
487-3279 4  
888-4567 3  
    
problem analysis  
For ease of memory, phone numbers are translated into words, phrases, and grouped. The same phone number, there are multiple ways of representation. To determine if there is a duplicate number in the entered phone number, there are two issues to be resolved. (1) Convert various phone number representations into standard representations: a string of length 8 with the first three characters being numbers, the fourth character being '-', and the last four characters being numbers. (2) Search for duplicate phone numbers based on the standard representation of the phone number. The solution is to sort all the phone numbers so that the same phone number is placed in an adjacent location. In addition, the title also requires that when a duplicate phone number is output, the output is sorted in ascending order of the number.  
  
solution  
Use a two-dimensional array telNumbers[100000][9] to store all phone numbers, each line storing a standard representation of a phone number. Each time a phone number is read, it is first converted to a standard representation and then stored in a two-dimensional array telNumbers. After all the phone numbers have been entered, the array telNumbers is treated as a one-dimensional array, where each element is a string, sorted by the function template sort pair provided by C/C++. Use the string comparison function strcmp to compare adjacent phone numbers in telNumbers to determine if there are duplicate phone numbers and calculate the number of repetitions.  
  
Implementation skills  
(1) Use a string map to represent the letter-to-number mapping from the telephone dial: map[j] represents the number to which the letter j+'A' is mapped. When converting the entered phone number to a standard form, use map to convert the letters into numbers, simplifying the implementation of the program code. When I first started learning to write programs, I was often accustomed to using data structures to represent facts and relationships in problems, and it was easy to implement this function with a set of conditional judgment statements. Although it can be implemented, the program code does not seem to be concise and error-prone.  
(2) Try to use C/C++ functions to complete the function of the program and simplify the implementation of the program code. In this program, use the function template sort to sort the phone numbers; use the string comparison function strcmp to find duplicate phone numbers.  
(3) Modularize the program, use a separate function as a function, and name the function with a word or phrase. In the above reference program, standardization of telephone numbers is an independent function. It is better to define a function standardizeTel to make the structure of the whole program clear, concise and easy to read. Different program modules need to access the data together, as a global variable, you can simplify the parameter interface of the function, and reduce the parameter transfer overhead of the function call. For example, in the reference program above, the array map and telNumbers are both global variables.  

Common mistakes  
In the output, pay attention to the format requirements of the output data, and distinguish the letter case in the output data:  
(1) When outputting a duplicate telephone number, it is output in the standard format: there is a character '-' between the first three digits and the last four digits of the telephone number.  
(2) When there is no duplicate phone number, the prompt message "No duplicates." is output, and the first letter of the question request message is capitalized.  
