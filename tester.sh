#!/bin/bash
cp main.c main2.c
sed -i -- 's/ft_printf/printf/g' main2.c
make && gcc main.c -L. -lftprintf -o a.out
./a.out > test
make && gcc main2.c -L. -lftprintf -o a2.out
./a2.out > test2
diff test test2