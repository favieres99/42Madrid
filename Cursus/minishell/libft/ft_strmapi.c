/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:50:59 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:55:46 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	slen;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	str = (char *)malloc((slen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[slen] = 0;
	while (slen-- > 0)
		str[slen] = f(slen, s[slen]);
	return (str);
}
