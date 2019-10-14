/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 08:49:04 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/14 16:37:02 by akerloc-         ###   ########.fr       */
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

static int		ft_count(int nbr, char *base)
{
	int		j;
	int		t;

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
*/
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

void	ft_putnbr_base(char *s, int nbr, char *base, size_t *t)
{
	long	l;

	l = nbr;
	if (nbr < 0)
	{
		l = -l;
		s[t[1]] = '-';
		t[1] = t[1] + 1;
	}
	ft_wbase(l, base, s, t);
}
