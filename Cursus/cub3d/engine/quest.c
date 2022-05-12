/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quest.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:03:17 by gfaviere          #+#    #+#             */
/*   Updated: 2021/02/16 10:18:11 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		check_quest(t_game *game)
{
	if (MAP(game->camera.pos, game->config) == '4')
	{
		MAP(game->camera.pos, game->config) = '0';
		game->collected++;
		delete_sprite(&game->sprites, &game->camera.pos);
	}
}

void		count_items(t_game *game)
{
	int		i;
	int		j;

	game->to_collect = 0;
	i = 0;
	while (i < game->config.rows)
	{
		j = 0;
		while (j < game->config.columns)
		{
			if (MAP_XY(j, i, game->config) == '4')
				game->to_collect++;
			j++;
		}
		i++;
	}
}
