/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:17 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/12 16:23:34 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *format, ...)
{
    char *s;
	va_list ap;
	
	va_start(ap, format);
	s = va_arg(ap, char*);
	ft_putstr((char*)format);
	printf("\n%s\n", s);
	s = va_arg(ap, char*);
	printf("%s\n", s);
	va_end(ap);
	return (0);
}
