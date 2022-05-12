/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:15:58 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/22 00:35:16 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_reset(t_struct *general)
{
	general->max = 0;
	general->min = 0;
	general->neg = 0;
	general->tipoimpr = 0;
	general->flag = 0;
	general->aux = 0;
}

static void		ft_advance(t_struct *general)
{
	general->total = 0;
	while ((*general->str) != '\0')
	{
		ft_reset(general);
		if ((*general->str) == '%')
		{
			general->str++;
			general->tipoimpr = ft_searchimpr(general);
			general->flag = ft_flag(general, 0);
			ft_imprimirtodo(general);
		}
		else
		{
			ft_putchar(*general->str);
			general->total++;
		}
		general->str++;
	}
}

int				ft_printf(const char *s, ...)
{
	t_struct	general;

	general.str = (char *)s;
	va_start(general.ap, s);
	ft_advance(&general);
	va_end(general.ap);
	return (general.total);
}
