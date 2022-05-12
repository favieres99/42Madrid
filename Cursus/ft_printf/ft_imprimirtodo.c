/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imprimirtodo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:42:55 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/22 00:08:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_imprimirtodo3(t_struct *general)
{
	char			*str;
	unsigned long	x;

	if (general->tipoimpr == 'p')
	{
		x = va_arg(general->ap, unsigned long);
		if (x == 0)
			general->aux = 1;
		ft_printpointer(general, ft_calchexlong(x));
	}
	else if (general->tipoimpr == '%')
		ft_printporcentaje(general);
	else if (general->tipoimpr == 's')
	{
		str = va_arg(general->ap, char*);
		if (str == NULL)
			str = "(null)";
		ft_printstr(general, str);
	}
}

static void		ft_imprimirtodo2(t_struct *general)
{
	unsigned int	u;

	if (general->tipoimpr == 'u')
	{
		u = va_arg(general->ap, unsigned int);
		if (u == 0)
			ft_printint0(general);
		else
			ft_printint(general, ft_itoa(u));
	}
	else if (general->tipoimpr == 'x' || general->tipoimpr == 'X')
	{
		u = va_arg(general->ap, unsigned int);
		if (u == 0)
			ft_printhex0(general);
		else
			ft_printhex(general, ft_calchex(u));
	}
	else
		ft_imprimirtodo3(general);
}

void			ft_imprimirtodo(t_struct *general)
{
	int		x;

	if (general->tipoimpr == 'c')
	{
		x = va_arg(general->ap, int);
		ft_printchar(general, x);
	}
	else if (general->tipoimpr == 'd' || general->tipoimpr == 'i')
	{
		x = va_arg(general->ap, int);
		if (x < 0)
		{
			x *= -1;
			general->aux = 1;
			ft_printintneg(general, ft_itoa(x));
		}
		else if (x == 0)
			ft_printint0(general);
		else
			ft_printint(general, ft_itoa(x));
	}
	else
		ft_imprimirtodo2(general);
}
