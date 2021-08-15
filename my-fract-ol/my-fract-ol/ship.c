/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwookim <namwookim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:15:22 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/15 22:18:12 by namwookim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ship(t_vars *vars, double x, double y)
{
	int			cycle;
	double		put_x;
	double		put_y;
	t_complex	zn;
	t_complex	input;

	init_complex(&zn, 0, 0);
	init_complex(&input, x, y);
	cycle = N_NUM;
	while (cycle-- && !isdvg_complex(zn))
	{
		zn.real = fabs(zn.real);
		zn.imaginary = fabs(zn.imaginary);
		zn = sum_complex(pow_complex(zn), input);
	}
	put_x = (x + MAX_X) * (WIDTH / (MAX_X * 2));
	put_y = (y + MAX_Y) * (HEIGHT / (MAX_Y * 2));
	put_x = (WIDTH / 2) + (put_x - (WIDTH / 2)) * vars->zoom;
	put_y = (HEIGHT / 2) + (put_y - (HEIGHT / 2)) * vars->zoom;
	if (isdvg_complex(zn) && (put_x > 0) && ((int)put_x < WIDTH)
		&& (put_y > 0) && ((int)put_y < HEIGHT))
		pixel_put(&vars->img, (int)put_x, (int)put_y, PURPLE * (cycle * 7));
	else
		pixel_put(&vars->img, (int)put_x, (int)put_y, BLACK);
}

static void	draw_ship(t_vars *vars)
{
	double	x;
	double	y;

	mlx_clear_window(vars->mlx, vars->win);
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	y = MAX_Y / vars->zoom;
	while (y > -(MAX_Y / vars->zoom))
	{
		x = MAX_X / vars->zoom;
		while (x > -(MAX_X / vars->zoom))
		{
			ship(vars, x, y);
			x -= (DX / vars->zoom);
		}
		y -= (DY / vars->zoom);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

static int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == ZOOM_IN && vars->zoom < ZOOM_MAX)
	{
		vars->zoom *= 1.2;
		draw_ship(vars);
	}
	else if (button == ZOOM_OUT && vars->zoom >= 1.2)
	{
		vars->zoom /= 1.2;
		draw_ship(vars);
	}
	else if (button == CLK_LEFT)
	{
		vars->num.real = ((double)(x - WIDTH / 2))
			/ ((double)(WIDTH / 2)) * MAX_X;
		vars->num.imaginary = ((double)(y - HEIGHT / 2))
			/ ((double)(HEIGHT / 2)) * MAX_Y;
	}
	return (0);
}

int	ship_main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (0);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Mandelbrot");
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	vars.zoom = 1;
	vars.num.real = -0.8;
	vars.num.imaginary = 0.156;
	draw_ship(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 4, 1L << 3, mouse_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
