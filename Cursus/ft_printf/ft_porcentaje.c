/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_porcentaje.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 02:46:33 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/19 05:59:54 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printporcentaje(t_struct *general)
{
	if (general->flag == 0)
		ft_putchar('%');
	else if (general->flag == 1 || general->flag == 4)
	{
		while (general->min > 1)
			ft_putspacemin(general);
		ft_putchar('%');
	}
	else if (general->flag == 2 || general->flag == 5)
	{
		ft_putchar('%');
		while (general->min > 1)
			ft_putspacemin(general);
	}
	else if (general->flag == 3 || general->flag == 6)
	{
		while (general->min > 1)
			ft_putzeromin(general);
		ft_putchar('%');
	}
	general->total++;
}
