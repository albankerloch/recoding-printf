/* updated: 19/10/2019 */
/* ft_size.c by alban kerloc'h */

#include "libftprint.h"

static void	ft_parsing_size(va_list ap, const char *format, size_t *t)
{
	char conv;

	t[4] = ft_checkflag1(format, t);
	t[2] = ft_checktaille_min(ap, format, t);
	t[3] = ft_checktaille_max(ap, format, t);
	conv = format[t[0] + 1];
	if (ft_isconv(conv, "cspdiuxX%"))
	{
		t[0] = t[0] + 2;
		if (conv == 's')
			ft_count_s(ap, t);
		else if (conv == 'c')
			ft_count_c(ap, t);
		else if (conv == 'p')
			ft_count_p(ap, t);
		else if (conv == '%')
			ft_count_prct(t);
		else
			ft_count_d(ap, t, conv);
	}
	else
		t[0] = t[0] + 1;
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
			ft_parsing_size(ap, format, t);
		}
	}
	t[1]++;
	return (t[1]);
}
