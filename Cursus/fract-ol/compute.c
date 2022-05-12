/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:21:36 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/15 09:32:25 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute(int x, int y, t_env *e)
{
	if (e->fractal == 1)
		mandelbrot_compute(x, y, e);
	if (e->fractal == 2)
		julia_compute(x, y, e);
	if (e->fractal == 3)
		black_hole_compute(x, y, e);
}
