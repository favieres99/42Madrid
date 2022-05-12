/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:10:41 by marvin            #+#    #+#             */
/*   Updated: 2021/06/15 12:25:37 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	black_hole_compute(int x, int y, t_env *e)
{
	int		iter;
	double	r;
	double	i;
	double	r_save;

	iter = 0;
	e->map[y / 180].d_r = (double)4 / sqrt(e->zoom);
	e->map[y / 180].d_i = (double) -4 / sqrt(e->zoom);
	e->map[y / 180].z_r = x / e->winx * e->map[y / 180].d_r + e->zd_r + e->os_r;
	e->map[y / 180].z_i = y / e->winy * e->map[y / 180].d_i + e->zd_i + e->os_i;
	r = 0;
	i = 0;
	while (iter < e->imax && (((r) * (r)) + ((i) * (i))) <= 4)
	{
		r_save = r;
		r = (r * r - i * i) + e->map[y / 180].z_r;
		i = ((double)3 * r_save * (double)i) + e->map[y / 180].z_i;
		iter++;
	}
	pixel_put(e, iter, x, y);
}

void	mandelbrot_compute(int x, int y, t_env *e)
{
	int		iter;
	double	r;
	double	i;
	double	r_save;

	iter = 0;
	e->map[y / 180].d_r = (double)4 / sqrt(e->zoom);
	e->map[y / 180].d_i = (double) -4 / sqrt(e->zoom);
	e->map[y / 180].z_r = x / e->winx * e->map[y / 180].d_r + e->zd_r + e->os_r;
	e->map[y / 180].z_i = y / e->winy * e->map[y / 180].d_i + e->zd_i + e->os_i;
	r = 0;
	i = 0;
	while (iter < e->imax && ((r * r) + (i * i)) <= 4)
	{
		r_save = r;
		r = (r * r - i * i) + e->map[y / 180].z_r;
		i = ((double)2 * (double)r_save * (double)i) + e->map[y / 180].z_i;
		iter++;
	}
	pixel_put(e, iter, x, y);
}

void	julia_compute(int x, int y, t_env *e)
{
	int		iter;
	double	r;
	double	i;
	double	r_save;

	iter = 0;
	e->map[y / 180].d_r = (double)4 / sqrt(e->zoom);
	e->map[y / 180].d_i = (double) -4 / sqrt(e->zoom);
	r = (double)x / e->winy * e->map[y / 180].d_r + e->zd_r + e->os_r;
	i = (double)y / e->winx * e->map[y / 180].d_i + e->zd_i + e->os_i;
	e->map[y / 180].z_r = e->julia_r;
	e->map[y / 180].z_i = e->julia_i;
	while (iter < e->imax && ((r * r) + (i * i)) <= 4)
	{
		r_save = r;
		r = (r * r - i * i) + e->map[y / 180].z_r;
		i = ((double)2 * (double)r_save * (double)i) + e->map[y / 180].z_i;
		iter++;
	}
	pixel_put(e, iter, x, y);
}

void	draw(t_env *e)
{
	pthread_t	*threads;
	void		*ret;
	int			i;

	threads = (pthread_t *)malloc(8 * sizeof(pthread_t));
	pthread_create(&threads[0], NULL, draw_0, e);
	pthread_create(&threads[1], NULL, draw_1, e);
	pthread_create(&threads[2], NULL, draw_2, e);
	pthread_create(&threads[3], NULL, draw_3, e);
	pthread_create(&threads[4], NULL, draw_4, e);
	pthread_create(&threads[5], NULL, draw_5, e);
	pthread_create(&threads[6], NULL, draw_6, e);
	pthread_create(&threads[7], NULL, draw_7, e);
	i = 0;
	while (i != 8)
		pthread_join(threads[i++], &ret);
	free(threads);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
}
