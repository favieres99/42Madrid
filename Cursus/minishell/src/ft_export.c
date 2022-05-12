/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:58:59 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 12:32:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	add_env(t_struct *xpt, char *new_key, char *new_content)
{
	int	i;

	xpt->env.len++;
	alloc_env_aux(xpt);
	i = 0;
	while (i < xpt->env.len - 1)
	{
		xpt->env_aux.key[i] = ft_strdup(xpt->env.key[i]);
		xpt->env_aux.content[i] = ft_strdup(xpt->env.content[i]);
		i++;
	}
	xpt->env_aux.key[i] = ft_strdup(new_key);
	xpt->env_aux.content[i] = ft_strdup(new_content);
	i++;
	xpt->env_aux.key[i] = NULL;
	xpt->env_aux.content[i] = NULL;
	free_char_array(xpt->env.key);
	free_char_array(xpt->env.content);
	xpt->env.key = xpt->env_aux.key;
	xpt->env.content = xpt->env_aux.content;
}

static void	verify_if_env_exists(t_struct *xpt, char **env_aux, int i)
{
	if (find_env(xpt, env_aux[0]))
	{
		free(xpt->env.content[xpt->env.index]);
		xpt->env.content[xpt->env.index] = ft_strdup(env_aux[1]);
	}
	else
		add_env(xpt, env_aux[0], env_aux[1]);
	if (!ft_strncmp(xpt->tokens[i], "PATH", 4))
	{
		if (xpt->path)
			free_char_array(xpt->path);
		init_path(xpt);
	}
}

void	ft_export(t_struct *xpt)
{
	int		i;
	char	**env_aux;

	i = 1;
	while (xpt->tokens[i])
	{
		env_aux = ft_split(xpt->tokens[i], '=');
		if (env_aux[1])
			verify_if_env_exists(xpt, env_aux, i);
		else if (xpt->tokens[i][ft_strlen(xpt->tokens[1]) - 1] == '=')
		{
			env_aux[1] = ft_strdup("");
			verify_if_env_exists(xpt, env_aux, i);
		}
		free(env_aux[0]);
		free(env_aux[1]);
		free(env_aux);
		env_aux = NULL;
		i++;
	}
	xpt->ret_number = 0;
}
