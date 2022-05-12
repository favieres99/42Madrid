/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:44:07 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/02 03:34:07 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_size(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(unsigned int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	index;
	unsigned int	size;

	nb = (unsigned int)nbr;
	size = (unsigned int)get_nb_size(nb);
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
