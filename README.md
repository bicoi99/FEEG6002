# FEEG6002 repository

This is Huy Duong repository for the module [FEEG6002](https://www.southampton.ac.uk/courses/modules/feeg6002.page). The cheatsheet below summarises all the material learned (C programming and some Linux related stuff).

## Exam cheatsheet

### Contents

- [Compiling a C programme](#compiling-a-c-programme)
- [Symbolic methods](#symbolic-methods)
- [Data types and variables](#data-types-and-variables)
- [Output](#output)
- [Input](#input)
- [Conditionals](#conditionals)
- [Loops](#loops)
- [Functions](#functions)
- [Symbolic constants](#symbolic-constants)
- [Arrays](#arrays)
- [Pointers](#pointers)
- [Dynamic memory allocation](#dynamic-memory-allocation)
- [Structures](#structures)
- [Files](#files)
- [Command line arguments](#command-line-arguments)
- [Function pointers](#function-pointers)

### Compiling a C programme

Use this command to compile the C programme called `hello.c` to make an executable called `hello`

```bash
gcc -ansi -Wall -pedantic hello.c -o hello
```

`gcc` is the compliler, `-o` tag is to indicate what the executable is going to be called e.g. `gcc <cprogramme.c> -o <executableName>`.

`-ansi` ensures compatibility with C90 standard. `-Wall` enables warnings. `-pedantic` issues all warnings ISO C requires. These tags are specific to this module and is not required normally.

### Symbolic methods

This section is not summarised here since it is unclear whether it will be tested or not.

### Data types and variables

Some common C data types:

- `char` (character): letter like a, b, c, ...
- `int` (integer): integers which can be positive or negative
- `long` (long integer): integers but takes more space
- `float` (float): decimal numbers
- `double` (long float): should be used over `float` in most cases because of higher floating point accuracy
- `unsigned` (unsigned): declares integers (or double) as only positive so that larger number can be stored with same amount of space.
- `bool` (boolean): can only take value of `true` or `false`.

C variables can be created using the syntax `<dataType> <variableName>(=<value>);`. Remember when declaring variables, the data type has to be defined.

C variables or expressions can be type-casted to another datatype using `(dataType) expression`. This converts the result of the `expression` to the `dataType` specified.

`sizeof(dataType)` function can be used to return the number of chars (bytes) of any `dataType`

### Output

`printf` is the C funtion that prints to the stdout (standard output) stream. Note that to use this we need to include a standard IO header file using this line `#include <stdio.h>` at top of script.

Example: `printf("Hello my name is %s and I am %d years old.", "Huy", 22);` print the formatted string and replaces the specifiers `%s` and `%d` with string `"Huy"` and integer `22` respectively.

Example: `printf("%.3f is a decimal number with 3 decimal places", 3.123923);` will print 3.123 rather than the full 6 decimal places because the string is formated.

`putchar(c)` writes `c` to the stdout stream.

### Input

`scanf` (in `stdio.h`) allows user input to be read into the C programme. Example: `scanf("%d", &digit);` will read the user input (in this case an integer) and store that into the variable `digit`.

`c = getchar()` reads single input character from the stdin stream and returns an integer to variable `c`. `EOF` or End Of File is a special macro built into OS and `stdio.h` - usually this is used to test whether the file is done so that we can stop reading the file. `\n` is the special character that signifies the end of a line - used to know when a line has ended

### Conditionals

Conditionals allow action to be carried only is a condition is satisfied. The syntax is as follows:

```c
if (condition)
{
    actionStatement;
}
else if (condition)
{
    actionStatement;
}
else
{
    actionStatement;
}
```

### Loops

`for` loop allows tasks to be repeated a certain number of times. The syntax is as follows:

```c
for (initialiseStep; stopCondition; increment)
{
    actionStatement;
}
```

`while` loop repeat task infinitely while a `condition` is `true`. The syntax is as follows:

```c
while (condition)
{
    actionStatement;
}
```

### Functions

A C programme consists only of functions which can be defined by the following syntax:

```c
returnType functionName(parameterList)
{
    actionStatement;
}
```

`returnType` refers to the data type of the returned value (`void` is nothing is returned). `parameterList` consists of arguments' data types and names e.g. `(int a, double b, char c)`. Arguments are passed in **by value** with this syntax i.e. if a variable is passed into the function, the variable will not be affected by anything that happens within the function. Another method for passing arguments is **by reference**, using *pointers* to be discussed later, which allows for passed in variable to be altered by the function.

Every programme needs a `main` function which will be executed and any other functions defined should be called in here. The syntax of `main` is given in the example below, it takes in no arguments (`void`) and returns integer `0` every time.

```c
#include <stdio.h>

// Function prototype
returnType functionPrototype(parameterList);

int main(void)
{
    actionStatement;
    return 0;
}

// Define the function prototyped above
returnType functionPrototype(parameterList)
{
    actionStatement;
}
```

All functions should be defined before it is referenced e.g. inside `main`. However, a "prototype" can be created using the syntax above to give a short definition of the real function which is fully defined after `main`. This cleans up the code but generally, we define the function fully above `main`.

### Symbolic constants

We use pre-processor `#define` to define any constants to be used in the C programme. The pre-processor runs before compilation and replace any occurance of `name` with `replacement`. Can be accomplished with the following syntax:

```c
#define name replacement
```

### Arrays

Array is a data structure that stores a fixed number of elements of the same type. The following syntax can be used to declare an array called `arrayName` that can store `arraySize` of elements of type `dataType`:

```c
dataType arrayName[arraySize];
```

To access the n-th element of the array, we use `arrayName[n-1]` because elements are indexed from `0` to `arraySize-1`. Usually `arraySize` is set using symbolic constant and set to be larger than what is needed because increasing the size of an array is not straight forward.

A **string** is an array of characters which are often used to store sentences.

### Pointers

#### Pointer syntax

Pointer is a type of variable that stores the memory address of a normal variable. To access the address of variable `c`, we use the `&` operator i.e. `p = &c` gets the address of `c` and stores that into `p` and now `p` points to `c`. To declare a pointer variable (which points to variable of type `dataType`) we use the syntax `datatype *p`. The operator `*` ca be used to dereference a pointer and access the variable that it is pointing to i.e. to access value of `c` we use `*p`.

#### Pass by reference

Pointers can be used to pass arguments into function **by reference** (in the [Functions](#functions) section) i.e. pass a pointer of the variable into the function rather than the variable itself. This allows the function to modify the variable directly.

When an array is passed into a function, `dataType arrayName[]` or `dataType *arrayName` can be used and they are treated as equivalent.

#### Array and pointer

Pointers and arrays are tighly linked as in the `arrayName` of an array is in fact a pointer that points to the first element of the array. The subsequent elements of the array is stored in the subsequent memory block with no gaps in between. Therefore, we can access the other elements by incrementing the pointer value. To access the i-th element of array `c`, `c[i]` and `*(c+i)` are equivalent.

### Dynamic memory allocation

`malloc` function (in `stdlib.h` header file) allows dynamic allocation of memory. This is to ensure all your variables can be assigned without running out of memory. Typical memory allocation syntax is:

```c
c = (int *) malloc(sizeof(int));

if (c == NULL)
{
    printf("Out of memory");
    return -1;
}
actionStatement;

free(c);
```

`malloc(size)` function when called check whether the `size` amount of space is available in the heap. If there is not enough memory, `malloc` returns `NULL` and we check this with a conditional `if` and return `-1` error code. If memory is available, `malloc` assigns and reserves required amount and return the pointer to the reserved block of memory. However, the return type of `malloc` is `void *` (`void` pointer) and so we need to typecast it to the appropriate type (`int *` in this case). Once we finish with the memory block we use `free` to free up the reserved memory.

### Structures

`struct` can be used to group data together with the following syntax:

```c
struct structTag
{
    <memberType> memberName;
};

int main(void)
{
    struct structTag structName = {memberAssignment};
    structName.memberName = newMemberValue
    return 0;
}
```

Here the `structTag` is created which forms a struct that stores members with `memberName`'s (can be more than one). Then in `main` the struct called `structName` is initialised with the `memberAssignment` in place of the variable assignment (correct datatype should be ensured here by the programmer). Finally, a member can be accessed through `structName.memberName` and this can be changed by simple variable assignment.

`struct` can be passed into a function as follows:

```c
struct person
{
    int age;
    double height;
    double weight;
};

void printDetails(struct person A)
{
    printf("A's age is: %d", A.age);
    printf("A's height is: %f", A.height);
    printf("A's weight is: %f", A.weight);
}

int main(void)
{
    struct person FooBar = {10, 1.75, 68.0};
    printDetails(FooBar);
    return 0;
}
```

This programme defines a struct with tag `person` that has members `age`, `height` and `weight`. Then the `printDetails` function that takes one argument that is a person struct called `A` and print out the members of that struct. The function is called in `main` after a `FooBar` person is defined.

To avoid having to type `struct <structTag>` all the time we can use `typedef`. When this is used the `struct <structTag>` can be replaced with only `<structTag>` when referenced after. The previous `person` struct can be defined in a different syntax as follows:

```c
typedef struct
{
    int age;
    double height;
    double weight;
} person;

int main(void)
{
    person FooBar = {10, 1.75, 68.0};
    printf("Age: %d, Height: %f, Weight: %f", FooBar.age, FooBar.height, FooBar.weight);
    return 0;
}
```

### Files

A C programme can read and write any file store on the computer given the `<path>` of the file is known.

Here is an example of opening a file and **write** some text into it:

```c
#include <stdio.h>

int main(void)
{
    // File pointer
    FILE *f;
    // Open file
    if ( (f=fopen("<path>", "w")) == NULL )
    {
        printf("Cannot open file for writing");
        return -1;
    }
    // Write to file
    fprintf(f, "We write the first line to this file using fprintf.\n");
    fprintf(f, "We can also write formatted string with interger %d\n", 1);
    // Close file
    if (fclose(f) != 0)
    {
        printf("Cannot close file");
        return -1;
    }
    return 0;
}
```

The programme first defines a `FILE` pointer `f` (`FILE` type included in `stdio.h`). Then it attempts to open a file with function `fopen`. The tag `"w"` means to open file for writing. If the opening fails, the function returns `NULL` so the programme catches this with a conditional. If the file opening is sucessful, programme proceeds to use `fprintf` to print formatted strings to the file. Once done, the file is closed with `fclose`. If file could not be closed, the function returns a non-zero value.

Reading information from a file can be done with `fgetc` to get character-by-character, line-by-line:

```c
// File pointer
// Open file - fopen("path/to/file", "r")
// Read file - print to stdout all characters until EOF is reached
while ( (c=fgetc(f))!=EOF )
{
    printf("%c", c)
}
// Close file
```

Or `fscanf` can extract information in a line and save it to variable when the format of read file is a known (i.e. a formatted string):

```c
char str1[10], str2[10], str3[10];
int year;
FILE *f;
// Open file for reading
fscanf(f, "%s %s %s %d", str1, str2, str3, &year);
// Close file
```

This [programme](https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm) when used to read a file with the line of text "This year is 2021" variables will be: `str1` is "This", `str2` is "year", `str3` is "is" and `year` is 2021. `fscanf` takes in the pointer to the variables to store the extracted information to. The string variable names are already pointer to the character arrays so they are passed directly, however the address of `year` has to be accessed with `&` since `year` is an integer.

### Command line arguments

When the C programme is complied into an executable, that executable can be called with some arguments. These arguments are programmed as arguments to the `main` function:

```c
int main(int argc, char *argv[])
{
    int i;
    for (i=0; i<argc; i++) {
        printf("Argument %d = ’%s’\n", i, argv[i]);
    }
    return 0;
}
```

When this programme (name `args`) is compiled into an executable and called with `./args Hello world` then Argument 0 is `./args`, Argument 1 is `Hello` and Argument 2 is `world`.

### Function pointers

Function pointers allow functions to be passed in as arguments to other functions using the following syntax: `returnType (*functionName)(inputType 1, inputType 2, ...)` where number of `inputTypes` is the number of `functionName` function arguments.
