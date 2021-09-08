/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:12:44 by acollin           #+#    #+#             */
/*   Updated: 2021/08/30 22:12:47 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Mandelbrot");
	vars->zoom = 1;
	vars->moveX = 0;
	vars->moveY = 0;
}

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_win(int keycode)
{
	(void)keycode;
	exit(0);
}

int	mouse_get_pos(int mousecode, int x, int y, t_vars *vars)
{
	if (mousecode == 1)
	{
		vars->cx = 2 * (x - WIDTH / 2) / (0.5 * WIDTH);
		vars->cy = 2 * (y - HEIGHT / 2) / (0.5 * HEIGHT);
		vars->moveX = 2 * (x - WIDTH / 2) / (0.5 * WIDTH);
		vars->moveY = 2 * (y - HEIGHT / 2) / (0.5 * HEIGHT);
		draw_fractol(vars);
	}
	if (mousecode == SCROLL_UP)
	{
		if (vars->zoom < 2)
			vars->zoom *= 1.2;
		draw_fractol(vars);
	}
	else if (mousecode == SCROLL_DOWN)
	{
		vars->zoom *= 0.8;
		draw_fractol(vars);
	}
	return (0);
}
