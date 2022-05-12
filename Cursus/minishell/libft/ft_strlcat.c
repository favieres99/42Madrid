/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:46:44 by jballest          #+#    #+#             */
/*   Updated: 2019/11/07 18:27:44 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen((char *)dst);
	if (dstsize <= dstlen)
		return (ft_strlen((char *)src) + dstsize);
	while (i < dstsize - dstlen - 1 && *(src + i) != 0)
	{
		*(dst + dstlen + i) = *(src + i);
		i++;
	}
	*(dst + dstlen + i) = 0;
	return (ft_strlen((char *)src) + dstlen);
}
