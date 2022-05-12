/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 06:38:04 by gfaviere          #+#    #+#             */
/*   Updated: 2020/04/15 17:56:11 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		cylinder(t_data img)
{
	int	i = 500, j = 500, h = 200, d = 120, k = 0;

	while (k < 3600)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
		i = 500 + d * cos(k);
		j = 500 - h + d * sin(k);
		k++;
	}
	j = 500;
	i = 500;
	while (j < 500 + h)
	{
		my_mlx_pixel_put(&img, i - 120, j - h, 0x00FFFFFF);
		j++;
	}
	j = 500;
	i = 500;
	while (j < 500 + h)
	{
		my_mlx_pixel_put(&img, i + 120, j - h, 0x00FFFFFF);
		j++;
	}
	k = 0;
	while (k < 3600)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
		i = 500 + d * cos(k);
		j = 500 + d * sin(k);
		k++;
	}
	k = 0;
	while (k < 360)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		
	}
}
