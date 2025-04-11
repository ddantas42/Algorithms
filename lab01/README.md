# Algorithm tester
This is a C program design to test the effiency of 3 algorithms: sequencial, binary and jump search in intege arrays.
The program will get an integer array and then execute the three searches, calculating the time it takes for each one.

## Usage
To compile que program, simple use a C compiler and the source files (*.c) as arguments, and with the flag "-lm" to enable the math library
```bash
gcc main.c _aux.c init.c -lm
```
After compilation, there's is two ways to use the program.\
No arguments means the program will ask for them directly including the size of the array.\
If there is arguments, the program will use them as the array in that order.\
Following the declaration of the array, it will prompt an input for an integer to search.
To execute the program just execute the executable generated
```bash
./a.out [Arguments...]
```

To use many random numbers as arguments, we can take advantage of the command shuf and sort
```bash
shuf -i A-B -n X | sort -n
```
This linux command will generate a list of X numbers from A to B non-repeatable and sort them, so we can use it's output as arguments

So if we want to execute the program with numbers from 1 to 100 000 sorted, we do like so
```bash
./a.out $(shuf -i 1-100000 -n 100000 | sort -n)
```

If the argument limit is reached, you can use the command to output to a file, then put in the top of the file how many numbers (using sed) the array will have, and at the bottom what the element the algorithm is searching for (using echo), then use the file as input.
In the following example we are putting X numbers from A to B, and Y as the number to search for
```bash
shuf -i A-B -n X | sort -n > input.txt
sed -i '1i X' input.txt
echo 'Y' >> input.txt
./a.out < input.txt
```
Example use for 1 000 000 numbers from 1 to 1 000 000, and searching for the number 1 000 000 (worst case scenario for all the algorithms in this program) 
```bash
shuf -i 1-1000000 -n 1000000 | sort -n > input.txt
sed -i '1i 1000000' input.txt
echo '1000000' >> input.txt
./a.out < input.txt
```