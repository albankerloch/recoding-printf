/**
 * @file ft_countnbr.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Calculation of the length needed for a number replacement
 * @param nbr: number
 * @param base: a string representing the numbering system
 * @param t: counter structure
 */
void		ft_countnbr_base(long nbr, char *base, size_t *t)
{
	size_t	sign;

	sign = nbr < 0 ? 1 : 0;
	if (t[2] > ft_max(t[3] + sign, ft_cy(nbr, base)) && t[4] == 0)
		t[1] = t[1] + t[2] - ft_max(t[3] + sign, ft_cy(nbr, base));
	if (t[2] > ft_max(t[3] + sign, ft_cy(nbr, base)) && t[4] == 2 &&
		t[3] != (size_t)-1)
		t[1] = t[1] + t[2] - ft_max(t[3] + sign, ft_cy(nbr, base));
	if (nbr < 0)
		t[1] = t[1] + 1;
	if (t[2] > ft_cy(nbr, base) && t[4] == 2 && t[3] == (size_t)-1)
		t[1] = t[1] + t[2] - ft_cy(nbr, base);
	if (ft_max(t[3], 0) > ft_ch(nbr, base))
		t[1] = t[1] + t[3] - ft_ch(nbr, base);
	t[1] = t[1] + ft_cy(nbr, base);
	if (t[2] > ft_max(t[3] + sign, ft_cy(nbr, base)) && t[4] == 1)
		t[1] = t[1] + t[2] - ft_max(t[3] + sign, ft_cy(nbr, base));
}

/**
 * @brief Calculation of the length needed for a memory address replacement
 * @param nbr: number
 * @param base: a string representing the numbering system
 * @param t: counter structure
 */
void		ft_countnbr_base_p(long nbr, char *base, size_t *t)
{
	if (t[2] > ft_max(t[3], ft_cy(nbr, base)) + 2 && t[4] != 1)
		t[1] = t[1] + t[2] - ft_max(t[3], ft_cy(nbr, base)) - 2;
	t[1] = t[1] + 2;
	if (ft_max(t[3], 0) > ft_ch(nbr, base))
		t[1] = t[1] + t[3] - ft_ch(nbr, base);
	t[1] = t[1] + ft_cy(nbr, base);
	if (t[2] > ft_max(t[3], ft_cy(nbr, base)) + 2 && t[4] == 1)
		t[1] = t[1] + t[2] - ft_max(t[3], ft_cy(nbr, base));
}
