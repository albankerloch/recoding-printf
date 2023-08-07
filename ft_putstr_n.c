/**
 * @file ft_putstr_n.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Write a string with a NULL protection
 * @param s: string
 * @param i: length of the string
 */
void	ft_putstr_n(char *s, int i)
{
	if (s == NULL)
		return ;
	write(1, s, i);
}
