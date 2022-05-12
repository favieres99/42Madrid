/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 01:20:16 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/20 22:06:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printint3(t_struct *general, char *x, size_t i)
{
	if (general->flag == 3)
	{
		if (general->max > general->min)
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
		else if (general->min >= general->max)
		{
			if (general->neg == 1)
			{
				while ((size_t)general->min > i)
					ft_putspacemin(general);
			}
			while ((size_t)general->min > ft_strlen(x))
				ft_putzeromin(general);
		}
		ft_putstr(general, x);
	}
}

static void		ft_printint2(t_struct *general, char *x, size_t i)
{
	if (general->flag == 2)
	{
		while ((size_t)general->max > ft_strlen(x))
			ft_putzeromax(general);
		ft_putstr(general, x);
		while ((size_t)general->min > i)
			ft_putspacemin(general);
	}
	else
		ft_printint3(general, x, i);
}

void			ft_printint(t_struct *general, char *x)
{
	size_t	i;

	i = ((size_t)general->max > ft_strlen(x)) ? general->max : ft_strlen(x);
	if (general->flag == 0)
		ft_putstr(general, x);
	else if (general->flag == 1)
	{
		while ((size_t)general->min > i)
			ft_putspacemin(general);
		while ((size_t)general->max > ft_strlen(x))
			ft_putzeromax(general);
		ft_putstr(general, x);
	}
	else
		ft_printint2(general, x, i);
}
