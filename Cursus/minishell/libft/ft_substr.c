/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 07:54:34 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:49:46 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	cnt;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	slen = ft_strlen(s + start);
	if (slen < len)
		len = slen;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	cnt = 0;
	while (cnt < len)
	{
		str[cnt] = s[start + cnt];
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}
