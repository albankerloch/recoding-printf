/**
 * @file ft_size.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"


/**
 * @brief Calculation of the length of the output of a replacement
 * @note Miror of the ft_parsing function
 * @param ap: va_list
 * @param format: string
 * @param t: counter structure
 * @return the length of the content to print
 */
static void	ft_parsing_size(va_list ap, const char *format, size_t *t)
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
			ft_count_s(ap, t);
		else if (conv == 'c')
			ft_count_c(ap, t);
		else if (conv == 'p')
			ft_count_p(ap, t);
		else if (conv == '%')
			ft_count_prct(t);
		else
			ft_count_d(ap, t, conv); 
	}
	else
		t[0] = t[0] + 1; /** advance the string iterator by one if the replacement is not supported */
}

/**
 * @brief Calculation of the length of the content to print
 * @param ap: va_list
 * @param format: string(s)
 * @return the length of the content to print
 */
size_t		ft_size(va_list ap, const char *format)
{
	size_t t[4];

	t[0] = 0;
	t[1] = 0;
	while (t[0] < ft_strlen(format)) /** parse the string */
	{
		if (format[t[0]] != '%')
		{
			t[0]++;
			t[1]++; /** add one to the counter while there is no replacement */
		}
		else
		{
			ft_parsing_size(ap, format, t); /** calculate how long the output of the replacement will be */
		}
	}
	t[1]++;
	return (t[1]);
}
