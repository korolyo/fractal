/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  fractals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:12:11 by acollin           #+#    #+#             */
/*   Updated: 2021/08/30 22:12:22 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_tricorn(t_vars *vars, t_data *img)
{
	while (++vars->y < HEIGHT)
	{
		vars->x = 1;
		while (++vars->x < WIDTH)
		{
			init_fractol(vars);
			while ((vars->zsqxm + vars->zsqym <= 4)
				&& vars->iter < vars->it_max)
			{
				vars->i = vars->zsqxm - vars->zsqym + vars->px;
				vars->zym = -2 * vars->zxm * vars->zym + vars->py;
				vars->zxm = vars->i;
				vars->iter++;
				vars->zsqxm = vars->zxm * vars->zxm;
				vars->zsqym = vars->zym * vars->zym;
			}
			if (vars->iter < vars->it_max)
				my_mlx_pixel_put(img, vars->x, vars->y,
					gradient(COL_ST, COL_FIN, vars->iter, vars->it_max));
			else
				my_mlx_pixel_put(img, vars->x, vars->y, BLACK);
		}
	}
}

void	ft_mandelbrot(t_vars *vars, t_data *img)
{
	while (++vars->y < HEIGHT)
	{
		vars->x = 1;
		while (++vars->x < WIDTH)
		{
			init_fractol(vars);
			while ((vars->zsqxm + vars->zsqym <= 4)
				&& vars->iter < vars->it_max)
			{
				vars->i = vars->zsqxm - vars->zsqym + vars->px;
				vars->zym = 2 * vars->zxm * vars->zym + vars->py;
				vars->zxm = vars->i;
				vars->iter++;
				vars->zsqxm = vars->zxm * vars->zxm;
				vars->zsqym = vars->zym * vars->zym;
			}
			if (vars->iter < vars->it_max)
				my_mlx_pixel_put(img, vars->x, vars->y,
					gradient(COL_ST, COL_FIN, vars->iter, vars->it_max));
			else
				my_mlx_pixel_put(img, vars->x, vars->y, BLACK);
		}
	}
}

void	ft_julia(t_vars *vars, t_data *img)
{
	while (++vars->y < HEIGHT)
	{
		vars->x = 1;
		while (++vars->x < WIDTH)
		{
			init_fractol(vars);
			while ((vars->zsqx + vars->zsqy <= 4) && vars->iter < vars->it_max)
			{
				vars->i = vars->zsqx - vars->zsqy + vars->cx;
				vars->zy = 2 * vars->zx * vars->zy + vars->cy;
				vars->zx = vars->i;
				vars->iter++;
				vars->zsqx = vars->zx * vars->zx;
				vars->zsqy = vars->zy * vars->zy;
			}
			if (vars->iter < vars->it_max)
				my_mlx_pixel_put(img, vars->x, vars->y,
					gradient(COL_ST, COL_FIN, vars->iter, vars->it_max));
			else
				my_mlx_pixel_put(img, vars->x, vars->y, BLACK);
		}
	}
}

void	init_fractol(t_vars *vars)
{
	vars->px = 2 * vars->zoom * (vars->x - WIDTH / 2) / (0.5 * WIDTH)
		+ vars->new_w;
	vars->py = vars->zoom * (vars->y - HEIGHT / 2) / (0.5 * HEIGHT)
		+ vars->new_h;
	vars->zx = 1.5 * vars->zoom * (vars->x - WIDTH / 2) / (0.5 * WIDTH);
	vars->zy = vars->zoom * (vars->y - HEIGHT / 2) / (0.5 * HEIGHT);
	vars->zxm = 0;
	vars->zym = 0;
	vars->i = 0;
	vars->iter = 0;
	vars->zsqxm = vars->zxm * vars->zxm;
	vars->zsqym = vars->zym * vars->zym;
	vars->zsqx = vars->zx * vars->zx;
	vars->zsqy = vars->zy * vars->zy;
}

void	draw_fractol(t_vars *vars)
{
	t_data	img;

	mlx_clear_window(vars->mlx, vars->win);
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	vars->y = 1;
	if (ft_strncmp(vars->fractol, "mandelbrot", 10) == 0)
		ft_mandelbrot(vars, &img);
	else if (ft_strncmp(vars->fractol, "julia", 10) == 0)
		ft_julia(vars, &img);
	else if (ft_strncmp(vars->fractol, "tricorn", 7) == 0)
		ft_tricorn(vars, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 1, 1);
}
