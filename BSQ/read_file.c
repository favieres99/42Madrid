/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 00:11:52 by gfaviere          #+#    #+#             */
/*   Updated: 2019/09/25 19:35:48 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			ft_malloc_table(int row, int col, t_map *map, char *aux)
{
	int i;

	i = 0;
	if (row == 0)
	{
		(*map).num_cols = col;
		(*map).table = malloc(8 * (*map).num_rows);
		while (i < (*map).num_rows)
		{
			(*map).table[i] = malloc((*map).num_cols);
			i++;
		}
		i = 0;
		while (i < col)
		{
			(*map).table[row][i] = aux[i];
			i++;
		}
	}
}

void			ft_fill_map_table(int file, t_map *map, char *ptr)
{
	int		row;
	int		col;
	char	*aux;

	row = 0;
	col = 0;
	aux = malloc(2000);
	while (read(file, ptr, 1) && row < (*map).num_rows)
	{
		if (*ptr == '\n' && row == 0)
			ft_ptr_nl_zero(&row, &col, aux, map);
		else if (*ptr == '\n')
		{
			if (ft_ptr_nl(&row, &col, map))
				break ;
		}
		else if (*ptr != '\n' && row == 0)
			aux[col] = *ptr;
		else
			(*map).table[row][col] = *ptr;
		col++;
	}
	free(aux);
}

void			ft_map_maker(int file, t_map *map)
{
	char	*ptr;
	int		stream;
	char	*aux;
	int		i;

	ptr = malloc(1);
	aux = malloc(10);
	i = 0;
	stream = read(file, ptr, 1);
	while (*ptr != '\n' && stream)
	{
		aux[i++] = *ptr;
		stream = read(file, ptr, 1);
	}
	ft_structure_maker(map, aux, i);
	ft_fill_map_table(file, map, ptr);
	free(ptr);
}

t_map			ft_read_file(char *str)
{
	char	*file_name;
	int		file;
	t_map	map;

	file_name = str;
	if ((file = open(file_name, O_RDONLY)) != -1)
	{
		ft_map_maker(file, &map);
		close(file);
	}
	else
	{
		map.num_cols = -1;
		write(1, "map error\n", 10);
	}
	return (map);
}
