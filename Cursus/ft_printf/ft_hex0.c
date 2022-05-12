/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:08:17 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 22:37:02 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printhex02(t_struct *general)
{
	if (general->flag == 3)
	{
		if (general->neg == 1)
		{
			while (general->min > general->max)
				ft_putspacemin(general);
			while (general->max > 0)
				ft_putzeromax(general);
		}
		else
		{
			while (general->min > 0)
				ft_putzeromin(general);
		}
	}
}

static void		ft_printhex01(t_struct *general, int i)
{
	if (general->flag == 2)
	{
		if (general->neg != 1)
		{
			ft_putstr(general, "0");
			while (general->min > 1)
				ft_putspacemin(general);
		}
		else
		{
			i = general->max;
			while (general->max > 0)
				ft_putzeromax(general);
			while (general->min > i)
				ft_putspacemin(general);
		}
	}
	else
		ft_printhex02(general);
}

void			ft_printhex0(t_struct *general)
{
	int		i;

	i = (general->max > 0) ? general->max : 1;
	if (general->flag == 0)
		ft_putstr(general, "0");
	else if (general->flag == 1)
	{
		if (general->neg != 1)
		{
			while (general->min > 1)
				ft_putspacemin(general);
			ft_putstr(general, "0");
		}
		else
		{
			while (general->min > general->max)
				ft_putspacemin(general);
			while (general->max > 0)
				ft_putzeromax(general);
		}
	}
	else
		ft_printhex01(general, i);
}
