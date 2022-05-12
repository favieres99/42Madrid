/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:07:28 by gfaviere          #+#    #+#             */
/*   Updated: 2019/09/25 19:38:46 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_map(t_map map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map.num_rows)
	{
		while (j < map.num_cols)
		{
			write(1, &map.table[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	ft_help_me(char *input, t_map *map)
{
	input = ft_read_extern();
	ft_read_input(input, map);
	if ((*map).num_cols == -1 || ft_error_check(*map))
		write(1, "map error\n", 10);
	else
	{
		ft_search_solution(map);
		ft_print_map(*map);
	}
}

int		main(int argc, char **argv)
{
	t_map	map;
	char	*input;
	int		i;

	i = 0;
	input = NULL;
	if (argc >= 2)
	{
		while (++i < argc)
		{
			map = ft_read_file(argv[i]);
			if (map.num_cols == -1 || ft_error_check(map))
				write(1, "map error\n", 10);
			else
			{
				ft_search_solution(&map);
				ft_print_map(map);
				if (i < argc - 1)
					write(1, "\n", 1);
			}
		}
	}
	else
		ft_help_me(input, &map);
	return (0);
}
