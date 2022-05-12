/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:31:27 by gfaviere          #+#    #+#             */
/*   Updated: 2021/02/16 10:13:56 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			ft_endwith(char const *str, char const *end)
{
	int	length;
	int	end_length;

	length = ft_strlen(str);
	end_length = ft_strlen(end);
	if (end_length > length)
		return (0);
	return (!ft_strcmp(str + length - end_length, end));
}
