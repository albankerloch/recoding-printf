/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:25:01 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/10 17:25:05 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char*)str;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
		{
			return (&s[i]);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&s[i]);
	return (NULL);
}
