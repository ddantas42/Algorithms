# Algorithm tester
This is a C program design to test the effiency and compare de number of operations performed of 4 algorithms: Bubble Sort, Bubble Sort Optimized, Selection Sort and Select Sort in intege arrays.
The program will then create an array using the two macros: SIZE and ORDER.
ORDER is the order of the array generated (0 for ascending, 1 for descending)
SIZE if the size of the array alocated
So for example, an ORDER of 1 and SIZE of 5 will generate the following array:
```
[ 5 4 3 2 1 ]
```

## Usage
To compile que program, simple use a C compiler and the source files (*.c) as arguments
```bash
gcc main.c algos.c array_aux.c
```
Although, there's is two ways to use the program.\
No extra flags means the program will use the values of the macros SIZE and ORDER that are in the lab02.h file
If you want to set the macros at compilation, you need to specify them using the -D flag
To compile que program use -D flag to set the macros values as so
```bash
gcc main.c algos.c array_aux.c -DSIZE=10 -DORDER=1
```
And that's is! Now just execute.
```bash
./a.out
```