/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:00:50 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/09 18:30:41 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void		check_for_camera(char **map, t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (y < config->rows)
	{
		x = 0;
		while (x < config->columns)
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' ||
				map[y][x] == 'W' || map[y][x] == 'E')
			{
				config->camera_x = x;
				config->camera_y = y;
			}
			x++;
		}
		y++;
	}
}

static char		**put_map_in_array(t_str *map_buffer, t_config *config)
{
	int		x;
	char	**map;

	map = NULL;
	x = 0;
	if (!(map = (char**)malloc(sizeof(*map) * config->rows + 1)))
		return (0);
	while (map_buffer)
	{
		map[x] = ft_strdup_special(map_buffer->content, config);
		x++;
		map_buffer = map_buffer->next;
	}
	map[x] = 0;
	check_for_camera(map, config);
	return (map);
}

static void		boundaryfill4(int x, int y, char **map, t_config *config)
{
	if (x != -1 && y != -1 && x < config->rows && y < config->columns &&
		map[x][y] != 'x')
	{
		if (map[x][y] != '1')
		{
			map[x][y] = '1';
			boundaryfill4(x + 1, y, map, config);
			boundaryfill4(x, y + 1, map, config);
			boundaryfill4(x - 1, y, map, config);
			boundaryfill4(x, y - 1, map, config);
		}
	}
	else
	{
		free(map);
		write(1, "Map error.\n", 11);
		exit(0);
	}
}

int				copy_map(t_config *config, t_str *map_buffer, int *map)
{
	int		i;
	int		j;
	int		line;
	int		has_camera;

	i = 0;
	has_camera = 0;
	while (map_buffer)
	{
		j = 0;
		line = 0;
		while (map_buffer->content[j])
		{
			map[(i * config->columns) + line++] = map_buffer->content[j];
			if (ft_in_set(map_buffer->content[j], DIRECTIONS))
				has_camera++;
			j++;
		}
		map_buffer = map_buffer->next;
		i++;
	}
	return (has_camera);
}

int				parse_map(t_config *config, t_str *map_buffer)
{
	int			*map;
	char		**map_in_array;
	int			x;

	x = 0;
	map = NULL;
	map_in_array = NULL;
	if ((config->columns = count_columns(map_buffer)) <= 2
		|| (config->rows = count_rows(map_buffer)) <= 2)
		return (0);
	if (!(map = (int*)malloc(sizeof(*map) * (config->rows * config->columns))))
		return (0);
	if (copy_map(config, map_buffer, map) != 1)
		return (0);
	config->map = map;
	map_in_array = put_map_in_array(map_buffer, config);
	boundaryfill4(config->camera_y, config->camera_x, map_in_array, config);
	while (x < config->rows)
		free(map_in_array[x++]);
	free(map_in_array);
	return (1);
}
