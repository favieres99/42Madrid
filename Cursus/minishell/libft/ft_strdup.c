/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:11:41 by jballest          #+#    #+#             */
/*   Updated: 2019/11/10 14:24:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ms1;

	ms1 = (char *)malloc(ft_strlen((char *)s1) * sizeof(char) + 1);
	if (ms1 == NULL)
		return (ms1);
	ft_strcpy(ms1, (char *)s1);
	return (ms1);
}
