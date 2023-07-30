/* updated: 19/10/2019 */
/* ft_strchr.c by alban kerloc'h */

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
