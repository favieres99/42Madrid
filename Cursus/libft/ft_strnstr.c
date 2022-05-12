/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:23:56 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/18 10:55:34 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	len2;

	if (*find == '\0')
		return ((char *)str);
	len2 = ft_strlen(find);
	while (*str != '\0' && len-- >= len2)
	{
		if (*str == *find && ft_strncmp(str, find, len2) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
