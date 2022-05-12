/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 23:14:12 by estina            #+#    #+#             */
/*   Updated: 2019/09/23 23:52:19 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_draw_sqr(t_map *map)
{
	int i;
	int j;
	int row;
	int col;

	i = 0;
	row = (*map).max.row;
	col = (*map).max.col;
	while (i < (*map).max.value)
	{
		j = 0;
		while (j < (*map).max.value)
		{
			(*map).table[row - i][col - j] = (*map).layout.full;
			j++;
		}
		i++;
	}
}
