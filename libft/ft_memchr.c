#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*ischarfind;

	p = (unsigned char *) s;
	ischarfind = NULL;
	while (n--)
	{
		if (*p != (unsigned char)c)
		{
			p++;
		}
		else
		{
			ischarfind = p;
			break ;
		}
	}
	return (ischarfind);
}
