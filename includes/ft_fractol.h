/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:13:11 by acollin           #+#    #+#             */
/*   Updated: 2021/08/30 22:13:14 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define WIDTH 480
# define HEIGHT 360
# define ESC_KEY 53
# define ARROW_L 123
# define ARROW_R 124
# define ARROW_D 125
# define ARROW_U 126
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define COL_ST 0x75E555
# define COL_FIN 0xE8811A
# define BLACK 0x000000

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

typedef struct sdata {
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_data;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	double		i;
	int			iter;
	double		px;
	double		py;
	int			xm;
	int			ym;
	double		cx;
	double		cy;
	double		zx;
	double		zy;
	double		zxm;
	double		zym;
	double		zoom;
	t_data		*img;
	char		*fractol;
	double		zsqx;
	double		zsqy;
	double		zsqxm;
	double		zsqym;
	double		move_x;
	double		move_y;
	double		new_w;
	double 		new_h;
	int			it_max;
}				t_vars;

void	init(t_vars *vars);
int		close_win(int keycode);
int		key_hook(int keycode, t_vars *vars);
int		mouse_get_pos(int mousecode, int x, int y, t_vars *vars);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
void	ft_mandelbrot(t_vars *vars, t_data *img);
void	ft_julia(t_vars *vars, t_data *img);
void	ft_tricorn(t_vars *vars, t_data *img);
int		gradient(int startcolor, int endcolor, int len, int pix);
void	draw_fractol(t_vars *vars);
void	init_fractol(t_vars *vars);
void	params(char **argv, t_vars *vars);
void	zoom(t_vars *vars, int x, int y);

#endif
