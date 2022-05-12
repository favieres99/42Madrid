/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:35:46 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/09 19:04:58 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}
