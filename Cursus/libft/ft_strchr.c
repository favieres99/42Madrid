/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:36:35 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/09 19:05:25 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	while (*s)
	{
		if (*s == c)
		{
			tmp = (char *)s;
			return (tmp);
		}
		s++;
	}
	if (c == '\0')
	{
		tmp = (char *)s;
		return (tmp);
	}
	return (NULL);
}
