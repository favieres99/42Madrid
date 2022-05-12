/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 11:26:57 by estina            #+#    #+#             */
/*   Updated: 2019/09/25 18:56:35 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	ft_error_check(t_map map)
{
	int		i;
	int		j;

	i = -1;
	if (map.layout.empty == map.layout.full
		|| map.layout.empty == map.layout.obstacle
		|| map.layout.full == map.layout.obstacle
		|| (map.layout.obstacle < 32 || map.layout.obstacle > 126)
		|| (map.layout.empty < 32 || map.layout.empty > 126)
		|| (map.layout.full < 32 || map.layout.full > 126))
		return (1);
	while (++i < map.num_rows)
	{
		j = -1;
		while (++j < map.num_cols)
		{
			if (map.table[i][j] == '\0'
				|| (map.table[i][j] != map.layout.obstacle
				&& map.table[i][j] != map.layout.empty)
				|| map.table[i][j] == map.layout.full)
				return (1);
		}
	}
	return (0);
}

int		ft_ptr_nl(int *row, int *col, t_map *map)
{
	if (*col > (*map).num_cols || *col < (*map).num_cols)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	(*row)++;
	*col = -1;
	return (0);
}

void	ft_ptr_nl_zero(int *row, int *col, char *aux, t_map *map)
{
	(*map).num_cols = *col;
	ft_malloc_table(*row, *col, map, aux);
	(*row)++;
	*col = -1;
}

void	ft_structure_maker(t_map *map, char *aux, int size)
{
	int i;

	i = 0;
	(*map).num_rows = 0;
	size--;
	(*map).layout.full = aux[size--];
	(*map).layout.obstacle = aux[size--];
	(*map).layout.empty = aux[size--];
	while (i <= size)
		(*map).num_rows = (*map).num_rows * 10 + aux[i++] - '0';
}
