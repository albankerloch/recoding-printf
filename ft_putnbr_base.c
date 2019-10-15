/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 08:49:04 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/15 12:22:23 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void	ft_strncat(char *dest, char *src, unsigned int nb, size_t *t)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
}
*/
size_t		ft_count_yc_signe(long nbr, char *base)
{
	size_t	j;
	size_t		t;

	j = 1;
	t = nbr;
	if (nbr < 0)
	{
		t = -t;
		j++;
	}
	while (t > ft_strlen(base))
	{
		t = t / ft_strlen(base);
		j++;
	}
	return (j);
}

size_t		ft_count_hors_signe(long nbr, char *base)
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

static void	ft_wbase(long n, char *base, char *s, size_t *t)
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

void	ft_putnbr_base(char *s, long nbr, char *base, size_t *t)
{
	long long	l;
	size_t k;

	l = nbr;
	if (nbr < 0)
	{
		l = -l;
		s[t[1]] = '-';
		t[1] = t[1] + 1;
	}
    k = 0;
    if (t[3] > ft_count_hors_signe(nbr, base) && t[4] != 0)
    {
        while (k < t[3] - ft_count_hors_signe(nbr, base))
        {
            k++;
            s[t[1]] = '0';
            t[1]++;
		}
    }
	ft_wbase(l, base, s, t);
}
