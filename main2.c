/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:44:18 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/20 15:47:11 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"
#include <stdio.h>


int main()
{
/*	char *var1;

	var1 = test;

	printf("vrai : %.0%\n");
	printf("faux : %.0%\n");

	printf("vrai :%%\n", "test");
	printf("faux :%%\n", "test");

	printf("%%\n");
	printf("%%\n");

	printf("%5%\n");
	printf("%5%\n");

	printf("%.0%\n");
	printf("%.0%\n");

	printf("%%\n", "test");
	printf("%%\n", "test");

	printf("vrai :%.2c essai\n", NULL);
	printf("faux :%.2c essai\n", NULL);

	printf("vrai :%10s essai\n", NULL);
	printf("faux :%10s essai\n", NULL);


	printf("faux :@moulitest: %d %d\n", 0, 0);

	printf("2vrai :@moulitest: %.d %.0d\n", 0, 0);
	printf("3vrai :@moulitest: %.d %.0d\n", 1, -5);
	printf("4vrai :@moulitest: %.1d %.5d\n", 0, 0);
	printf("5faux :@moulitest: %.d %.0d\n", 0, 0);
	printf("6vrai :@moulitest: %.d\n", 0, 0);
	printf("7vrai :@moulitest: %5.i\n", 0, 0);
	printf("8vrai :@moulitest: %.u %.1u\n", 1, 0);
	printf("9xvrai :@moulitest: %x %x %.x\n", 1, 0, 0);
	printf("10xvrai :@moulitest: %i %i %.i\n", 1, 0, 0);

	printf("faux :%u\n", -2);
	printf("faux :%u\n", 4294967295);
	printf("vrai :%u\n", -2);
	printf("vrai :%u\n", 4294967295);

	printf("faux :%x\n", -42);
	printf("faux :%x\n", 4294967254);
	printf("vrai :%x\n", -42);
	printf("vrai :%x\n", 4294967254);
*/
/*
	printf("faux :% Z\n");
	printf("vrai :% Z\n");

	printf("faux :%Z\n");
	printf("vrai :%Z\n");

	printf("faux :%Z\n");
	printf("vrai :%Z\n");


//	printf(" %%\n");
//	printf(" %%\n");
//	printf("7faux :@moulitest: %.d %.0d\n", 0, 0);
//	printf("7vrai :@moulitest: %.d %.0d\n", 0, 0);

//	printf(" --- \n");
//	printf("vrai :@moulitest: %5.d %5.0d\n", 0, 0);
//	printf("vrai :@moulitest: %1.0d %1.1d\n", 0, 0);
//	printf("faux :@moulitest: %5.d %5.0d\n", 0, 0);
//	printf("faux :@moulitest: %.d %.0d\n", 0, 0);


//	printf("truprintf |%s \n", var1);
//	printf("printf |%s \n", var1);

/*	int number;
	int t;

	number = -17;
	t = 6;

//	   printf("truprintf |%-10.5d \n", number);
//	printf("printf |%-10.5d \n", number);

    printf(" %-10d \n", number);
    printf(" %010d \n", number);
    printf(" %-010d \n", number);
    printf(" %0-10d \n", number);
    printf(" %10d \n", number);
    printf(" %5d \n", number);
    printf(" %*d \n", t, number);
    printf(" %1.2d \n", number);
    printf(" %10.20d \n", number);
    printf(" %10.2d \n", number);
    printf(" %.2d \n", number);
	// min = 0
	printf(" %1.d \n", number);
	//max = 0
	t = 300;
	printf(" %20.*d \n", t, number);

*/

	char var;

	var = '\0';

	printf("essai |%c| fin", var);
/*
//test char
	printf("012%*.*c56789\n", 20, 20, var);
	printf("-1 %*.*c-- %% fin\n", 7, 5, var);
	printf("-1 %*.*c-- %% fin\n", 7, 10, var);
	printf("-1 %*.*c-- %% fin\n", 0, 5, var);
	printf("-1 %*.*c-- %% fin\n", 0, 0, var);
	printf("-1 %*.*c-- %% fin\n", 7, 7, var);
	
//test flag -
	printf("-1 %0*.*c-- %% fin\n", 7, 3, var);
	printf("-1 %0*.*c-- %% fin\n", 7, 5, var);
	printf("-1 %0*.*c-- %% fin\n", 7, 10, var);
	printf("-1 %0*.*c-- %% fin\n", 0, 5, var);
	printf("-1 %0*.*c-- %% fin\n", 0, 0, var);
	printf("-1 %0*.*c-- %% fin\n", 7, 7, var);

//test flag 0
	printf("-1 %-*.*c-- %% fin\n", 7, 3, var);
	printf("-1 %-*.*c-- %% fin\n", 7, 5, var);
	printf("-1 %-*.*c-- %% fin\n", 7, 10, var);
	printf("-1 %-*.*c-- %% fin\n", 0, 5, var);
	printf("-1 %-*.*c-- %% fin\n", 0, 0, var);
	printf("-1 %-*.*c-- %% fin\n", 7, 7, var);


	char var1[10]="test";
	char var2[10]="vvvv";
	char var3[10]="vemt";

	printf("printf |%s \n", var1);
	printf("printf |s \n");
	printf("-1 %*.*s-- %% fin\n", 7, 3, var1);
	printf("-1 %*.*s-- %% fin\n", 7, 5, var1);
	printf("-1 %*.*s-- %% fin\n", 7, 10, var1);
	printf("-1 %*.*s-- %% fin\n", 0, 5, var1);
	printf("-1 %*.*s-- %% fin\n", 0, 0, var1);
	printf("-1 %*.*s-- %% fin\n", 7, 7, var1);

	printf("-2 %0*.*s-- %% fin\n", 7, 3, var1);
	printf("-1 %0*.*s-- %% fin\n", 7, 5, var1);
	printf("-1 %0*.*s-- %% fin\n", 7, 10, var1);
	printf("-1 %0*.*s-- %% fin\n", 0, 5, var1);
	printf("-1 %0*.*s-- %% fin\n", 0, 0, var1);
	printf("-1 %0*.*s-- %% fin\n", 7, 7, var1);

	printf("-3 %-*.*s-- %% fin\n", 7, 3, var1);
	printf("-1 %-*.*s-- %% fin\n", 7, 5, var1);
	printf("-1 %-*.*s-- %% fin\n", 7, 10, var1);
	printf("-1 %-*.*s-- %% fin\n", 0, 5, var1);
	printf("-1 %-*.*s-- %% fin\n", 0, 0, var1);
	printf("-1 %-*.*s-- %% fin\n", 7, 7, var1);
*/
	return (0);
}
