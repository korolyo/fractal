#include "libft.h"

int	ft_atoi(const char	*nptr)
{
	long long int	n;
	long long int	sign;

	n = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n'
		   || *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
		nptr++;
	if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	return (n * sign);
}
