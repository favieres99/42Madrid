/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:00:34 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 12:32:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	rm_env(t_struct *xpt)
{
	int	i;
	int	j;

	xpt->env.len--;
	alloc_env_aux(xpt);
	i = 0;
	j = 0;
	while (i < xpt->env.len + 1)
	{
		if (i != xpt->env.index)
		{
			xpt->env_aux.key[j] = ft_strdup(xpt->env.key[i]);
			xpt->env_aux.content[j] = ft_strdup(xpt->env.content[i]);
			j++;
		}
		i++;
	}
	xpt->env_aux.key[j] = NULL;
	xpt->env_aux.content[j] = NULL;
	free_char_array(xpt->env.key);
	free_char_array(xpt->env.content);
	xpt->env.key = xpt->env_aux.key;
	xpt->env.content = xpt->env_aux.content;
}

void	alloc_env_aux(t_struct *xpt)
{
	xpt->env_aux.key = malloc(sizeof(char *) * (xpt->env.len + 1));
	if (!xpt->env_aux.key)
		exit(EXIT_FAILURE);
	xpt->env_aux.content = malloc(sizeof(char *) * (xpt->env.len + 1));
	if (!xpt->env_aux.content)
		exit(EXIT_FAILURE);
}

void	ft_unset(t_struct *xpt)
{
	int	i;

	i = 1;
	while (xpt->tokens[i])
	{
		if (find_env(xpt, xpt->tokens[i]))
		{
			rm_env(xpt);
			if (!ft_strncmp(xpt->tokens[i], "PATH", 4))
			{
				free_char_array(xpt->path);
				xpt->path = NULL;
			}
		}
		i++;
	}
	xpt->ret_number = 0;
}
