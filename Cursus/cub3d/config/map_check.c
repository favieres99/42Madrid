/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:32:27 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/15 10:39:44 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int				count_columns(t_str *map_buffer)
{
	int		big;
	int		new;

	if (!map_buffer)
		return (0);
	big = 0;
	while (map_buffer)
	{
		new = 0;
		while (map_buffer->content[new])
			new++;
		if (new > big)
			big = new;
		map_buffer = map_buffer->next;
	}
	return (big);
}

int				count_rows(t_str *map_buffer)
{
	int		i;

	if (!map_buffer)
		return (0);
	i = 0;
	while (map_buffer)
	{
		map_buffer = map_buffer->next;
		i++;
	}
	return (i);
}

char			*ft_strdup_special(char const *s1, t_config *config)
{
	char	*str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	str = (char*)malloc(sizeof(*str) * (config->columns + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < config->columns)
	{
		if (ft_in_set(s1[i], VALID_MAP_CHARACTERS))
			str[i] = s1[i];
		else
			str[i] = 'x';
		i++;
	}
	str[i] = 0;
	return (str);
}

int				check_rgb(t_config *config)
{
	if ((config->c[TEX_SKY] == 0xC69C4B || config->c[TEX_FLOOR] == 0x75CD91)
		&& (config->tex_path[TEX_SKY] == NULL ||
		config->tex_path[TEX_FLOOR] == NULL))
		return (0);
	return (1);
}

t_str			*ft_split_special(char const *org, char sep)
{
	int		i;
	int		start;
	t_str	*str;
	int		x;

	x = 0;
	start = 0;
	i = 0;
	str = NULL;
	while (org[i])
	{
		if (org[i] == sep)
		{
			if ((i - start > 0 &&
			!str_add_back(&str, ft_substr(org, start, i - start))) || x++ > 1)
				return (PTR_CAST(str_clear(&str)));
			start = ++i;
		}
		else
			i++;
	}
	if (i - start > 0
		&& !str_add_back(&str, ft_substr(org, start, i - start)))
		return (PTR_CAST(str_clear(&str)));
	return (str);
}
