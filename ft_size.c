/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/15 13:23:25 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_checkflag1(const char *format, size_t *i)
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

static size_t ft_checktaille_min(va_list ap, const char *format, size_t *i)
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

static size_t ft_checktaille_max(va_list ap, const char *format, size_t *i)
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

static void ft_parsing_size(char *s, va_list ap, const char *format, size_t *t)
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
	t[1] = t[1] + t[2] + t[3];
	if (conv != 'c' && conv != 's' && conv != 'd' && conv != 'i' conv != 'p' && conv != 'u' && conv != 'x' && conv != 'X')
	t[5] == -2;
}

static void ft_size(char *s, va_list ap, const char *format)
{
	size_t t[6];

	t[0] = 0;
	t[1] = 0;
	t[5] = 0;
	while (t[0] < ft_strlen(format))
	{
		if (format[t[0]] != '%')
		{
			s[t[1]] = format[t[0]];
			t[0]++;
			t[1]++;
		}
		else
		{
			if (format[t[0] + 1] == '%')
			{
				s[t[1]] = '%';
				t[1]++;
				t[0] = t[0] + 2;
			}
			else
			{
				ft_parsing_size(s, ap, format, t);

			}
		}
	}
	t[1]++;
	return (t[5] == -2 ? t[5] : t[1]);
}

int ft_printf(const char *format, ...)
{
    char *s;
	size_t t;
	size_t len;
	va_list ap;

	t = ft_count(format);
	if (t != 0)
	{
		va_start(ap, format);
		len = ft_size(ap, format);
		va_end(ap);
	}
	else
		len = -1;
    s = NULL;
	if (len < -1)
		return (0);
    if (!(s = (char*)malloc(ft_strlen(format) + len + 1)))
        return (0);
	if (t != 0)
	{
		va_start(ap, format);
		ft_fill(s, ap, format);
		va_end(ap);
	}
	ft_putstr(s);
	free(s);
	return (0);
}
