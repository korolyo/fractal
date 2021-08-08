#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psource;
	unsigned int		size;

	size = (unsigned int)n;
	pdest = (unsigned char *)dest;
	psource = (const unsigned char *)src;
	while (n != 0)
	{
		if ((*psource == (unsigned char) c))
		{
			*pdest = *psource;
			return (pdest + 1);
		}
		*pdest++ = *psource++;
		n--;
	}
	return (0);
}
