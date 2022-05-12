/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intneg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 21:22:25 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/22 00:25:15 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printintneg4(t_struct *general, char *x, size_t i)
{
	if (general->neg == 1)
	{
		while ((size_t)general->min > i)
			ft_putspacemin(general);
		ft_putnegativo(general);
		while ((size_t)general->max > ft_strlen(x))
			ft_putzeromax(general);
	}
	else
	{
		while ((size_t)general->min > ft_strlen(x))
			ft_putspacemin(general);
		ft_putnegativo(general);
	}
	ft_putstr(general, x);
}

static void		ft_printintneg3(t_struct *general, char *x, size_t i)
{
	if (general->flag == 3)
	{
		if (general->neg == 1)
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			ft_putnegativo(general);
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
		else
		{
			ft_putnegativo(general);
			while ((size_t)general->min > i)
				ft_putzeromin(general);
		}
		ft_putstr(general, x);
	}
}

static void		ft_printintneg2(t_struct *general, char *x, size_t i)
{
	if (general->flag == 2)
	{
		ft_putnegativo(general);
		while ((size_t)general->max > ft_strlen(x))
			ft_putzeromax(general);
		ft_putstr(general, x);
		while ((size_t)general->min > i)
			ft_putspacemin(general);
	}
	else
		ft_printintneg3(general, x, i);
}

void			ft_printintneg(t_struct *general, char *x)
{
	size_t	i;

	if (general->min > 0)
		general->min--;
	i = ((size_t)general->max > ft_strlen(x)) ? general->max : ft_strlen(x);
	if (general->flag == 0)
	{
		ft_putnegativo(general);
		ft_putstr(general, x);
	}
	else if (general->flag == 1)
		ft_printintneg4(general, x, i);
	else
		ft_printintneg2(general, x, i);
}
