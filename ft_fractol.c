
#include "ft_fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;
	new[0] = (R(startcolor)) + fabs(pix * increment[0]);
	new[1] = (G(startcolor)) + fabs(pix * increment[1]);
	new[2] = (B(startcolor)) + fabs(pix * increment[2]);
	newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
}

void	ft_mandelbrot(t_vars *vars)
{
	t_data img;

	mlx_clear_window(vars->mlx, vars->win);
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	vars->y = 1;
	while (vars->y < HEIGHT)
	{
		vars->x = 1;
		while (vars->x < WIDTH)
		{
			vars->px = 2 * (vars->x - WIDTH / 2) / (0.5 * WIDTH * vars->zoom);
			vars->py = (vars->y - HEIGHT / 2) / (0.5 * HEIGHT * vars->zoom);
			vars->zx = 0.0;
			vars->zy = 0.0;
			vars->i = 0;
			vars->iter = 0;
			while ((vars->zx * vars->zx + vars->zy * vars->zy <= 4)
			&& vars->iter < 800)
			{
				vars->i = vars->zx * vars->zx - vars->zy * vars->zy + vars->px;
				vars->zy = 2 * vars->zx * vars->zy + vars->py;
				vars->zx = vars->i;
				vars->iter++;
			}
			if (vars->iter < 800)
				my_mlx_pixel_put(&img, vars->x, vars->y,
						ft_gradient(0x75E555, 0xE8811A, vars->iter, 1000));
			else
				my_mlx_pixel_put(&img, vars->x, vars->y, 0x000000);
			vars->x++;
		}
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 1, 1);
}

int	mouse_get_pos(int mousecode, t_vars *vars)
{
//	vars->zoom += 0.1;
	if (mousecode == 5)
	{
		printf("%d\n", mousecode);
		ft_mandelbrot(vars);
	}
	else if (mousecode == 4)
	{
		printf("%d\n", mousecode);
		ft_mandelbrot(vars);
	}
	return (0);
}

void	ft_julia(t_vars *vars)
{
	t_data img;

	mlx_clear_window(vars->mlx, vars->win);
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	vars->y = 1;
	while (vars->y < HEIGHT)
	{
		vars->x = 1;
		while (vars->x < WIDTH)
		{
			vars->zx = 2 * (vars->x - WIDTH / 2) / (0.5 * WIDTH);
			vars->zy = (vars->y - HEIGHT / 2) / (0.5 * HEIGHT);
			vars->i = 0;
			vars->iter = 0;
			vars->cx = 2 * (vars->xm - WIDTH / 2) / (0.5 * WIDTH);
			vars->cy = (vars->ym - HEIGHT / 2) / (0.5 * HEIGHT);
			while ((vars->zx * vars->zx + vars->zy * vars->zy <= 4)
			&& vars->iter < 1000)
			{
				vars->i = vars->zx * vars->zx - vars->zy * vars->zy;
				vars->zy = 2 * vars->zx * vars->zy + vars->cy;
				vars->zx = vars->i + vars->cx;
				vars->iter++;
			}
			if (vars->iter < 1000)
				my_mlx_pixel_put(&img, vars->x, vars->y,
								 ft_gradient(0x75E555, 0xE8811A, vars->iter, 1000));
			else
				my_mlx_pixel_put(&img, vars->x, vars->y, 0x000000);
			vars->x++;
		}
		vars->y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 1, 1);
}

void init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Mandelbrot");
	vars->zoom = 1;
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init(&vars);
	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
			ft_mandelbrot(&vars);
		if (ft_strncmp(argv[1], "Julia", 5) == 0)
			ft_julia(&vars);
	}
	else
	{
		write(1, &"Wrong input! Here is available sets for this moment:\n "
			"Mandelbrot\n Julia\n", 72);
		exit(0);
	}
	mlx_hook(vars.win, 4, 0, mouse_get_pos, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
