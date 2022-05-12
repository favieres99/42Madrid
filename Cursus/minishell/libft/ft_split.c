/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:22:28 by jballest          #+#    #+#             */
/*   Updated: 2021/04/01 16:01:23 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_words(const char *s, char **str, char c, int wordn)
{
	int		l;
	int		i;
	int		w;

	i = 0;
	l = 0;
	w = -1;
	while (wordn > ++w)
	{
		l = 0;
		while (s[i] == c && s[i] != 0)
			i++;
		while (s[i] != c && s[i] != 0)
		{
			l++;
			i++;
		}
		str[w] = (char *)malloc((l + 1) * sizeof(char *));
		if (!str[w])
			return ;
		ft_strlcpy(str[w], &s[i - l], l + 1);
	}
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		wordn;

	if (!s)
		return (NULL);
	wordn = ft_wordcnt(s, c);
	str = (char **)malloc((wordn + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	fill_words(s, str, c, wordn);
	str[wordn] = 0;
	return (str);
}
