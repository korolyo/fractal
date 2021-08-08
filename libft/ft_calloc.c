#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	sizeinbytes;
	char	*s;

	sizeinbytes = nmemb * size;
	p = malloc (sizeinbytes);
	s = p;
	if (p != NULL)
	{
		while (sizeinbytes--)
			*s++ = 0;
	}
	return (p);
}
