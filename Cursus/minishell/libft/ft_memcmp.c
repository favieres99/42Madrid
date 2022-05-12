/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:55:30 by jballest          #+#    #+#             */
/*   Updated: 2019/11/06 20:19:55 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m0;
	unsigned char	*m1;

	m0 = (unsigned char *)s1;
	m1 = (unsigned char *)s2;
	while (n)
	{
		if (*m0 != *m1)
			return (*m0 - *m1);
		m0++;
		m1++;
		n--;
	}
	return (0);
}
