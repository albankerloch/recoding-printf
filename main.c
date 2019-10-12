/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:44:18 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/12 18:16:19 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


int main()
{
	char str[100]="%s %% %s \n";
	int i;
	int t;
	int number;
	char var1[10]="test";
	char var2[10]="vvvv";
	char var3[10]="vemt";

	t = -1;
	i = 54;
//	printf("%s %i %% %-i\n", str, t, i);
	ft_printf(str, var1, var2);
	printf(str, var1, var2);


	number = 17;
	t = 6;
    printf(" %-10d \n", number);
    printf(" %010d \n", number);
    printf(" %10d \n", number);
    printf(" %5d \n", number);
    printf(" %*d \n", t, number);

    printf(" %1.2s \n", var1);
    printf(" %10.20s \n", var1);
    printf(" %10.2s \n", var1);
    printf(" %.2s \n", var1);
	// min = 0
	printf(" %1.s \n", var1);
	//max = 0
	t = 3;
	printf(" %.*s \n", t, var1);

	return (0);
}
