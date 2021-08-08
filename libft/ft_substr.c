#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char		*sub;
	unsigned char		*str;
	size_t				slen;

	slen = ft_strlen(s);
	if (start + len > slen && start < slen)
		len = slen - start;
	else if (start >= slen)
		len = 0;
	sub = (unsigned char *)ft_calloc((len + 1), sizeof(char));
	if (sub == ((void *)0))
		return ((void *)0);
	str = sub;
	while (len > 0)
	{
		*sub = *(s + start);
		sub++;
		s++;
		len--;
	}
	return ((char *)str);
}
