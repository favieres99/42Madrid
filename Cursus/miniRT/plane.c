/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 03:59:28 by gfaviere          #+#    #+#             */
/*   Updated: 2020/03/06 05:50:04 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void		plane(t_data img)
{
	int		i;
	int		j;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			my_mlx_pixel_put(&img, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
	i = 500;
	while (i < 1000)
	{
		j = 0;
		while (j < 1000)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
}