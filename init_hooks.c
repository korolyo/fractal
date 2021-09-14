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
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fractal");
	vars->zoom = 1;
	vars->move_x = 0;
	vars->move_y = 0;
	vars->it_max = 300;
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
	else if (keycode == ARROW_L)
		vars->x -= 50;
	else if (keycode == ARROW_R)
		vars->x += 50;
	else if (keycode == ARROW_D)
		vars->y -= 50;
	else if (keycode == ARROW_U)
		vars->y += 50;
	draw_fractol(vars);
	return (0);
}

int	close_win(int keycode)
{
	(void)keycode;
	exit(0);
}

void zoom(t_vars *vars, int x, int y)
{
	int		zoom_x;
	int		zoom_y;

	vars->move_x = 2 * (x - WIDTH / 2) / (0.5 * WIDTH);
	vars->move_y = 2 * (y - HEIGHT / 2) / (0.5 * HEIGHT);
	zoom_x = WIDTH / vars->move_x;
	zoom_y = HEIGHT / vars->move_y;
	vars->new_w = WIDTH / zoom_x - (x / WIDTH * (vars->new_w - zoom_x));
	vars->new_h = HEIGHT / zoom_y - (y / HEIGHT * (vars->new_h - zoom_y));
}

int	mouse_get_pos(int mousecode, int x, int y, t_vars *vars)
{
	if (vars->zoom == 1)
	{
		zoom(vars, x, y);
//		vars->move_x = x - (x / WIDTH * (new)) ;
//		vars->move_y = 2 * (y - HEIGHT / 2) / (0.5 * HEIGHT);
	}
	if (mousecode == 1)
	{
		zoom(vars, x, y);
		vars->cx = 2 * (x - WIDTH / 2) / (0.5 * WIDTH);
		vars->cy = 2 * (y - HEIGHT / 2) / (0.5 * HEIGHT);
	}
	if (mousecode == SCROLL_UP && vars->zoom < 2 && vars->it_max > 100)
	{
		zoom(vars, x, y);
		vars->it_max -= 100;
		vars->zoom *= 1.2;
	}
	else if (mousecode == SCROLL_DOWN)
	{
		zoom(vars, x, y);
		vars->it_max += 100;
		vars->zoom *= 0.8;
	}
	draw_fractol(vars);
	return (0);
}
