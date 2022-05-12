/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:43:29 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 03:34:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*(s1 + i) == *(s2 + i) && i < n
		&& (*(s1 + i) != 0 || *(s2 + i)) != 0)
		i++;
	if (i != n)
		return ((*(s1 + i) - *(s2 + i)));
	return (0);
}
