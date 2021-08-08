#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	len;
	unsigned int	index;

	len = ft_strlen(s);
	index = 0;
	res = (char *) ft_calloc(sizeof(char), len + 1);
	if (res == NULL)
		return (NULL);
	while (index < len)
	{
		res[index] = f(index, s[index]);
		index++;
	}
	return ((char *)res);
}
