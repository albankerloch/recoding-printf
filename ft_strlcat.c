/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:22:15 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/12 13:48:48 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strinsert(char *dest, const char *src, size_t i)
{
	size_t	j;

	j = 0;
	while (src[j] != 0)
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (j + i);
}
