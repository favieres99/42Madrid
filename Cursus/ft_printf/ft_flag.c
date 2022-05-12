/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:03:30 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 23:26:18 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_negativos(t_struct *general, char x)
{
	if (general->min < 0)
	{
		general->min *= -1;
		return (2);
	}
	else if (general->max < 0)
	{
		if (general->tipoimpr == 's')
			general->max *= -1;
		else
			general->max = 0;
		general->aux = 5;
		return (x);
	}
	else
		return (x);
}

static char		ft_ajuste(t_struct *general, char x, char y)
{
	if (x == 0)
		general->str--;
	return (y);
}

static char		ft_precision(t_struct *general)
{
	if ((*general->str) == '*')
	{
		general->min = va_arg(general->ap, unsigned int);
		general->str++;
	}
	else
		general->min = ft_atoispecial(general);
	if ((*general->str++) == '.')
	{
		general->neg = 1;
		if ((*general->str) == '*')
		{
			general->max = va_arg(general->ap, unsigned int);
			general->str++;
		}
		else
			general->max = ft_atoispecial(general);
		return (1);
	}
	return (0);
}

char			ft_flag(t_struct *general, char y)
{
	char	x;

	if ((*general->str) == '0')
	{
		general->str++;
		x = ft_precision(general);
		y = ft_negativos(general, 3);
		return (ft_ajuste(general, x, y));
	}
	else if ((*general->str) == '-')
	{
		general->str++;
		x = ft_precision(general);
		y = ft_negativos(general, 2);
		return (ft_ajuste(general, x, y));
	}
	else if (ft_isdigit(*general->str) || (*general->str) == '*' ||
				(*general->str) == '.')
	{
		x = ft_precision(general);
		y = ft_negativos(general, 1);
		return (ft_ajuste(general, x, y));
	}
	else
		return (0);
}
