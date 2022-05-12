/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:48:46 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:27:09 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mptr;

	mptr = malloc(count * size);
	if (mptr == NULL)
		return (mptr);
	ft_bzero(mptr, size * count);
	return (mptr);
}
