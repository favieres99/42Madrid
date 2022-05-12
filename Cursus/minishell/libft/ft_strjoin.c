/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:09:22 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:51:17 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	strlen;
	size_t	cnt;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	cnt = 0;
	str = (char *)malloc((strlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*(s1 + cnt) != 0)
	{
		*(str + cnt) = *(s1 + cnt);
		cnt++;
	}
	strlen = cnt;
	cnt = 0;
	while (*(s2 + cnt) != 0)
	{
		*(str + strlen + cnt) = *(s2 + cnt);
		cnt++;
	}
	*(str + strlen + cnt) = 0;
	return (str);
}
