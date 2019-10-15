/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 08:49:04 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/15 17:05:33 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

size_t			ft_count_hors_signe(long nbr, char *base)
{
	size_t		j;
	size_t		t;

	j = 1;
	t = nbr;
	if (nbr < 0)
	{
		t = -t;
	}
	while (t > ft_strlen(base))
	{
		t = t / ft_strlen(base);
		j++;
	}
	return (j);
}

static void		ft_wbase(long n, char *base, char *s, size_t *t)
{
	long c;
	long d;
	char e;
	int b;

	b = ft_strlen(base);
	if (n >= b)
	{
		c = n / b;
		d = n % b;
		ft_wbase(c, base, s, t);
		e = base[d];
		s[t[1]] = e;
		t[1] = t[1] + 1;
	}
	else
	{
		e = base[n];
		s[t[1]] = e;
		t[1] = t[1] + 1;
	}
}

void			ft_putnbr_base(char *s, long nbr, char *base, size_t *t)
{
	long long	l;
	size_t m;

	l = nbr;
	m = t[2] > ft_count_hors_signe(nbr, base) ? t[3] : ft_count_hors_signe(nbr, base);
	m = nbr < 0 ? m + 1 : m;
//	printf("\n%zu %zu\n", m, ft_count_hors_signe(nbr, base));
    if (t[2] > m && t[4] == 2)
		ft_fill_caract(s, t[2] - m, t, ' ');
	if (nbr < 0)
	{
		l = -l;
		s[t[1]] = '-';
		t[1] = t[1] + 1;
	}
    if (t[3] > ft_count_hors_signe(nbr, base) && t[4] != 0)
		ft_fill_caract(s, t[3] - ft_count_hors_signe(nbr, base), t, '0');
	ft_wbase(l, base, s, t);
	m = t[3] > ft_count_hors_signe(nbr, base) ? t[3] : ft_count_hors_signe(nbr, base);
	m = nbr < 0 ? m + 1 : m;
//	printf("\n%zu %zu\n", m, ft_count_hors_signe(nbr, base));
    if (t[2] > m && t[4] == 1)
		ft_fill_caract(s, t[2] - m, t, '0');
}

void			ft_countnbr_base(long nbr, char *base, size_t *t)
{
	long long	l;
	size_t m;

	l = nbr;
	m = t[2] > ft_count_hors_signe(nbr, base) ? t[3] : ft_count_hors_signe(nbr, base);
	m = nbr < 0 ? m + 1 : m;
//	printf("\n%zu %zu\n", m, ft_count_hors_signe(nbr, base));
    if (t[2] > m && t[4] == 2)
		t[1] = t[1] + t[2] - m;
	if (nbr < 0)
	{
		l = -l;
		t[1] = t[1] + 1;
	}
    if (t[3] > ft_count_hors_signe(nbr, base) && t[4] != 0)
		t[1] = t[1] + t[3] - ft_count_hors_signe(nbr, base);
	t[1] = t[1] + ft_count_hors_signe(nbr, base);
	m = t[3] > ft_count_hors_signe(nbr, base) ? t[3] : ft_count_hors_signe(nbr, base);
	m = nbr < 0 ? m + 1 : m;
//	printf("\n%zu %zu\n", m, ft_count_hors_signe(nbr, base));
    if (t[2] > m && t[4] == 1)
		t[1] = t[1] + t[2] - m;
}
