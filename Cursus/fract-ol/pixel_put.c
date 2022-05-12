/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:19:09 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/15 09:59:22 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_env *e, int i, int x, int y)
{
	int		index;
	double	ct_index;

	ct_index = i + 1 - 2 * log(3) / sqrt((e->map[y / 180].z_r
				* e->map[y / 180].z_r) + (e->map[y / 180].z_i
				* e->map[y / 180].z_i));
	index = (x * (e->bpp / 8)) + (y * e->sz_l);
	if (i == e->imax)
	{
		e->data[index] = 0;
		e->data[index + 1] = 0;
		e->data[index + 2] = 0;
	}
	else
	{
		e->data[index] = (sin(0.1 * ct_index + e->r) * 50 + 200);
		e->data[index + 1] = (sin(0.1 * ct_index + e->g) * 50 + 200);
		e->data[index + 2] = (sin(0.1 * ct_index + e->b) * 50 + 200);
	}
}

void	mouse_hook2(int x, int y, t_env *e)
{
	e->zoom /= 4;
	e->map[0].z_r = (double)x / e->winx * e->map[0].d_r + e->zd_r;
	e->map[0].z_i = (double)y / e->winy * e->map[0].d_i + e->zd_i;
	e->map[0].d_r = (double)4 / sqrt(e->zoom);
	e->map[0].d_i = (double) -4 / sqrt(e->zoom);
	e->zd_r = -(((double)x * (e->map[0].d_r / e->winx))) + e->map[0].z_r;
	e->zd_i = -(((double)y * ((e->map[0].d_i) / e->winy))) + e->map[0].z_i;
}
