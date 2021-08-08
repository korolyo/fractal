#include "libft.h"

int	ft_isprint(int c)
{
	if ((char) c >= 32 && c <= 126)
		return (1);
	return (0);
}
