#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)
# define WIDTH 800
# define HEIGHT 600

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

typedef struct	sdata {
	void		*img;
	char		*addr;
	int 		bpp;
	int 		line_len;
	int 		endian;
}				t_data;

typedef	struct	s_vars {
	void		*mlx;
	void 		*win;
	int			x;
	int			y;
	double		i;
	int			iter;
	double		px;
	double		py;
	int			xm;
	int 		ym;
	double		cx;
	double		cy;
	double		zx;
	double		zy;
	double		zoom;
	t_data		*img;
}				t_vars;

#endif
