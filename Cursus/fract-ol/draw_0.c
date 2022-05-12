/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 01:10:23 by marvin            #+#    #+#             */
/*   Updated: 2021/06/15 09:54:38 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_0(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 0;
	while (y != 180)
	{
		x = 0;
		while (x != e->winx)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}

void	*draw_1(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 180;
	while (y != 360)
	{
		x = 0;
		while (x != e->winx)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}

void	*draw_2(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 360;
	while (y != 540)
	{
		x = 0;
		while (x != e->winx)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}

void	*draw_3(void *e_void)
{
	int		x;
	int		y;
	t_env	*e;

	e = (t_env *)e_void;
	y = 540;
	while (y != 720)
	{
		x = 0;
		while (x != e->winx)
		{
			compute(x, y, e);
			++x;
		}
		++y;
	}
	return (e_void);
}
