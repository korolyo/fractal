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

void	ft_mandelbrot(t_vars *vars, t_data *img)
{
	while (++vars->y < HEIGHT)
	{
		vars->x = 1;
		while (++vars->x < WIDTH)
		{
			init_mandelbrot(vars);
			while ((vars->zsqx + vars->zsqy <= 4) && vars->iter < ITER_MAX)
			{
				vars->i = vars->zsqx - vars->zsqy + vars->px;
				vars->zy = 2 * vars->zx * vars->zy + vars->py;
				vars->zx = vars->i;
				vars->iter++;
				vars->zsqx = vars->zx * vars->zx;
				vars->zsqy = vars->zy * vars->zy;
			}
			if (vars->iter < ITER_MAX)
				my_mlx_pixel_put(img, vars->x, vars->y,
					gradient(COL_ST, COL_FIN, vars->iter, ITER_MAX));
			else
				my_mlx_pixel_put(img, vars->x, vars->y, BLACK);
		}
	}
}

void	init_mandelbrot(t_vars *vars)
{
	vars->px = 2 * vars->zoom * (vars->x - WIDTH / 2) / (0.5 * WIDTH) +
			vars->moveX;
	vars->py = vars->zoom * (vars->y - HEIGHT / 2) / (0.5 * HEIGHT) +
			vars->moveY;
	vars->zx = 0.0;
	vars->zy = 0.0;
	vars->i = 0;
	vars->iter = 0;
	vars->zsqx = vars->zx * vars->zx;
	vars->zsqy = vars->zy * vars->zy;
}

void	ft_julia(t_vars *vars, t_data *img)
{
	while (++vars->y < HEIGHT)
	{
		vars->x = 1;
		while (++vars->x < WIDTH)
		{
			init_julia(vars);
			while ((vars->zsqx + vars->zsqy <= 4) && vars->iter < ITER_MAX)
			{
				vars->i = vars->zsqx - vars->zsqy + vars->cx;
				vars->zy = 2 * vars->zx * vars->zy + vars->cy;
				vars->zx = vars->i;
				vars->iter++;
				vars->zsqx = vars->zx * vars->zx;
				vars->zsqy = vars->zy * vars->zy;
			}
			if (vars->iter < ITER_MAX)
				my_mlx_pixel_put(img, vars->x, vars->y,
					gradient(COL_ST, COL_FIN, vars->iter, ITER_MAX));
			else
				my_mlx_pixel_put(img, vars->x, vars->y, BLACK);
		}
	}
}

void	init_julia(t_vars *vars)
{
	vars->zx = 1.5 * vars->zoom * (vars->x - WIDTH / 2) / (0.5 * WIDTH);
	vars->zy = vars->zoom * (vars->y - HEIGHT / 2) / (0.5 * HEIGHT);
	vars->i = 0;
	vars->iter = 0;
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
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 1, 1);
}
