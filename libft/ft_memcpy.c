#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	unsigned const char	*psource;

	pdest = (unsigned char *)dest;
	psource = (unsigned const char *)src;
	if ((pdest == NULL) && (psource == NULL))
		return (NULL);
	while (n)
	{
		*(pdest++) = *(psource++);
		n--;
	}
	return (dest);
}
