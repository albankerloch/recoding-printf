/* updated: 19/10/2019 */
/* ft_fill_caract.c by alban kerloc'h */

#include "libftprint.h"

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
