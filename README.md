# Welcome to My Printf
***

## Task
The goal of this project is to create my own version of the printf() function in C.

The main challenge is to understand and use variadic functions with va_list, va_start, va_arg, and va_end.

My my_printf() function can print different types of data using format specifiers.
## Description
I created my_printf() using small helper functions.

The function supports these format specifiers:

%c - prints a character
%s - prints a string
%d - prints a signed integer
%o - prints an octal number
%u - prints an unsigned decimal number
%x - prints a hexadecimal number
%p - prints a pointer address
%% - prints the % character

I used write() to print characters and stdarg.h to work with variable arguments.

I also separated the different conversions into different functions to make the code easier to understand and maintain.
## Installation
No special installation is needed.

Compile the project with:

gcc -Wall -Wextra -Werror my_printf.c test.c -o my_printf

Then run it with:

./my_printf
## Usage
The function can be used like the standard printf() function.
### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
