/**
 * @file ft_strdup.c
 * @author alban kerloc'h
 * @date 19/10/2019
 * @version 1.0
 */

#include "libft.h"

/**
 * @brief Replication of the strcpy function
 * @param dest: a pointer to the begining of a string
 * @param src: a string
 * @return a pointer to the string copied from src
 */
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

/**
 * @brief Replication of the strdup function
 * @param src: one string
 * @return a string allocated in memory
 */
char		*ft_strdup(const char *src)
{
	char *s;

	s = NULL;
	if (!(s = (char*)malloc(ft_strlen(src) + 1)))
		return (s);
	ft_strcpy(s, src);
	return (s);
}
