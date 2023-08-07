/**
 * @file ft_check.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Determination of the flag 1
 * @param format: string
 * @param i: counter structure
 * @retval 1 if 
 * @retval 2 if 
 */
size_t			ft_checkflag1(const char *format, size_t *i)
{
	size_t option;

	option = 0;
	while (format[*i + 1] == '0' | format[*i + 1] == '-')
	{
		if (option != 1 && format[*i + 1] == '0')
			option = 2;
		else
			option = 1;
		*i = *i + 1;
	}
	return (option);
}

/**
 * @brief Determination of the precision specifier of the conversion
 * @param ap: va_list
 * @param format: string
 * @param i: counter structure
 * @return the value of the precision specifier (0 if there is no precision specifier)
 */
size_t			ft_checktaille_min(va_list ap, const char *format, size_t *i)
{
	size_t	var1;
	size_t	j;
	int		t;

	if (format[*i + 1] == '*')
	{
		t = va_arg(ap, int);
		var1 = (size_t)t;
		var1 = t < 0 ? (size_t)(-t) : (size_t)(t);
		if (t < 0)
			i[4] = 1;
		*i = *i + 1;
		return (var1);
	}
	else if (ft_isdigit(format[*i + 1]))
	{
		j = *i;
		while (ft_isdigit(format[*i + 1]))
			*i = *i + 1;
		return (ft_atoi(&format[j + 1]));
	}
	return (0);
}

/**
 * @brief Determination of the length specifier of the conversion
 * @param ap: va_list
 * @param format: string
 * @param i: counter structure
 * @return the value of length specifier (0 if there is no precision specifier)
 */
size_t			ft_checktaille_max(va_list ap, const char *format, size_t *i)
{
	size_t	taille_max;
	size_t	j;
	int		t;

	taille_max = -1;
	if (format[*i + 1] == '.')
	{
		*i = *i + 1;
		if (format[*i + 1] == '*')
		{
			t = va_arg(ap, int);
			taille_max = t < 0 ? (size_t)(-1) : (size_t)(t);
			*i = *i + 1;
			return (taille_max);
		}
		else if (ft_isdigit(format[*i + 1]))
		{
			j = *i;
			while (ft_isdigit(format[*i + 1]))
				*i = *i + 1;
			return (ft_atoi(&format[j + 1]));
		}
		return (0);
	}
	return (taille_max);
}
