#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s1;
	char		*save;

	save = 0;
	s1 = s;
	while (*s1)
	{
		if (*s1 == (char) c)
			save = (char *) s1;
		s1++;
	}
	if (c == '\0')
		save = (char *) s1;
	return (save);
}
