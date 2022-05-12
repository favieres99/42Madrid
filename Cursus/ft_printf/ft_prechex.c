/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prechex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:17:55 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/22 00:36:38 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_apoyo(t_struct *general, char *x, int i)
{
	if (i == 2)
	{
		if (*x == '0' && general->max == 0 && general->min != 0)
		{
			ft_putchar(' ');
			general->total++;
		}
		else if (*x == '0' && general->min == 0 && general->max == 0)
			x++;
		else
			ft_putstr(general, x);
	}
	else if (i == 1)
		general->min++;
	else if (i == 0)
		ft_putstr(general, x);
	else if (i == 3)
		general->max = 2;
}

static void		ft_precisionhex3(t_struct *general, char *x, size_t i)
{
	if (general->flag == 6)
	{
		if (general->max >= general->min)
		{
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
			ft_apoyo(general, x, (general->neg == 1) ? 1 : 0);
		}
		else if (general->min > general->max)
		{
			if (general->neg == 3)
				ft_apoyo(general, x, 3);
			else
				ft_apoyo(general, x, general->neg == 3 && general->neg != 1 ?
						3 : 0);
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
	}
}

static void		ft_precisionhex2(t_struct *general, char *x, size_t i)
{
	if (general->flag == 5)
	{
		if (general->max >= general->min)
		{
			while ((size_t)general->max >= ft_strlen(x) + 1)
				ft_putzeromax(general);
			ft_apoyo(general, x, (general->neg == 1) ? 1 : 0);
		}
		else if (general->min > general->max)
		{
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
			ft_apoyo(general, x, (general->neg == 1) ? 1 : 0);
			while ((size_t)general->min > i)
				ft_putspacemin(general);
		}
	}
	else
		ft_precisionhex3(general, x, i);
}

void			ft_precisionhex(t_struct *general, char *x)
{
	size_t		i;

	i = (size_t)general->max > ft_strlen(x) ? general->max : ft_strlen(x);
	if (general->flag == 4)
	{
		if (general->max >= general->min)
		{
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
		if (general->min > general->max)
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
		ft_apoyo(general, x, 2);
	}
	else
		ft_precisionhex2(general, x, i);
}
