#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
