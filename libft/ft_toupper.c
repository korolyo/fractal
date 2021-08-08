#include "libft.h"

int	ft_toupper(int c)
{
	if ((char) c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
