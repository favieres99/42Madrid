/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:21:00 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/20 09:44:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		ft_searchimpr(t_struct *general)
{
	char	*type;
	char	*find;
	int		i;
	char	x;

	type = general->str;
	find = "cspdiuxX%\0";
	while (*type != '\0')
	{
		i = 0;
		while (find[i] != '\0')
		{
			if (find[i] == *type)
				return (x = find[i]);
			i++;
		}
		type++;
	}
	return (0);
}

int			ft_atoispecial(t_struct *general)
{
	int		res;

	res = 0;
	while ((*general->str) && (*general->str) >= '0' && (*general->str) <= '9')
	{
		res = res * 10 + ((*general->str) - 48);
		general->str++;
	}
	return (res);
}
