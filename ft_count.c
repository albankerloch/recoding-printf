/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/15 17:04:05 by akerloc-         ###   ########.fr       */
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
//	printf("\n -%s- %zu %zu %zu %zu\n", var1, t[4], t[2], t[3], t[2] - m);
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
//	printf("\n -%p- %ld %zu %zu\n", var1, (long)var1, t[1], t[0]);
	t[1] = t[1] + 1;
	ft_countnbr_base((long)var1, "0123456789abcdef", t);
}

void		ft_count_d(va_list ap, size_t *t, char conv)
{
	int var1;

	var1 = va_arg(ap, int);
//	printf("\n %d %zu %zu %zu %zu \n", var1, t[1], t[0], ft_count_yc_signe(var1, "0123456789"), ft_count_hors_signe(var1, "0123456789"));
//	printf("\n -%s- %zu %zu\n", var1, t[1], t[0]);
	if (conv == 'i' || conv == 'd' || conv == 'u')
		ft_countnbr_base(var1, "0123456789", t);
	if (conv == 'x')
		ft_countnbr_base(var1, "0123456789abcdef", t);
	if (conv == 'X')
		ft_countnbr_base(var1, "0123456789ABCDEF", t);
}
