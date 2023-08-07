/**
 * @file ft_printf.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Check if a type is part of a list of types
 * @param conv: a character of a type
 * @param s: a list of type
 * @retval 1 if the type is part of the list
 * @retval 0 if the type isn't part of the list
 */
int				ft_isconv(char conv, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (conv == s[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Affect the output of a replacement
 * @param s: string
 * @param ap: va_list
 * @param format: string
 * @param t: counter structure
 */
static void		ft_parsing(char *s, va_list ap, const char *format, size_t *t)
{
	char conv;

	t[4] = ft_checkflag1(format, t);
	t[2] = ft_checktaille_min(ap, format, t);
	t[3] = ft_checktaille_max(ap, format, t);
	conv = format[t[0] + 1]; /** get of the type of replacement*/
	if (ft_isconv(conv, "cspdiuxX%"))
	{
		t[0] = t[0] + 2; /** advance the string iterator by two if the replacement is supported */
		if (conv == 's')
			ft_write_s(s, ap, t);
		else if (conv == 'c')
			ft_write_c(s, ap, t);
		else if (conv == '%')
			ft_write_prct(s, t);
		else if (conv == 'p')
			ft_write_p(s, ap, t);
		else
			ft_write_d(s, ap, t, conv);
	}
	else
		t[0] = t[0] + 1; /** advance the string iterator by one if the replacement is not supported */
}

/**
 * @brief Find the content to print (after replacements)
 * @param s: string
 * @param ap: va_list
 * @param format: string
 * @param t: counter structure
 */
static void		ft_fill(char *s, va_list ap, const char *format, size_t *t)
{
	t[0] = 0;
	t[1] = 0;
	while (t[0] < ft_strlen(format)) /** parse the string */
	{
		if (format[t[0]] != '%')
		{
			s[t[1]] = format[t[0]]; /** affect the content of the string when there is no replacement */
			t[0]++;
			t[1]++;
		}
		else
			ft_parsing(s, ap, format, t); /** affect the output of the replacement otherwise */
	}
	s[t[1]] = '\0'; /** end the string */
}

/**
 * @brief Replication of the printf function
 * @param format, ... : string(s)
 * @retval n as the number of characters printed if the function worked
 * @retval 0 1 if the function didn't work
 */
int				ft_printf(const char *format, ...)
{
	char	*s; 
	size_t	len; /* the size of the string to print */
	size_t	t[4]; /* t[0] = string iterator
					t[1] = the number of characters to print
					t[2] = the precision specifier for a replacement
					t[3] = the length specifier for a replacement
					t[4] = the flag 1 option
				    */
	va_list	ap; /* a structure from stdarg.h */

	va_start(ap, format); /* initialize the va_list structure */
	len = ft_size(ap, format); /** calculate the size of the string to print */
	va_end(ap); /* release va_list resources */
	t[1] = 0;
	s = NULL;
	if (!(s = (char*)malloc(len))) /** allocate the string in memory */
		return (0);
	va_start(ap, format);
	ft_fill(s, ap, format, t); /** find the content to print (after replacements)*/
	va_end(ap); 
	ft_putstr_n(s, (int)t[1]); /** print the content */
	free(s);
	return ((int)t[1]);
}
