/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:15:45 by gfaviere          #+#    #+#             */
/*   Updated: 2019/09/25 19:37:59 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_input_map_table(char *str, t_map *map, int col, int row)
{
	int i;

	i = 0;
	if (row == 0)
		ft_malloc_table(row, col, map, str);
	if (col > (*map).num_cols)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	while (i < col)
	{
		(*map).table[row][i] = str[i];
		i++;
	}
	return (1);
}

void	ft_layout_fill(char *input, int *i, char *aux, t_map *map)
{
	while (input[*i] != '\n')
	{
		aux[*i] = input[*i];
		if (*i > 40)
		{
			write(1, "map error\n", 10);
			exit(-1);
		}
		(*i)++;
	}
	ft_structure_maker(map, aux, *i);
}

int		ft_fill_input_map(int *row, int *col, char *aux, t_map *map)
{
	if (*row == 0)
	{
		(*map).num_cols = *col;
	}
	if (!ft_input_map_table(aux, map, *col, *row))
	{
		(*map).num_cols = -1;
		return (0);
	}
	(*row)++;
	*col = 0;
	return (1);
}

void	ft_read_input(char *input, t_map *map)
{
	int		i;
	int		col;
	char	*aux;
	int		row;

	i = 0;
	col = 0;
	row = 0;
	while (input[i])
		i++;
	aux = malloc(i);
	i = 0;
	ft_layout_fill(input, &i, aux, map);
	i++;
	while (input[i] && row < (*map).num_rows)
	{
		if (input[i] != '\n')
			aux[col++] = input[i];
		else if (!ft_fill_input_map(&row, &col, aux, map))
			break ;
		i++;
	}
	free(aux);
}
