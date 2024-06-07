# Recoding printf

For pedagogical purposes, I redid the printf function for those conversions : 
- c: char
- s: const char *
- p: pointer, type void * printed en hexadecimal
- d: signed int
- i: signed int
- u: unsigned int
- x: signed hexadecimal with abcdef
- X: unsigned hexadecimal  with ABCDEF
- %: a « % » character is printed


Features:
- Write on the terminal replacing the correct variable (ex: %c, 't')
- Take the with and the precision in account (ex: "%-5.2s is a string", "this" -> "th is a string")
- Take order in account
- No memory leak
- No more than 25 lines for each function

## Installation

Use this command in a terminal : 

```bash
make
```

(make and clang needed)

## Usage

- Add #include "libftprint.h" in a C file (like in main.c)

```bash
gcc main.c -L. -lftprintf -o a.out
sh ./tester.sh
```

#### Author : Alban Kerloc'h
#### Category: Low-level
#### Tag: C
