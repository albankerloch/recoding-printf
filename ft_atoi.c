/**
 * @file ft_atoi.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Replication of the isspace function
 * @param c: one character
 * @retval 1 if the character is a space
 * @retval 0 if the character is not a space
 */
static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
	c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

/**
 * @brief Replication of the atoi function
 * @param str: a string containing a number (positive or negative)
 * @return the number extracted from the string
 */
int			ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
