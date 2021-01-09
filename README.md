# FEEG6002 repository

This is Huy Duong repository for the module [FEEG6002](https://www.southampton.ac.uk/courses/modules/feeg6002.page). The cheatsheet below summarises all the material learned (C programming and some Linux related stuff).

## Exam cheatsheet

### Contents

- [Compiling a C programme](#compiling-a-c-programme)
- [Symbolic methods](#symbolic-methods)
- [Data types and variables](#data-types-and-variables)
- [Printing](#printing)
- [Scanning](#scanning)
- [Conditionals](#conditionals)
- [Loops](#loops)

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

C variables can be created using the syntax `<dataType> <variableName>(=<value>);`. Remember when declaring variables, the data type has to be defined.

C variables or expressions can be type-casted to another datatype using `(dataType) expression`. This converts the result of the `expression` to the `dataType` specified.

### Printing

`printf` is the C funtion that prints to the stdout (standard output) stream. Note that to use this we need to include a standard IO header file using this line `#include <stdio.h>` at top of script.

Example: `printf("Hello my name is %s and I am %d years old.", "Huy", 22);` print the formatted string and replaces the specifiers `%s` and `%d` with string `"Huy"` and integer `22` respectively.

Example: `printf("%.3f is a decimal number with 3 decimal places", 3.123923);` will print 3.123 rather than the full 6 decimal places because the string is formated.

### Scanning

`scanf` (in `stdio.h`) allows user input to be read into the C programme.

Example: `scanf("%d", &digit);` will read the user input (in this case an integer) and store that into the variable `digit`.

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

<!-- Lecture 3 continue -->