#include "ft_fractol.h"

typedef struct	sdata {
	void		*img;
	char		*addr;
	int 		bits_per_pixel;
	int 		line_len;
	int 		endian;
}				t_data;

typedef	struct	s_vars {
	void		*mlx;
	void 		*win;
}				t_vars;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars  *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main()
{
	t_vars vars;
	t_data	img;
	double x;
	double y;
	double i;
	int iter_max = 1000;
	int iter;
	const int width = 1920;
	const int height = 1080;
	double px;
	double py;
	double zx;
	double zy;

	x = 1;
	y = 1;
	iter = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Mandelbrot set");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
								 &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	while (y <= height)
	{
			while (x <= width)
			{
				px = (x - width/2) * 4 / width;
				py = (y - height/2) * 4 / height;
				zx = 0.0;
				zy = 0.0;
				iter = 0;
				while (zx * zx + zy * zy < 4 && iter <= iter_max)
				{
					i = zx * zx - zy * zy + px;
					zy = 2 * zx * zy + py;
					zx = i;
					iter++;
				}
				if (iter == 1000)
					my_mlx_pixel_put(&img, x, y, 0x00FF0000);
				else
					my_mlx_pixel_put(&img, x, y, 0x00FF0000);
				x++;
			}
		y++;
	}
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
