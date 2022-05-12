/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:47:59 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/19 05:59:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printchar(t_struct *general, int x)
{
	if (general->flag == 0)
		ft_putchar(x);
	else if (general->flag == 1)
	{
		while (general->min > 1)
			ft_putspacemin(general);
		ft_putchar(x);
	}
	else if (general->flag == 2)
	{
		ft_putchar(x);
		while (general->min > 1)
			ft_putspacemin(general);
	}
	general->total += 1;
}
