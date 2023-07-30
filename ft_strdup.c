/* updated: 19/10/2019 */
/* ft_strdup.c by alban kerloc'h */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *src)
{
	char *s;

	s = NULL;
	if (!(s = (char*)malloc(ft_strlen(src) + 1)))
		return (s);
	ft_strcpy(s, src);
	return (s);
}
