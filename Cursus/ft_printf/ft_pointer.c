/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 02:36:34 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/22 00:17:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_null(t_struct *general, char *x)
{
	if (general->aux != 1)
		ft_putstr(general, x);
	else
		ft_putstr(general, "0");
}

void			ft_printpointer2(t_struct *general, char *x)
{
	if (general->flag == 2)
	{
		ft_putstr(general, "0x");
		ft_null(general, x);
		while ((size_t)general->min > ft_strlen(x) + 2)
			ft_putspacemin(general);
	}
}

void			ft_printpointer(t_struct *general, char *x)
{
	if (general->flag == 0)
	{
		ft_putstr(general, "0x");
		ft_null(general, x);
	}
	else if (general->flag == 1)
	{
		if (general->neg == 1)
		{
			while ((size_t)general->min > 2)
				ft_putspacemin(general);
			ft_putstr(general, "0x");
		}
		else
		{
			while ((size_t)general->min > ft_strlen(x) + 2)
				ft_putspacemin(general);
			ft_putstr(general, "0x");
			ft_null(general, x);
		}
	}
	else
		ft_printpointer2(general, x);
}
