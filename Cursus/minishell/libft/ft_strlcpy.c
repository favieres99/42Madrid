/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:39:15 by jballest          #+#    #+#             */
/*   Updated: 2019/11/10 17:06:47 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst)
		return (dstsize);
	if (dstsize > 0)
	{
		while (--dstsize && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
		return (ft_strlen((char *)src));
	}
	return (ft_strlen((char *)src));
}
