/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:45:51 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/18 11:44:35 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int		ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (i);
	else
		return (0);
}

size_t	ft_max(size_t n1, size_t n2)
{
	size_t m;

	m = -1;
	if (n1 == m)
		return (n2);
	if (n2 == m)
		return (n1);
	if (n1 > n2)
		return (n1);
	return (n2);
}
