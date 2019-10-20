/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:49:47 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/18 11:49:51 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

size_t			ft_checkflag1(const char *format, size_t *i)
{
	size_t option;

	option = 0;
	if (format[*i + 1] == '0' | format[*i + 1] == '-')
	{
		option = (format[*i + 1] == '-' ? 1 : 2);
		*i = *i + 1;
		if (format[*i + 1] == '0' | format[*i + 1] == '-')
		{
			option = 1;
			*i = *i + 1;
		}
	}
	return (option);
}

size_t			ft_checktaille_min(va_list ap, const char *format, size_t *i)
{
	size_t var1;
	size_t j;

	if (format[*i + 1] == '*')
	{
		var1 = (size_t)va_arg(ap, int);
		*i = *i + 1;
		return (var1);
	}
	else if (ft_isdigit(format[*i + 1]))
	{
		j = *i;
		while (ft_isdigit(format[*i + 1]))
			*i = *i + 1;
		return (ft_atoi(&format[j + 1]));
	}
	return (0);
}

size_t			ft_checktaille_max(va_list ap, const char *format, size_t *i)
{
	size_t taille_max;

	taille_max = -1;
	if (format[*i + 1] == '.')
	{
		*i = *i + 1;
		taille_max = ft_checktaille_min(ap, format, i);
	}
	return (taille_max);
}
