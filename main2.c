/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:44:18 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/16 11:31:02 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"
#include <stdio.h>


int main()
{
	int number;
	int t;

	number = -17;
	t = 6;

//   printf("%3.5d \n", number);
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

/*
	char var1;

	var1 = '3';

//test char
	printf("012%*.*c56789\n", 20, 20, var1);
	printf("-1 %*.*c-- %% fin\n", 7, 5, var1);
	printf("-1 %*.*c-- %% fin\n", 7, 10, var1);
	printf("-1 %*.*c-- %% fin\n", 0, 5, var1);
	printf("-1 %*.*c-- %% fin\n", 0, 0, var1);
	printf("-1 %*.*c-- %% fin\n", 7, 7, var1);
	
//test flag -
	printf("-1 %0*.*c-- %% fin\n", 7, 3, var1);
	printf("-1 %0*.*c-- %% fin\n", 7, 5, var1);
	printf("-1 %0*.*c-- %% fin\n", 7, 10, var1);
	printf("-1 %0*.*c-- %% fin\n", 0, 5, var1);
	printf("-1 %0*.*c-- %% fin\n", 0, 0, var1);
	printf("-1 %0*.*c-- %% fin\n", 7, 7, var1);

//test flag 0
	printf("-1 %-*.*c-- %% fin\n", 7, 3, var1);
	printf("-1 %-*.*c-- %% fin\n", 7, 5, var1);
	printf("-1 %-*.*c-- %% fin\n", 7, 10, var1);
	printf("-1 %-*.*c-- %% fin\n", 0, 5, var1);
	printf("-1 %-*.*c-- %% fin\n", 0, 0, var1);
	printf("-1 %-*.*c-- %% fin\n", 7, 7, var1);
*/
/*
	char var1[10]="test";
	char var2[10]="vvvv";
	char var3[10]="vemt";

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
