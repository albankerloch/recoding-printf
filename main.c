/* updated: 19/10/2019 */
/* main.c by alban kerloc'h */

#include "libftprint.h"
#include <stdio.h>


int main()
{

	ft_printf("faux : %5d\n", 10);
	ft_printf("faux : %10d %10s, %5i\n", 100, "coucou", 40);
	ft_printf("faux : %5d\n", 40);	
	ft_printf("faux : %*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);
	ft_printf("faux : %5d\n", 40);
	ft_printf("faux : %*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);
	ft_printf("1-%*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);

	ft_printf("%%\n");
	ft_printf("2vrai %.d %.0d\n", 0, 0);
	ft_printf("3vrai %.d %.0d\n", 1, -5);
	ft_printf("4vrai %.1d %.5d\n", 0, 0);
	ft_printf("5faux %.d %.0d\n", 0, 0);
	ft_printf("8vrai %.u %.1u\n", 1, 0);
	ft_printf("9vrai %x %x %.x\n", 1, 0, 0);
	ft_printf("10vrai %i %i %.i\n", 1, 0, 0);

	ft_printf("faux :%u\n", -2);
	ft_printf("faux :%x\n", -42);

	int number;
	int t;

	number = -17;
	t = 6;

    ft_printf("faux : |%.*d|\n", 10, t);
	ft_printf(" %010d \n", number);
    ft_printf(" %10d \n", number);
    ft_printf(" %5d \n", number);
    ft_printf(" %*d \n", t, number);
    ft_printf(" %1.2d \n", number);
    ft_printf(" %10.20d \n", number);
    ft_printf(" %10.2d \n", number);
    ft_printf(" %.2d \n", number);

	char var1[10]="test";
	char var2[10]="vvvv";
	char var3[10]="vemt";

	ft_printf("printf |%s \n", var1);
	ft_printf("printf |s \n");

	ft_printf("-1 %*.*s-- %% fin\n", 7, 3, var1);
	ft_printf("-1 %*.*s-- %% fin\n", 7, 5, var1);
	ft_printf("-1 %*.*s-- %% fin\n", 7, 10, var1);
	ft_printf("-1 %*.*s-- %% fin\n", 0, 5, var1);
	ft_printf("-1 %*.*s-- %% fin\n", 0, 0, var1);
	ft_printf("-1 %*.*s-- %% fin\n", 7, 7, var1);

	ft_printf("-3 %-*.*s-- %% fin\n", 7, 3, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 7, 5, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 7, 10, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 0, 5, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 0, 0, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 7, 7, var1);

	return (0);
}
