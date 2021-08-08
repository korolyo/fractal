#include "libft.h"

int	ft_isalnum(int c)
{
	if ((((char)c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'z')) || ((c
				>= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}
