/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:56:51 by acollin           #+#    #+#             */
/*   Updated: 2021/08/04 21:57:02 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	sizeinbytes;
	char	*s;

	sizeinbytes = nmemb * size;
	p = malloc (sizeinbytes);
	s = p;
	if (p != NULL)
	{
		while (sizeinbytes--)
			*s++ = 0;
	}
	return (p);
}
