/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:11:59 by marvin            #+#    #+#             */
/*   Updated: 2021/06/15 13:52:26 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mlx2(t_env *e)
{
	e->img = mlx_new_image(e->ptr, e->winx, e->winy);
	if (!e->img)
	{
		mlx_destroy_window(e->ptr, e->win);
		free(e->ptr);
		return (1);
	}
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sz_l, &e->endian);
	if (!e->data)
	{
		mlx_destroy_image(e->ptr, e->img);
		mlx_destroy_window(e->ptr, e->win);
		free(e->ptr);
		return (1);
	}
	return (0);
}

int	init_mlx(t_env *e)
{
	int	i;

	e->ptr = mlx_init();
	if (!e->ptr)
		return (1);
	e->win = mlx_new_window(e->ptr, e->winx, e->winy, "fractol");
	if (!e->win)
	{
		free(e->ptr);
		return (1);
	}
	i = init_mlx2(e);
	if (i == 1)
		return (i);
	e->sz_i = ft_strlen(e->data);
	mlx_hook(e->win, 2, 1L << 1, key_hook, e);
	mlx_hook(e->win, 6, 1L << 1, cursor_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	return (0);
}

void	init_env(t_env *e, int	x)
{
	int		i;

	i = -1;
	if (x == 0)
		e->map = (t_map *)malloc(8 * sizeof(t_map));
	while (++i != 8)
		e->map[i].y_min = 180 * i;
	e->imax = 50;
	e->zoom = 1;
	e->zd_r = -2;
	e->zd_i = 2;
	e->lock = 0;
	e->julia_i = 0;
	e->julia_r = 0;
	e->os_i = 0;
	e->os_r = 0;
	e->r = 0;
	e->g = 2;
	e->b = 4;
	e->winx = 1444;
	e->winy = 1444;
}

int	main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		init_env(&e, 0);
		if (init_mlx(&e))
			ft_error("mlx_init failed");
		e.fractal = check_arg(argv[1]);
		if (e.fractal == 0)
		{
			ft_putstr("Options:\n./fractol mandelbrot\n");
			ft_putstr("./fractol julia\n./fractol black_hole\n");
			exit(0);
		}
		draw(&e);
		mlx_loop(e.ptr);
	}
	else
	{
		ft_putstr("Options:\n./fractol mandelbrot\n");
		ft_putstr("./fractol julia\n./fractol black_hole\n");
	}
	return (0);
}
