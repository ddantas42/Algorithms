# Algorithm tester
This is a C program design to test the effiency and compare de number of operations performed of 5 algorithms: Bubble Sort, 2x Bubble Sort Optimized, Selection Sort and Insetion Sort in intege arrays.
The program will then create an array using the two macros: ```SIZE``` and ```ORDER```.
ORDER is the order of the array generated (0 for ascending, 1 for descending, 2 for random)
SIZE is the size of the array alocated
So for example, an ```ORDER``` of 1 and ```SIZE``` of 5 will generate the following array:
```
[ 5 4 3 2 1 ]
```

## Usage
To compile que program, simply use ```make``` so the programs compiles and generates an executable called "algos" with the command:
```bash
make all
```
And that's it! now simply execute
```bash
./algos
```

After you can use ```make clean``` to clean every object and the executable created.
To clean and recompile you can use ```make re```.

## Customization
If you wish to add your own algorithms, or filter the output, simply comment or alter the function on the structure on main calls.
The ```ORDER``` and ```SIZE``` macros can be defined on the inc/lab02.h file