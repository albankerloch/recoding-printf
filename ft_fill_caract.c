/**
 * @file ft_fill_caract.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libftprint.h"

/**
 * @brief Affect repeated character to an allocated string
 * @param s: string (allocated in memory)
 * @param max: the number of repetition
 * @param t: counter structure
 * @param t: character
 */
void		ft_fill_caract(char *s, size_t max, size_t *t, char c)
{
	size_t	k;

	k = 0;
	while (k < max)
	{
		k++;
		s[t[1]] = c;
		t[1]++;
	}
}
