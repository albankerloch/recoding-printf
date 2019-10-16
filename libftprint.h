/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:38:07 by akerloc-          #+#    #+#             */
/*   Updated: 2019/10/16 15:45:34 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <stdarg.h>

void	ft_fill_caract(char *s, size_t max, size_t *t, char c);
void	ft_write_s(char *s, va_list ap, size_t *t);
void	ft_write_p(char *s, va_list ap, size_t *t);
void    ft_write_prct(char *s, size_t *t);
void	ft_write_c(char *s, va_list ap, size_t *t);
void	ft_write_d(char *s, va_list ap, size_t *t, char conv);
void	ft_count_s(va_list ap, size_t *t);
void	ft_count_p(va_list ap, size_t *t);
void	ft_count_c(va_list ap, size_t *t);
void	ft_count_d(va_list ap, size_t *t, char conv);
void    ft_countnbr_base(long nbr, char *base, size_t *t);
void	ft_size(va_list ap, const char *format, size_t *len);
void 	ft_fill_caract(char *s, size_t max, size_t *t, char c);
size_t	ft_checktaille_max(va_list ap, const char *format, size_t *i);
size_t 	ft_checktaille_min(va_list ap, const char *format, size_t *i);
size_t	ft_checkflag1(const char *format, size_t *i);
size_t  ft_max(size_t n1, size_t n2);
size_t	ft_count_hors_signe(long nbr, char *base);
size_t 	ft_count_yc_signe(long nbr, char *base);
int		ft_isdigit(int i);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
void    ft_putstr_n(char *s, int i);
char	*ft_strchr(const char *str, int c);
size_t	ft_strinsert(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *src);
void	ft_putnbr_base(char *s, long nbr, char *base, size_t *t);

#endif
