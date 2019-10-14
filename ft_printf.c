/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/14 16:24:51 by akerloc-         ###   ########.fr       */
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
	int taille_max;

	taille_max = -1;
	if (format[*i + 1] == '.')
	{
		*i = *i + 1;
        taille_max = ft_checktaille_min(ap, format, i);
    }
    return (taille_max);
}

static void ft_write_s(char *s, va_list ap, size_t *t)
{
    char *var1;
	size_t k;

	var1 = va_arg(ap, char*);
//	printf("\n -%s- %zu %zu\n", var1, t[1], t[0]);
	k = 0;
	while (k < ft_strlen(var1))
	{
		s[t[1]] = var1[k];
		t[1]++;
		k++;
	}
}

static void ft_write_d(char *s, va_list ap, size_t *t)
{
   int var1;

	var1 = va_arg(ap, int);
//	printf("\n -%s- %zu %zu\n", var1, t[1], t[0]);
	ft_putnbr_base(s, var1, "0123456789", t);
}

static void ft_write_c(char *s, va_list ap, size_t *t)
{
    char var1;

	var1 = (char)va_arg(ap, int);
	s[t[1]] = var1;
	t[1]++;
}

static void ft_parsing(char *s, va_list ap, const char *format, size_t *t)
{

	char option;
	int taille_min;
	int taille_max;
	char conv;

	option = ft_checkflag1(format, t);
//	printf("\n %c %zu\n", option, i);
	taille_min = ft_checktaille_min(ap, format, t);
//	printf("\n %d | %zu\n", taille_min, i);
	taille_max = ft_checktaille_max(ap, format, t);
//	printf("\n %d | %zu\n", taille_mqx, i);
	conv = format[t[0] + 1];
//	printf("\n %c %c %zu  %zu\n", option, conv, t[0], t[1]);
	t[0] = t[0] + 2;
    if (s[0] == 'a')
        conv = 'a';
	if (conv == 's' && option == 'n')
		ft_write_s(s, ap, t);
	if (conv == 'c' && option == 'n')
		ft_write_c(s, ap, t);
	if (conv == 'd' && option == 'n')
		ft_write_d(s, ap, t);
}

static void ft_fill(char *s, va_list ap, const char *format)
{
	size_t t[2];

	t[0] = 0;
	t[1] = 0;
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
				ft_parsing(s, ap, format, t);

			}
		}
	}
	s[t[1]] = '\0';
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
		len = 1000;
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
