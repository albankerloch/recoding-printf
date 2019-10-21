/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:50:35 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/20 15:55:35 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

void	ft_putstr_n(char *s, int i)
{
	if (s == NULL)
		return ;
	write(1, s, i);
}
