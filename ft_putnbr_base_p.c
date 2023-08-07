/**
 * @file ft_putnbr_base_p.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Manage length and precision specifier before an memory address replacement
 * @param s: a string (allocated in memory)
 * @param nbr: the memory address 
 * @param base: a string representing the numbering system
 * @param t: counter structure
 * @return 
 */
void			ft_fill_left_p(char *s, long nbr, char *base, size_t *t)
{
	if (t[2] > ft_max(t[3], ft_cy(nbr, base)) + 2 && t[4] != 1)
		ft_fill_caract(s, t[2] - ft_max(t[3], ft_cy(nbr, base)) - 2, t, ' ');
	s[t[1]] = '0';
	s[t[1] + 1] = 'x';
	t[1] = t[1] + 2;
	if (ft_max(t[3], 0) > ft_ch(nbr, base))
		ft_fill_caract(s, t[3] - ft_ch(nbr, base), t, '0');
	ft_putnbr_base_p(s, nbr, base, t);
}

/**
 * @brief Affect a memory address in an certain numbering 
 * @param s: string (allocated in memory)
 * @param nbr: number
 * @param base: a string representing the numbering system
 * @param t: counter structure
 * @return 
 */
void			ft_putnbr_base_p(char *s, long nbr, char *base, size_t *t)
{
	long long	l;

	l = nbr;
	if (!(nbr == 0 && t[3] == 0))
		ft_wbase(l, base, s, t);
	else
	{
		if (t[2] > 0)
		{
			s[t[1]] = '0';
			t[1] = t[1] + 1;
		}
	}
	if (t[2] > ft_max(t[3], ft_cy(nbr, base)) + 2 && t[4] == 1)
		ft_fill_caract(s, t[2] - ft_max(t[3], ft_cy(nbr, base)) - 2, t, ' ');
}
