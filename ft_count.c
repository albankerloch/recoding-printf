/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:49:21 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/18 11:49:25 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

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
	while (k < ft_strlen(var1) && k < t[3])
	{
		t[1]++;
		k++;
	}
	k = 0;
	if (t[2] > m && t[4] == 1)
		t[1] = t[1] + t[2] - m;
}

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

void		ft_count_p(va_list ap, size_t *t)
{
	void *var1;

	var1 = va_arg(ap, void*);
	t[1] = t[1] + 1;
	ft_countnbr_base((long)var1, "0123456789abcdef", t);
}

void		ft_count_d(va_list ap, size_t *t, char conv)
{
	int var1;

	var1 = va_arg(ap, int);
	if (conv == 'i' || conv == 'd' || conv == 'u')
		ft_countnbr_base(var1, "0123456789", t);
	if (conv == 'x')
		ft_countnbr_base(var1, "0123456789abcdef", t);
	if (conv == 'X')
		ft_countnbr_base(var1, "0123456789ABCDEF", t);
}

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
