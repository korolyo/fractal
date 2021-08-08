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
	const int ixMax = 1000;
	const int iyMax = 1000;
	const double c_x_min = -2.5;
	const double c_x_max = 1.5;
	const double c_y_min = -2.0;
	const double c_y_max = 2.0;
	double pix_width;
	double pix_heigth;
	double cx;
	double cy;
	double zx;
	double zy;

	x = 1;
	y = 1;
	pix_width  = (c_x_max - c_x_min)/ixMax;
	pix_heigth = (c_y_max - c_y_min)/iyMax;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
								 &img.endian);
	while (y <= iyMax-1)
	{
			cy = y * pix_heigth + y * pix_heigth;
			if (fabs(cy) < pix_heigth / 2)
				cy = 0.0;
			while (x <= ixMax-1)
			{
				cx = c_x_min + x * pix_width;
				zx = 0.0;
				zy = 0.0;
				iter = 0;
				while (zx * zx + zy * zy < 4 && iter <= iter_max)
				{
					i = zx * zx - zy * zy + cx;
					zy = 2 * zx * zy + cy;
					zx = i;
					iter++;
				}
				my_mlx_pixel_put(&img, zx, zy, 0x00FF0000);
				x++;
			}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
