/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:04:10 by jballest          #+#    #+#             */
/*   Updated: 2019/11/19 18:38:10 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	asc;

	str = (unsigned char *)s;
	asc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*str++ == asc)
		{
			s = str--;
			return (str);
		}
	}
	return (0);
}
