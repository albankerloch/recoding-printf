/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/16 18:50:43 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static void	ft_parsing_size(va_list ap, const char *format, size_t *t)
{
	char conv;

	t[4] = ft_checkflag1(format, t);
//	printf("\n %c %zu\n", option, i);
	t[2] = ft_checktaille_min(ap, format, t);
//	printf("\n %zu | %zu\n", t[2], t[0]);
	t[3] = ft_checktaille_max(ap, format, t);
//	printf("\n %zu | %zu\n", t[3], t[0]);
	conv = format[t[0] + 1];
//	printf("\n %c %c %zu  %zu\n", option, conv, t[0], t[1]);
	t[0] = t[0] + 2;
	if (conv == 's')
		ft_count_s(ap, t);
	else if (conv == 'c')
		ft_count_c(ap, t);
	else if (conv == 'p')
		ft_count_p(ap, t);
	else
		ft_count_d(ap, t, conv);
}

size_t		ft_size(va_list ap, const char *format)
{
	size_t t[4];

	t[0] = 0;
	t[1] = 0;
	while (t[0] < ft_strlen(format))
	{
		if (format[t[0]] != '%')
		{
			t[0]++;
			t[1]++;
		}
		else
		{
			if (format[t[0] + 1] == '%')
			{
				t[1]++;
				t[0] = t[0] + 2;
			}
			else
				ft_parsing_size(ap, format, t);
		}
	}
	t[1]++;
	return (t[1]);
}
