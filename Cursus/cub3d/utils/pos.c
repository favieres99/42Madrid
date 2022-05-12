/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:50:02 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/02 11:15:41 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void		copy_pos(t_pos *pos, t_pos *org)
{
	pos->x = org->x;
	pos->y = org->y;
}
