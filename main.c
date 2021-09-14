/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acollin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:12:11 by acollin           #+#    #+#             */
/*   Updated: 2021/08/30 22:12:22 by acollin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	params(char **argv, t_vars *vars)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		vars->fractol = "mandelbrot";
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		vars->fractol = "julia";
	else if (ft_strncmp(argv[1], "tricorn", 7) == 0)
		vars->fractol = "tricorn";
	else
	{
		write(1, &"Wrong input! Here is available sets for this moment:\n->"
			"mandelbrot\n->julia\n->tricorn\n", 84);
		exit(0);
	}
	draw_fractol(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	init(&vars);
	if (argc > 1)
		params(argv, &vars);
	else
	{
		write(1, &"Wrong input! Here is available sets for this moment:\n->"
			"mandelbrot\n->julia\n->tricorn\n", 84);
		exit(0);
	}
	mlx_mouse_hook(vars.win, mouse_get_pos, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, 0);
	mlx_loop(vars.mlx);
	return (0);
}
