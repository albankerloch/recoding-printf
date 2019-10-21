/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:44:18 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/21 18:54:00 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"
#include <stdio.h>


int main()
{
	int *p;
	int a;

	a = 1;
	p = &a;

	printf("vrai : %5d\n", 10);
	ft_printf("faux : %5d\n", 10);

	printf("vrai : %10d %10s, %5i\n", 100, "coucou", 40);
	ft_printf("faux : %10d %10s, %5i\n", 100, "coucou", 40);

	printf("vrai : %5d\n", 40);
	ft_printf("faux : %5d\n", 40);

//	printf("vrai : %*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);
//	ft_printf("faux : %*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);

//	printf("vrai : |%027.p|\n", p);
//	ft_printf("faux : |%027.p|\n", p);

//	printf("1|%10.50.**--*dcsdp%d|\n", -25, -15, -5, -33, 4, 6, -4897987565423, 123);
//	ft_printf("2|%10.50.**--*dcsdp%d|\n", -25, -15, -5, -33, 4, 6, -4897987565423, 123);

//	ft_printf("1-%*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);
//	printf("2-%*d %*s, %*i\n", 10, 10, 5, "coucou", 4, 40);
//printf("vrai : |%*.**s|\n", 10, 10, "ahaha");
//	ft_printf("faux : |%*.**s|\n", 10, 10, "hahah");

/*	printf("vrai : |%-7d|\n", a);
	printf("vrai : |%-*d|\n", 7, a);


	printf("vrai : |%.*d|\n", 10, a);
	ft_printf("faux : |%.*d|\n", 10, a);*/

//	printf("vrai : |%p|\n", p);
//	ft_printf("faux : |%p|\n", p);

/*	char *var1;

	var1 = test;

	printf("vrai : %.0%\n");
	ft_printf("faux : %.0%\n");

	printf("vrai :%%\n", "test");
	ft_printf("faux :%%\n", "test");

	printf("%%\n");
	ft_printf("%%\n");

	printf("%5%\n");
	ft_printf("%5%\n");

	printf("%.0%\n");
	ft_printf("%.0%\n");

	printf("%%\n", "test");
	ft_printf("%%\n", "test");

	printf("vrai :%.2c essai\n", NULL);
	ft_printf("faux :%.2c essai\n", NULL);

	printf("vrai :%10s essai\n", NULL);
	ft_printf("faux :%10s essai\n", NULL);


	ft_printf("faux :@moulitest: %d %d\n", 0, 0);

	ft_printf("2vrai :@moulitest: %.d %.0d\n", 0, 0);
	ft_printf("3vrai :@moulitest: %.d %.0d\n", 1, -5);
	ft_printf("4vrai :@moulitest: %.1d %.5d\n", 0, 0);
	ft_printf("5faux :@moulitest: %.d %.0d\n", 0, 0);
	ft_printf("6vrai :@moulitest: %.d\n", 0, 0);
	ft_printf("7vrai :@moulitest: %5.i\n", 0, 0);
	ft_printf("8vrai :@moulitest: %.u %.1u\n", 1, 0);
	ft_printf("9xvrai :@moulitest: %x %x %.x\n", 1, 0, 0);
	ft_printf("10xvrai :@moulitest: %i %i %.i\n", 1, 0, 0);

	ft_printf("faux :%u\n", -2);
	ft_printf("faux :%u\n", 4294967295);
	printf("vrai :%u\n", -2);
	printf("vrai :%u\n", 4294967295);

	ft_printf("faux :%x\n", -42);
	ft_printf("faux :%x\n", 4294967254);
	printf("vrai :%x\n", -42);
	printf("vrai :%x\n", 4294967254);
*/
/*
	ft_printf("faux :% Z\n");
	printf("vrai :% Z\n");

	ft_printf("faux :%Z\n");
	printf("vrai :%Z\n");

	ft_printf("faux :%Z\n");
	printf("vrai :%Z\n");


//	ft_printf(" %%\n");
//	printf(" %%\n");
//	ft_printf("7faux :@moulitest: %.d %.0d\n", 0, 0);
//	printf("7vrai :@moulitest: %.d %.0d\n", 0, 0);

//	ft_printf(" --- \n");
//	printf("vrai :@moulitest: %5.d %5.0d\n", 0, 0);
//	printf("vrai :@moulitest: %1.0d %1.1d\n", 0, 0);
//	ft_printf("faux :@moulitest: %5.d %5.0d\n", 0, 0);
//	ft_printf("faux :@moulitest: %.d %.0d\n", 0, 0);


//	printf("truprintf |%s \n", var1);
//	ft_printf("ft_printf |%s \n", var1);

	int number;
	int t;

	number = -17;
	t = 6;

//	   printf("truprintf |%-10.5d \n", number);
//	ft_printf("ft_printf |%-10.5d \n", number);

    ft_printf(" %-10d \n", number);
    ft_printf(" %010d \n", number);
    ft_printf(" %-010d \n", number);
    ft_printf(" %0-10d \n", number);
    ft_printf(" %10d \n", number);
    ft_printf(" %5d \n", number);
    ft_printf(" %*d \n", t, number);
    ft_printf(" %1.2d \n", number);
    ft_printf(" %10.20d \n", number);
    ft_printf(" %10.2d \n", number);
    ft_printf(" %.2d \n", number);
	// min = 0
	ft_printf(" %1.d \n", number);
	//max = 0
	t = 300;
	ft_printf(" %20.*d \n", t, number);

*/
/*
	char var;

	var = '\0';

	ft_printf("essai |%c| fin", var);

//test char
	ft_printf("012%*.*c56789\n", 20, 20, var);
	ft_printf("-1 %*.*c-- %% fin\n", 7, 5, var);
	ft_printf("-1 %*.*c-- %% fin\n", 7, 10, var);
	ft_printf("-1 %*.*c-- %% fin\n", 0, 5, var);
	ft_printf("-1 %*.*c-- %% fin\n", 0, 0, var);
	ft_printf("-1 %*.*c-- %% fin\n", 7, 7, var);
	
//test flag -
	ft_printf("-1 %0*.*c-- %% fin\n", 7, 3, var);
	ft_printf("-1 %0*.*c-- %% fin\n", 7, 5, var);
	ft_printf("-1 %0*.*c-- %% fin\n", 7, 10, var);
	ft_printf("-1 %0*.*c-- %% fin\n", 0, 5, var);
	ft_printf("-1 %0*.*c-- %% fin\n", 0, 0, var);
	ft_printf("-1 %0*.*c-- %% fin\n", 7, 7, var);

//test flag 0
	ft_printf("-1 %-*.*c-- %% fin\n", 7, 3, var);
	ft_printf("-1 %-*.*c-- %% fin\n", 7, 5, var);
	ft_printf("-1 %-*.*c-- %% fin\n", 7, 10, var);
	ft_printf("-1 %-*.*c-- %% fin\n", 0, 5, var);
	ft_printf("-1 %-*.*c-- %% fin\n", 0, 0, var);
	ft_printf("-1 %-*.*c-- %% fin\n", 7, 7, var);


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

	ft_printf("-2 %0*.*s-- %% fin\n", 7, 3, var1);
	ft_printf("-1 %0*.*s-- %% fin\n", 7, 5, var1);
	ft_printf("-1 %0*.*s-- %% fin\n", 7, 10, var1);
	ft_printf("-1 %0*.*s-- %% fin\n", 0, 5, var1);
	ft_printf("-1 %0*.*s-- %% fin\n", 0, 0, var1);
	ft_printf("-1 %0*.*s-- %% fin\n", 7, 7, var1);

	ft_printf("-3 %-*.*s-- %% fin\n", 7, 3, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 7, 5, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 7, 10, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 0, 5, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 0, 0, var1);
	ft_printf("-1 %-*.*s-- %% fin\n", 7, 7, var1);
*/
	return (0);
}
