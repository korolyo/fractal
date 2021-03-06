/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:12:33 by acollin           #+#    #+#             */
/*   Updated: 2021/08/30 22:12:36 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	gradient(int startcolor, int endcolor, int iter, int iter_max)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = ((endcolor >> 16) - (startcolor >> 16)) / (iter + 1);
	increment[1] = ((endcolor >> 8) & 0xFF - (startcolor >> 8) & 0xFF) / (iter + 1);
	increment[2] = ((endcolor & 0xFF) - (startcolor & 0xFF)) / (iter + 1);
	new[0] = ((startcolor) >> 16) + fabs(iter_max * increment[0]);
	new[1] = (((startcolor) >> 8) & 0xFF) + fabs(iter_max * increment[1]);
	new[2] = ((startcolor) & 0xFF) + fabs(iter_max * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}
