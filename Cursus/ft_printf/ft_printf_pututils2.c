/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pututils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 02:15:50 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/19 02:16:37 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putspacemin(t_struct *general)
{
	ft_putchar(' ');
	general->min--;
	general->total++;
}

void		ft_putzeromin(t_struct *general)
{
	ft_putchar('0');
	general->min--;
	general->total++;
}

void		ft_putzeromax(t_struct *general)
{
	ft_putchar('0');
	general->max--;
	general->total++;
}
