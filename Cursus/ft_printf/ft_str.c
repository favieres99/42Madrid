/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:29:22 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 23:27:01 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printstr3(t_struct *general, char *x, unsigned int i,
								unsigned int h)
{
	if (general->aux == 5)
	{
		while ((size_t)general->min > ft_strlen(x))
			ft_putspacemin(general);
		ft_putstr(general, x);
	}
	else
	{
		if (general->neg == 1)
		{
			while ((size_t)general->min > h)
				ft_putspacemin(general);
			ft_putnstr(general, x, h);
		}
		else
		{
			while ((size_t)general->min > i)
				ft_putspacemin(general);
			ft_putnstr(general, x, i);
		}
	}
}

static void		ft_printstr2(t_struct *general, char *x, unsigned int i,
								unsigned int h)
{
	if (general->flag == 2)
	{
		if (general->neg == 1)
		{
			ft_putnstr(general, x, h);
			while ((size_t)general->min > h)
				ft_putspacemin(general);
		}
		else
		{
			ft_putnstr(general, x, i);
			while ((size_t)general->min > i)
				ft_putspacemin(general);
		}
	}
}

void			ft_printstr(t_struct *general, char *x)
{
	unsigned int	i;
	unsigned int	h;

	h = ((size_t)general->max < ft_strlen(x)) ? general->max : ft_strlen(x);
	i = ((size_t)general->max > ft_strlen(x)) ? general->max : ft_strlen(x);
	if (general->flag == 0)
		ft_putstr(general, x);
	else if (general->flag == 1)
		ft_printstr3(general, x, i, h);
	else
		ft_printstr2(general, x, i, h);
}
