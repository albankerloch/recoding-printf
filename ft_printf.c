/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/12 16:05:17 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *format, const char *var1)
{
    char *s;
	size_t i;
	size_t	j;
	int t;

    s = NULL;
    if (!(s = (char*)malloc(ft_strlen(format) + ft_strlen(var1) + 1)))
        return (0);
	j = 0;
	i = 0;
//	printf("%zu\n", ft_strlen(format) + ft_strlen(var1)); 
	while (j < ft_strlen(format) + ft_strlen(var1))
	{
		if (format[i] != '%')
		{
			s[j] = format[i];
			i++;
			j++;
			t = 0;
		}
		else
		{
			while (j < i + ft_strlen(var1))
			{
				s[j] = var1[j - i];
				j++;
			}
			i++;
			t = 1;
		}
		printf("%zu %zu %d %s \n", j, i, t,  s); 
	}
	s[j] = '\0';
	ft_putstr(s);
	return (0);
}
