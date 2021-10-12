#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- && dest != src)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}
