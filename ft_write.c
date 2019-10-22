/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:49:34 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/22 14:14:01 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

void		ft_write_s(char *s, va_list ap, size_t *t)
{
	char	*var1;
	size_t	k;
	size_t	m;

	var1 = va_arg(ap, char*);
	m = t[3] < ft_strlen(var1) ? t[3] : ft_strlen(var1);
	if (t[2] > m && t[4] != 1)
		ft_fill_caract(s, t[2] - m, t, (t[4] == 2 ? '0' : ' '));
	if (!(var1))
		var1 = "(null)";
	k = 0;
	while (k < ft_strlen(var1) && k < t[3])
	{
		s[t[1]] = var1[k];
		t[1]++;
		k++;
	}
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

void		ft_write_prct(char *s, size_t *t)
{
	if (t[2] > 0 && t[4] != 1)
		ft_fill_caract(s, t[2] - 1, t, (t[4] == 2 ? '0' : ' '));
	s[t[1]] = '%';
	t[1]++;
	if (t[2] > 0 && t[4] == 1)
		ft_fill_caract(s, t[2] - 1, t, ' ');
}

void		ft_write_p(char *s, va_list ap, size_t *t)
{
	void			*var1;
	unsigned int	var2;

	var1 = va_arg(ap, void*);
	if (var1 < 0)
	{
		var2 = (unsigned long)var1;
		ft_fill_left_p(s, (long)var2, "0123456789abcdef", t);
	}
	else
		ft_fill_left_p(s, (long)var1, "0123456789abcdef", t);
}

void		ft_write_d(char *s, va_list ap, size_t *t, char conv)
{
	int				var1;
	unsigned int	var2;

	var1 = va_arg(ap, int);
	if (var1 < 0)
		var2 = (unsigned int)var1;
	if (conv == 'u' && var1 < 0)
		ft_fill_left(s, var2, "0123456789", t);
	if (conv == 'i' || conv == 'd' || (conv == 'u' && var1 >= 0))
		ft_fill_left(s, var1, "0123456789", t);
	if (conv == 'x' && var1 >= 0)
		ft_fill_left(s, var1, "0123456789abcdef", t);
	if (conv == 'X' && var1 >= 0)
		ft_fill_left(s, var1, "0123456789ABCDEF", t);
	if (conv == 'x' && var1 < 0)
		ft_fill_left(s, var2, "0123456789abcdef", t);
	if (conv == 'X' && var1 < 0)
		ft_fill_left(s, var2, "0123456789ABCDEF", t);
}
