/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:25:02 by jballest          #+#    #+#             */
/*   Updated: 2019/11/10 13:46:49 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*m0;
	unsigned char	*m1;

	m0 = (unsigned char *)dst;
	m1 = (unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (m1 < m0)
		while (++i <= len)
			m0[len - i] = m1[len - i];
	else
		while (len-- > 0)
			*m0++ = *m1++;
	return (dst);
}
