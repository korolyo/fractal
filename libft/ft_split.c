/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 22:02:51 by acollin           #+#    #+#             */
/*   Updated: 2021/08/04 22:03:41 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	size_t	count;
	size_t	flag;
	size_t	i;

	count = 0;
	flag = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		i++;
	}
	return (count);
}

static char	*result(size_t j, size_t reslen, char **call, char *str)
{
	size_t	i;

	call[j] = (char *)ft_calloc(sizeof(char), reslen + 1);
	if (call[j] == NULL)
	{
		free_array(call);
		return (NULL);
	}
	i = 0;
	while (reslen > 0)
	{
		call[j][i] = *(str - reslen);
		i++;
		reslen--;
	}
	return (call[j]);
}

static char	**printres(char *str, char c, char **res, size_t count)
{
	size_t	j;
	size_t	reslen;

	j = 0;
	reslen = 0;
	while (count > 0)
	{
		while (*str == c)
			str++;
		if (*str != c)
		{
			while (*str != c && *str)
			{
				reslen++;
				str++;
			}
			res[j] = result(j, reslen, res, str);
			reslen = 0;
			j++;
		}
		count--;
	}
	res[j] = NULL;
	return ((char **)res);
}

char	**ft_split(char const *s, char c)
{
	size_t	reslen;
	char	*str;
	char	**res;
	size_t	count;

	reslen = 0;
	count = count_words(s, c);
	str = (char *)s;
	while (*str == c)
		str++;
	res = (char **) ft_calloc(sizeof(char *), count + 1);
	if (res == NULL)
		return (NULL);
	printres(str, c, res, count);
	return ((char **)res);
}
