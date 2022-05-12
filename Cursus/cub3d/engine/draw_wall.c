/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:21:18 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/01 11:02:55 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static void		init_draw_wall(t_tex *tex, t_raysult *ray, t_pos *p_tex)
{
	if (ray->side)
		ray->wall_x = ray->ray_pos.x
			+ ((ray->map_pos.y - ray->ray_pos.y
				+ (1. - ray->step.y) / 2.) / ray->ray_dir.y)
			* ray->ray_dir.x;
	else
		ray->wall_x = ray->ray_pos.y
			+ ((ray->map_pos.x - ray->ray_pos.x
				+ (1. - ray->step.x) / 2.) / ray->ray_dir.x)
			* ray->ray_dir.y;
	ray->wall_x -= floor(ray->wall_x);
	p_tex->x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->ray_dir.x > 0.)
		p_tex->x = tex->width - p_tex->x - 1.;
	else if (ray->side == 1 && ray->ray_dir.y < 0.)
		p_tex->x = tex->width - p_tex->x - 1.;
}

void			draw_wall(t_game *g, t_raysult *r)
{
	int		i[2];
	t_pos	p_tex;
	t_tex	*tex;
	t_pos	pixel;

	tex = &g->tex[r->direction];
	set_pos(&pixel, r->column, MAX(0, g->window.half.y - (r->height / 2.)));
	if (!tex->tex)
	{
		draw_vertical_line(&g->window, &pixel, r->height,
			distance_shade(g->options,
			g->config.c[r->direction], r->distance));
		return ;
	}
	init_draw_wall(tex, r, &p_tex);
	i[1] = MAX(0, g->window.half.y - (r->height / 2.));
	i[0] = 0;
	while (i[0] < r->height && (pixel.y = i[1]++) < g->window.size.y)
	{
		p_tex.y = (int)((pixel.y * 2 - g->window.size.y + r->height)
				* ((tex->height / 2.) / r->height));
		draw_pixel(&g->window, &pixel, distance_shade(g->options,
			get_tex_color(tex, &p_tex), r->distance));
		i[0]++;
	}
}
