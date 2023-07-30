/* updated: 19/10/2019 */
/* ft_putstr_n.c by alban kerloc'h */

#include "libftprint.h"

void	ft_putstr_n(char *s, int i)
{
	if (s == NULL)
		return ;
	write(1, s, i);
}
