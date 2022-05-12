/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:37:52 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 20:06:32 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_printhex2(t_struct *general, char *x, size_t i)
{
	if (general->flag == 3)
	{
		if (general->neg == 1)
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
		else
		{
			while ((size_t)general->min > i)
				ft_putzeromin(general);
		}
		ft_putstr(general, x);
	}
}

static void			ft_printhex1(t_struct *general, char *x, size_t i)
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
		ft_printhex2(general, x, i);
}

void				ft_printhex(t_struct *general, char *x)
{
	size_t	i;

	i = ((size_t)general->max > ft_strlen(x)) ? general->max : ft_strlen(x);
	if (general->flag == 0)
		ft_putstr(general, x);
	else if (general->flag == 1)
	{
		if (general->neg == 1)
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			while ((size_t)general->max > ft_strlen(x))
				ft_putzeromax(general);
		}
		else
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
		}
		ft_putstr(general, x);
	}
	else
		ft_printhex1(general, x, i);
}
