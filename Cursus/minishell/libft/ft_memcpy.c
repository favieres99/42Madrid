/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:01:47 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 03:35:22 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*m0;
	char	*m1;

	if (n == 0 || dst == src)
		return (dst);
	m0 = (char *)dst;
	m1 = (char *)src;
	while (n--)
		*m0++ = *m1++;
	return (dst);
}
