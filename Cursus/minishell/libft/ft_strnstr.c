/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:29:48 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 14:26:15 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hayc;
	size_t	needc;

	if (!*needle)
		return ((char *)haystack);
	hayc = 0;
	while (*(haystack + hayc) != 0 && hayc < len)
	{
		needc = 0;
		while (*(haystack + hayc + needc) == *(needle + needc)
			&& hayc + needc < len && *(needle + needc) != 0)
		{
			if (*(needle + needc + 1) == 0)
				return ((char *)(haystack + hayc));
			else
				needc++;
		}
		hayc++;
	}
	return (0);
}
