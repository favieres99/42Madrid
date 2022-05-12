/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:56:23 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:35:21 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*num;
	unsigned int	onum;
	int				is_negative;
	int				nsize;

	is_negative = ft_isnegative(n);
	nsize = ft_ndigits(n) + is_negative;
	num = (char *)malloc((nsize + 1) * sizeof(char));
	if (!num)
		return (0);
	if (is_negative)
		onum = -n;
	else
		onum = n;
	num[nsize] = 0;
	if (is_negative)
		num[0] = '-';
	while (--nsize >= is_negative)
	{
		num[nsize] = onum % 10 + 48;
		onum /= 10;
	}
	return (num);
}
