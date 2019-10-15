/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:49:01 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/15 12:21:54 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <stdarg.h>

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t			    ft_count_hors_signe(long nbr, char *base);
size_t 			    ft_count_yc_signe(long nbr, char *base);
int					ft_isdigit(int i);
int			        ft_atoi(const char *str);
size_t				ft_strlen(const char *str);
int					ft_printf(const char *format, ...);
void    			ft_putstr(char *s);
char			   	*ft_strchr(const char *str, int c);
size_t				ft_strinsert(char *dest, const char *src, size_t size);
char				*ft_strdup(const char *src);
void			    ft_putnbr_base(char *s, long nbr, char *base, size_t *t);


#endif
