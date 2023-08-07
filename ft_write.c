/**
 * @file ft_write.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief affect the output of a string replacement
 * @param s: string (allocated in memory)
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_write_s(char *s, va_list ap, size_t *t)
{
	char	*var1;
	size_t	k;
	size_t	m;

	var1 = va_arg(ap, char*); /** access the next argument */
	m = t[3] < ft_strlen(var1) ? t[3] : ft_strlen(var1); /** take in account a length specifier if there is one */
	if (t[2] > m && t[4] != 1)
		ft_fill_caract(s, t[2] - m, t, (t[4] == 2 ? '0' : ' '));
	if (!(var1))
		var1 = "(null)"; /** replace by (null) if there is no next argument */
	k = 0;
	while (k < ft_strlen(var1) && k < t[3])
	{
		s[t[1]] = var1[k];
		t[1]++;
		k++;
	}
	if (t[2] > m && t[4] == 1)
		ft_fill_caract(s, t[2] - m, t, ' ');
}

/**
 * @brief affect the output of a characters replacement
 * @param s: string (allocated in memory)
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_write_c(char *s, va_list ap, size_t *t)
{
	char	var1;

	var1 = (char)va_arg(ap, int); /** access the next argument */
	if (t[2] > 0 && t[4] != 1)
		ft_fill_caract(s, t[2] - 1, t, (t[4] == 2 ? '0' : ' '));
	s[t[1]] = var1;
	t[1]++;
	if (t[2] > 0 && t[4] == 1)
		ft_fill_caract(s, t[2] - 1, t, ' ');
}

/**
 * @brief affect the output of a replacement by a % character
 * @param s: string (allocated in memory)
 * @param t: counter structure
 */
void		ft_write_prct(char *s, size_t *t)
{
	if (t[2] > 0 && t[4] != 1)
		ft_fill_caract(s, t[2] - 1, t, (t[4] == 2 ? '0' : ' '));
	s[t[1]] = '%';
	t[1]++;
	if (t[2] > 0 && t[4] == 1)
		ft_fill_caract(s, t[2] - 1, t, ' ');
}

/**
 * @brief affect the output of a pointer replacement
 * @param s: string (allocated in memory)
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_write_p(char *s, va_list ap, size_t *t)
{
	void			*var1;
	unsigned int	var2;

	var1 = va_arg(ap, void*); /** access the next argument */
	if (var1 < 0)
	{
		var2 = (unsigned long)var1;
		ft_fill_left_p(s, (long)var2, "0123456789abcdef", t);
	}
	else
		ft_fill_left_p(s, (long)var1, "0123456789abcdef", t);
}

/**
 * @brief affect the output of a number replacement
 * @param s: string (allocated in memory)
 * @param ap: va_list
 * @param t: counter structure
 * @param conv: conversion type
 */
void		ft_write_d(char *s, va_list ap, size_t *t, char conv)
{
	int				var1;
	unsigned int	var2;

	var1 = va_arg(ap, int); /** access the next argument */
	if (conv == 'i' || conv == 'd' || (conv == 'u' && var1 >= 0))
		ft_fill_left(s, var1, "0123456789", t);
	if (conv == 'x' && var1 >= 0)
		ft_fill_left(s, var1, "0123456789abcdef", t);
	if (conv == 'X' && var1 >= 0)
		ft_fill_left(s, var1, "0123456789ABCDEF", t);
	if (var1 < 0) 
		var2 = (unsigned int)var1; /** cast the argument into an unsigned int if it is negative for an hexadecimal or  unsigned int replacement */
	if (conv == 'u' && var1 < 0)
		ft_fill_left(s, var2, "0123456789", t);
	if (conv == 'x' && var1 < 0)
		ft_fill_left(s, var2, "0123456789abcdef", t);
	if (conv == 'X' && var1 < 0)
		ft_fill_left(s, var2, "0123456789ABCDEF", t);
}
