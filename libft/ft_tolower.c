#include "libft.h"

int	ft_tolower(int c)
{
	if ((char) c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}
