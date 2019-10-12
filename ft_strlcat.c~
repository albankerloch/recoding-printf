/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:22:15 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/07 18:22:40 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	n = (ft_strlen(dest) < size) ? ft_strlen(dest) : size;
	n = n + ft_strlen(src);
	j = 0;
	i = ft_strlen(dest);
	while (j + i + 1 < size && src[j] != 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (n);
}
