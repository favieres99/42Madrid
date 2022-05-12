/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pututils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:58:02 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 22:44:47 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_checkhex(t_struct *general, char *str)
{
	size_t	i;

	i = 0;
	if (general->tipoimpr == 'x' || general->tipoimpr == 'p')
	{
		while (i < ft_strlen(str))
		{
			if (str[i] > 64 && str[i] < 71)
				str[i] += 32;
			i++;
		}
	}
	else if (general->tipoimpr == 'X')
	{
		while (i < ft_strlen(str))
		{
			if (str[i] > 96 && str[i] < 103)
				str[i] -= 32;
			i++;
		}
	}
}

void		ft_putnstr(t_struct *general, char *str, size_t x)
{
	size_t		i;

	i = 0;
	ft_checkhex(general, str);
	while (str[i] != '\0' && i < x)
	{
		write(1, &str[i], 1);
		i++;
		general->total++;
	}
}

void		ft_putstr(t_struct *general, char *str)
{
	ft_checkhex(general, str);
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		general->total++;
	}
}

void		ft_putnegativo(t_struct *general)
{
	if (general->aux == 1)
	{
		ft_putchar('-');
		general->total++;
	}
}
