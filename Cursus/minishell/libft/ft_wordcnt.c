/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:31:42 by jballest          #+#    #+#             */
/*   Updated: 2019/11/14 18:24:34 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcnt(const char *s, char del)
{
	int	pos;
	int	wcnt;

	pos = 0;
	wcnt = 0;
	while (s[pos] != 0)
	{
		if (s[pos] == del)
			pos++;
		else
		{
			wcnt++;
			while (s[pos] != del && s[pos] != 0)
				pos++;
		}
	}
	return (wcnt);
}
