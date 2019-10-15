/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/15 16:26:57 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

void		ft_fill_caract(char *s, size_t max, size_t *t, char c)
{
	size_t	k;

	k = 0;
	while (k < max)
	{
		k++;
		s[t[1]] = c;
		t[1]++;
	}
}

void		ft_write_s(char *s, va_list ap, size_t *t)
{
	char	*var1;
	size_t	k;
	size_t	m;

	var1 = va_arg(ap, char*);
	k = 0;
	m = t[3] < ft_strlen(var1) ? t[3] : ft_strlen(var1);
//	printf("\n -%s- %zu %zu %zu %zu\n", var1, t[4], t[2], t[3], t[2] - m);
	if (t[2] > m && t[4] != 1)
		ft_fill_caract(s, t[2] - m, t, (t[4] == 2 ? '0' : ' '));
	k = 0;
	while (k < ft_strlen(var1) && k < t[3])
	{
		s[t[1]] = var1[k];
		t[1]++;
		k++;
	}
	k = 0;
	if (t[2] > m && t[4] == 1)
		ft_fill_caract(s, t[2] - m, t, ' ');
}

void		ft_write_c(char *s, va_list ap, size_t *t)
{
	char	var1;

	var1 = (char)va_arg(ap, int);
	if (t[2] > 0 && t[4] != 1)
		ft_fill_caract(s, t[2] - 1, t, (t[4] == 2 ? '0' : ' '));
	s[t[1]] = var1;
	t[1]++;
	if (t[2] > 0 && t[4] == 1)
		ft_fill_caract(s, t[2] - 1, t, ' ');
}

void		ft_write_p(char *s, va_list ap, size_t *t)
{
	void *var1;

	var1 = va_arg(ap, void*);
//	printf("\n -%p- %ld %zu %zu\n", var1, (long)var1, t[1], t[0]);
	s[t[1]] = '0';
	s[t[1] + 1] = 'x';
	t[1] = t[1] + 1;
	ft_putnbr_base(s, (long)var1, "0123456789abcdef", t);
}

void		ft_write_d(char *s, va_list ap, size_t *t, char conv)
{
	int var1;

	var1 = va_arg(ap, int);
//	printf("\n %d %zu %zu %zu %zu \n", var1, t[1], t[0], ft_count_yc_signe(var1, "0123456789"), ft_count_hors_signe(var1, "0123456789"));
//	printf("\n -%s- %zu %zu\n", var1, t[1], t[0]);
	if (conv == 'i' || conv == 'd' || conv == 'u')
		ft_putnbr_base(s, var1, "0123456789", t);
	if (conv == 'x')
		ft_putnbr_base(s, var1, "0123456789abcdef", t);
	if (conv == 'X')
		ft_putnbr_base(s, var1, "0123456789ABCDEF", t);
}
