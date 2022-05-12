/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:47:52 by gfaviere          #+#    #+#             */
/*   Updated: 2021/02/16 10:17:22 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int			draw_string(t_window *window, t_pos *s_pos, char *str, int color)
{
	return (mlx_string_put(window->ptr, window->win, s_pos->x, s_pos->y,
		color, str));
}
