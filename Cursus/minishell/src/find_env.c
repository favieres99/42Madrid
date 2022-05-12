/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:38:03 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 18:38:29 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*find_env(t_struct *xpt, char *needle)
{
	int	i;
	int	len;
	int	len_needle;

	i = 0;
	xpt->env.index = 0;
	len_needle = ft_strlen(needle);
	while (xpt->env.key[i] && i < xpt->env.len)
	{
		len = ft_strlen(xpt->env.key[i]);
		if (!ft_strncmp(xpt->env.key[i], needle, len_needle)
			&& len == len_needle)
		{
			xpt->env.index = i;
			return (xpt->env.content[i]);
		}
		i++;
	}
	return (0);
}
