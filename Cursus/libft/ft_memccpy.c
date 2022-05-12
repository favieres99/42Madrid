/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:23:36 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/19 18:49:27 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void d, const void s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)d;
	str2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str1[i] == (unsigned char)c)
			return ((void*)(d + 1 + i));
		i++;
	}
	return (NULL);
}
