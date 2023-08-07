/**
 * @file ft_strlen.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Replication of the strlen function
 * @param str: a string
 * @return the size of the string
 */
size_t	ft_strlen(const char *str)
{
	int		a;

	a = 0;
	if (!(str))
		return (0);
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}
