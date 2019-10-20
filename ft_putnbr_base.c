/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:49:06 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/18 11:49:11 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

size_t			ft_cy(long nbr, char *base)
{
	if (nbr < 0)
		return (ft_ch(nbr, base) + 1);
	return (ft_ch(nbr, base));
}

size_t			ft_ch(long nbr, char *base)
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
	long	c;
	long	d;
	char	e;
	int		b;

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

void			ft_fill_left(char *s, long nbr, char *base, size_t *t)
{
	size_t		si;

	si = nbr < 0 ? 1 : 0;
	if (t[2] > ft_max(t[3] + si, ft_cy(nbr, base)) && t[4] == 0)
		ft_fill_caract(s, t[2] - ft_max(t[3] + si, ft_cy(nbr, base)), t, ' ');
	if (t[2] > ft_max(t[3] + si, ft_cy(nbr, base)) && t[4] == 2 &&
t[3] != (size_t)-1)
		ft_fill_caract(s, t[2] - ft_max(t[3] + si, ft_cy(nbr, base)), t, ' ');
	if (nbr < 0)
	{
		s[t[1]] = '-';
		t[1] = t[1] + 1;
	}
	if (t[2] > ft_cy(nbr, base) && t[4] == 2 && t[3] == (size_t)-1)
		ft_fill_caract(s, t[2] - ft_cy(nbr, base), t, '0');
	if (ft_max(t[3], 0) > ft_ch(nbr, base))
		ft_fill_caract(s, t[3] - ft_ch(nbr, base), t, '0');
	ft_putnbr_base(s, nbr, base, t);
}

void			ft_putnbr_base(char *s, long nbr, char *base, size_t *t)
{
	long long	l;
	size_t		si;

	l = nbr;
	si = nbr < 0 ? 1 : 0;
	if (nbr < 0)
		l = -l;
	if (!(nbr == 0 && t[3] == 0))
		ft_wbase(l, base, s, t);
	else
	{
		if (t[2] > 0)
		{
			s[t[1]] = ' ';
			t[1] = t[1] + 1;
		}
	}
	if (t[2] > ft_max(t[3] + si, ft_cy(nbr, base)) && t[4] == 1)
		ft_fill_caract(s, t[2] - ft_max(t[3] + si, ft_cy(nbr, base)), t, ' ');
}
