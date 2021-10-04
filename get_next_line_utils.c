#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- && dest != src)
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}
