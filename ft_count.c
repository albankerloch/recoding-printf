/**
 * @file ft_count.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Calculation of the length of a string replacement
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_count_s(va_list ap, size_t *t)
{
	char	*var1;
	size_t	k;
	size_t	m;

	var1 = va_arg(ap, char*);
	k = 0;
	m = t[3] < ft_strlen(var1) ? t[3] : ft_strlen(var1);
	if (t[2] > m && t[4] != 1)
		t[1] = t[1] + t[2] - m;
	k = 0;
	if (!(var1))
		var1 = "(null)";
	while (k < ft_strlen(var1) && k < t[3])
	{
		t[1]++;
		k++;
	}
	k = 0;
	if (t[2] > m && t[4] == 1)
		t[1] = t[1] + t[2] - m;
}

/**
 * @brief Calculation of the length of a char replacement
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_count_c(va_list ap, size_t *t)
{
	char	var1;

	var1 = (char)va_arg(ap, int);
	if (t[2] > 0 && t[4] != 1)
		t[1] = t[1] + t[2] - 1;
	t[1]++;
	if (t[2] > 0 && t[4] == 1)
		t[1] = t[1] + t[2] - 1;
}

/**
 * @brief Calculation of the length of a replacement by a literal %
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_count_prct(size_t *t)
{
	if (t[2] > 0 && t[4] != 1)
		t[1] = t[1] + t[2] - 1;
	t[1]++;
	if (t[2] > 0 && t[4] == 1)
		t[1] = t[1] + t[2] - 1;
}

/**
 * @brief Calculation of the length of a pointer replacement
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_count_p(va_list ap, size_t *t)
{
	void			*var1;
	unsigned long	var2;

	var1 = va_arg(ap, void*);
	if (var1 < 0)
	{
		var2 = (unsigned long)var1;
		ft_countnbr_base_p((long)var2, "0123456789abcdef", t);
	}
	else
	{
		ft_countnbr_base_p((long)var1, "0123456789abcdef", t);
	}
}

/**
 * @brief Calculation of the length of a diuxX replacement
 * @param ap: va_list
 * @param t: counter structure
 */
void		ft_count_d(va_list ap, size_t *t, char conv)
{
	int				var1;
	unsigned long	var2;

	var1 = va_arg(ap, int);
	if (var1 < 0)
		var2 = (unsigned long)var1;
	if (conv == 'i' || conv == 'd' || conv == 'u')
		ft_countnbr_base(var1, "0123456789", t);
	if (conv == 'x' && var1 >= 0)
		ft_countnbr_base(var1, "0123456789abcdef", t);
	if (conv == 'X' && var1 >= 0)
		ft_countnbr_base(var1, "0123456789ABCDEF", t);
	if (conv == 'x' && var1 < 0)
		ft_countnbr_base(var2, "0123456789abcdef", t);
	if (conv == 'X' && var1 < 0)
		ft_countnbr_base(var2, "0123456789ABCDEF", t);
}
