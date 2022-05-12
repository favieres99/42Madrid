/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:56:01 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/09 19:06:55 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ternary(int n)
{
	if (n >= 0)
		return (1);
	return (-1);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		sign;
	char	nbr1[11];
	char	*nbr2;

	i = 0;
	j = 0;
	sign = ternary(n);
	while (sign * n > 9 || sign * n < 0)
	{
		nbr1[i++] = '0' + sign * (n % 10);
		n = n / 10;
	}
	nbr1[i++] = '0' + sign * n;
	if (sign < 0)
		nbr1[i++] = '-';
	nbr2 = (char *)malloc(sizeof(char) * i + 1);
	if (nbr2 == NULL)
		return (NULL);
	nbr2[i] = '\0';
	while (i--)
		nbr2[i] = nbr1[j++];
	return (nbr2);
}
