/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/14 13:40:03 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t ft_count(const char *format)
{
	size_t i;
	size_t t;

	i = 0;
	t = 0;
	while ( i < ft_strlen(format))
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
				t++;
			else
				i++;
		}
		i++;
	}
//	printf("\n --%zu-- \n", t);
	return (t);
}
/*
static size_t ft_size(va_list ap, const char *format, size_t t)
{
	size_t len;
	size_t i;
    char *var1;

	len = 0;
	i = 0;
	while (i < t)
	{
		(void)format;
		var1 = va_arg(ap, char*);
		len = len + ft_strlen(var1);
		i++;
	}
//	printf("\n --%zu-- \n", len);
	return (len);
}
*/
static char ft_checkflag1(const char *format, size_t *i)
{
	char option;

	option = 'n';
	if (format[*i + 1] == '0' | format[*i + 1] == '-')
	{
		option = format[*i + 1];
		*i = *i + 1;
		if (format[*i + 1] == '0' | format[*i + 1] == '-')
		{
			option = '-';
			*i = *i + 1;
		}
	}
	return (option);
}

static int ft_checktaille_min(va_list ap, const char *format, size_t *i)
{
    int var1;
	size_t j;

	if (format[*i + 1] == '*')
	{
		var1 = va_arg(ap, int);
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

static int ft_checktaille_max(va_list ap, const char *format, size_t *i)
{
	size_t j;

	if (format[*i + 1] == '.')
	{
		*i = *i + 1;
		return (ft_checkflag1
		if (format[*i + 1] == '*')
		{
			var1 = va_arg(ap, int);
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
	}
	return (0);
}

static size_t ft_parsing(char *s, va_list ap, const char *format, size_t i)
{
    char *var1;
	char option;
	int taille_min;

	option = ft_checkflag1(format, &i);
//	printf("\n %c %zu\n", option, i);
	taille_min = ft_checktaille_min(ap, format, &i);
//	printf("\n %d | %zu\n", taille_min, i);
	taille_max = ft_checktaille_max(ap, format, &i);
	if (s[0] == 'a')
		var1 = va_arg(ap, char*);
	i = i + 2;
	return (i);
}

static void ft_fill(char *s, va_list ap, const char *format)
{
	size_t k;
	size_t j;
	size_t i;
    char *var1;

	j = 0;
	i = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] != '%')
		{
			s[j] = format[i];
			i++;
			j++;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				s[j] = '%';
				j++;
				i = i + 2;
			}
			else
			{
				i = ft_parsing(s, ap, format, i);
				var1 = va_arg(ap, char*);
//				printf("\n -%s- %zu %zu %zu\n", var1, j, i, j - i);
				k = 0;
				while (k < ft_strlen(var1))
				{
					s[j] = var1[k];
					j++;
					k++;
				}
			}
		}
	}
	s[j] = '\0';
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
		//len = ft_size(ap, format, t);
		len = 50;
		va_end(ap);
	}
	else
		len = -1;
    s = NULL;
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
