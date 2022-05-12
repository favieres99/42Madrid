/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:48:40 by gfaviere          #+#    #+#             */
/*   Updated: 2019/11/11 14:17:32 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	x;
	int				i;

	i = 0;
	x = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (ptr[i] == x)
			return (ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
