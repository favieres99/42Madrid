/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:50:44 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:50:41 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int char_n, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)str;
	while (len-- > 0)
		*a++ = (unsigned char)char_n;
	return (str);
}
