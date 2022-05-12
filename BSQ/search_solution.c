/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:10:18 by estina            #+#    #+#             */
/*   Updated: 2019/09/24 01:27:21 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_value(t_map *map, int **aux, int row, int col)
{
	if ((*map).table[row][col] != (*map).layout.obstacle)
	{
		if (aux[row][col - 1] <= aux[row - 1][col])
		{
			if (aux[row][col - 1] <= aux[row - 1][col - 1])
				aux[row][col] = aux[row][col - 1] + 1;
			else
				aux[row][col] = aux[row - 1][col - 1] + 1;
		}
		else if (aux[row - 1][col] <= aux[row - 1][col - 1])
			aux[row][col] = aux[row - 1][col] + 1;
		else
			aux[row][col] = aux[row - 1][col - 1] + 1;
	}
	else
		aux[row][col] = 0;
	if (aux[row][col] > (*map).max.value)
	{
		(*map).max.value = aux[row][col];
		(*map).max.row = row;
		(*map).max.col = col;
	}
}

void	ft_fill_walls(t_map map, int **aux)
{
	int i;
	int j;

	i = 0;
	while (i < map.num_rows)
	{
		j = 0;
		while (j < map.num_cols)
		{
			if (i == 0 || j == 0)
			{
				if (map.table[i][j] == map.layout.obstacle)
					aux[i][j] = 0;
				else
					aux[i][j] = 1;
			}
			else
				aux[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_find_max_sqr(t_map *map, int **aux_table)
{
	int i;
	int j;

	i = 1;
	ft_fill_walls(*map, aux_table);
	while (i < (*map).num_rows)
	{
		j = 1;
		while (j < (*map).num_cols)
		{
			ft_put_value(map, aux_table, i, j);
			j++;
		}
		i++;
	}
}

void	ft_search_solution(t_map *map)
{
	int		**aux_table;
	int		i;

	aux_table = malloc((*map).num_rows * 8);
	i = 0;
	(*map).max.value = 0;
	(*map).max.row = 0;
	(*map).max.col = 0;
	while (i < (*map).num_rows)
	{
		aux_table[i] = malloc((*map).num_cols * sizeof(int));
		i++;
	}
	ft_find_max_sqr(map, aux_table);
	ft_draw_sqr(map);
	free(aux_table);
}
