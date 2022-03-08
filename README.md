## ft_printf

project of École 42 where it is necessary to implement own printf function in C using only va_arg and write functions.

the function works just like the original function from stdio.h library with certain specifiers and specific flags.

all functions written in the project were implemented independently without using standard libraries.

the project was made in accordance with the school design code standard in C language.

### how to use
```
make
gcc main.c -L. libftprintf.a
./a.out
```

### list of specifiers

| specifier | description |
| ------------ | ------------ |
| c | outputs any character from ascii table |
| s | outputs a null-terminated string |
| p | outputs a pointer memory address |
| d | outputs an integer in decimal notation |
| i | outputs an integer in decimal notation |
| u | outputs unsigned decimal base |
| x | outputs unsigned hex base |

### list of flags

| flag | description |
| ------------ | ------------ |
| - | left-align text with the specified width |
| (number). | minimum number of characters to output as a width |
| .(number) | precision of minimum number of characters to output |
