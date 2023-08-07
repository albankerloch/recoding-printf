/**
 * @file ft_isdigit.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Replication of the isdigit function
 * @param i: one integer
 * @retval 1 if the integer has only one digit
 * @retval 0 if the integer has more than one digit
 */
int		ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (i);
	else
		return (0);
}

/**
 * @brief Replication of the max function
 * @param n1: an number
 * @param n2: another number
 * @return the greater number
 */
size_t	ft_max(size_t n1, size_t n2)
{
	size_t m;

	m = -1;
	if (n1 == m)
		return (n2);
	if (n2 == m)
		return (n1);
	if (n1 > n2)
		return (n1);
	return (n2);
}
