/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/16 18:48:02 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

/*static size_t	ft_count(const char *format)
{
	size_t i;
	size_t t;

	i = 0;
	t = 0;
	while (i < ft_strlen(format))
	{
		if (format[i] == '%')
			t++;
		i++;
	}
//printf("\n --%zu-- \n", t);
	return (t);
}
*/

static int		ft_isconv(char conv, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (conv == s[i])
			return (1);
		i++;
	}
	return (0);
}

static void		ft_parsing(char *s, va_list ap, const char *format, size_t *t)
{
	char conv;

	t[4] = ft_checkflag1(format, t);
//	printf("\n %c %zu\n", option, i);
	t[2] = ft_checktaille_min(ap, format, t);
//	printf("\n %zu | %zu\n", t[2], t[0]);
	t[3] = ft_checktaille_max(ap, format, t);
//	printf("\n %zu | %zu\n", t[3], t[0]);
	conv = format[t[0] + 1];
//	printf("\n %zu %c %zu  %zu\n", t[4], conv, t[0], t[1]);
	if (ft_isconv(conv, "cspdiuxX%"))
	{
		t[0] = t[0] + 2;
		if (conv == 's')
			ft_write_s(s, ap, t);
		else if (conv == 'c')
			ft_write_c(s, ap, t);
		else if (conv == '%')
			ft_write_prct(s, t);
		else if (conv == 'p')
			ft_write_p(s, ap, t);
		else
			ft_write_d(s, ap, t, conv);
	}
	else
		t[0] = t[0] + 1;
}

static void		ft_fill(char *s, va_list ap, const char *format, size_t *t)
{
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
			ft_parsing(s, ap, format, t);
	}
//	printf("longeur finale : %zu\n", t[1]);
	s[t[1]] = '\0';
}

int				ft_printf(const char *format, ...)
{
	char	*s;
	size_t	len;
	size_t	t[4];
	va_list	ap;

	va_start(ap, format);
	len = ft_size(ap, format);
	//len[1] = 5000;
	va_end(ap);
	s = NULL;
//	printf("longeur totale : %zu\n", len[1]);
	if (!(s = (char*)malloc(len)))
		return (0);
	va_start(ap, format);
	ft_fill(s, ap, format, t);
	va_end(ap);
	ft_putstr_n(s, (int)t[1]);
	free(s);
	return ((int)t[1]);
}
