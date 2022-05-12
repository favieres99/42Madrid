/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:33:18 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 23:00:40 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_printint02(t_struct *general)
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
			while (general->min > 1)
				ft_putzeromin(general);
			ft_putstr(general, "0");
		}
	}
}

static void			ft_printint01(t_struct *general)
{
	int		i;

	i = general->max;
	if (general->flag == 2)
	{
		if (general->neg == 1)
		{
			while (general->max > 0)
				ft_putzeromax(general);
			while (general->min > i)
				ft_putspacemin(general);
		}
		else
		{
			ft_putstr(general, "0");
			while (general->min > 1)
				ft_putspacemin(general);
		}
	}
	else
		ft_printint02(general);
}

void				ft_printint0(t_struct *general)
{
	if (general->flag == 0)
		ft_putstr(general, "0");
	else if (general->flag == 1)
	{
		if (general->aux == 5)
			ft_putstr(general, "0");
		else
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
				while (general->min > 1)
					ft_putspacemin(general);
				ft_putstr(general, "0");
			}
		}
	}
	else
		ft_printint01(general);
}
