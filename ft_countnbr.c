/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:49:21 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/22 14:44:10 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

void		ft_countnbr_base(long nbr, char *base, size_t *t)
{
	size_t	sign;

	sign = nbr < 0 ? 1 : 0;
	if (t[2] > ft_max(t[3] + sign, ft_cy(nbr, base)) && t[4] == 0)
		t[1] = t[1] + t[2] - ft_max(t[3] + sign, ft_cy(nbr, base));
	if (t[2] > ft_max(t[3] + sign, ft_cy(nbr, base)) && t[4] == 2 &&
		t[3] != (size_t)-1)
		t[1] = t[1] + t[2] - ft_max(t[3] + sign, ft_cy(nbr, base));
	if (nbr < 0)
		t[1] = t[1] + 1;
	if (t[2] > ft_cy(nbr, base) && t[4] == 2 && t[3] == (size_t)-1)
		t[1] = t[1] + t[2] - ft_cy(nbr, base);
	if (ft_max(t[3], 0) > ft_ch(nbr, base))
		t[1] = t[1] + t[3] - ft_ch(nbr, base);
	t[1] = t[1] + ft_cy(nbr, base);
	if (t[2] > ft_max(t[3] + sign, ft_cy(nbr, base)) && t[4] == 1)
		t[1] = t[1] + t[2] - ft_max(t[3] + sign, ft_cy(nbr, base));
}

void		ft_countnbr_base_p(long nbr, char *base, size_t *t)
{
	if (t[2] > ft_max(t[3], ft_cy(nbr, base)) + 2 && t[4] != 1)
		t[1] = t[1] + t[2] - ft_max(t[3], ft_cy(nbr, base)) - 2;
	t[1] = t[1] + 2;
	if (ft_max(t[3], 0) > ft_ch(nbr, base))
		t[1] = t[1] + t[3] - ft_ch(nbr, base);
	t[1] = t[1] + ft_cy(nbr, base);
	if (t[2] > ft_max(t[3], ft_cy(nbr, base)) + 2 && t[4] == 1)
		t[1] = t[1] + t[2] - ft_max(t[3], ft_cy(nbr, base));
}
