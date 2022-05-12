/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:57:21 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 12:32:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	len_env(t_struct *xpt)
{
	int	i;

	i = 0;
	while (xpt->env.env[i])
		i++;
	xpt->env.len = i;
}

static void	init_struct_env(t_struct *xpt)
{
	xpt->env.key = malloc(sizeof(char *) * (xpt->env.len + 1));
	if (!xpt->env.key)
		exit(EXIT_FAILURE);
	xpt->env.content = malloc(sizeof(char *) * (xpt->env.len + 1));
	if (!xpt->env.content)
		exit(EXIT_FAILURE);
}

void	create_env(t_struct *xpt, char **my_env)
{
	int		i;
	char	**env_aux;

	xpt->env.env = my_env;
	len_env(xpt);
	init_struct_env(xpt);
	i = 0;
	while (xpt->env.env[i])
	{
		env_aux = ft_split(xpt->env.env[i], '=');
		xpt->env.key[i] = ft_strdup(env_aux[0]);
		if (env_aux[1])
			xpt->env.content[i] = ft_strdup(env_aux[1]);
		else
			xpt->env.content[i] = ft_strdup("");
		free_char_array(env_aux);
		env_aux = NULL;
		i++;
	}
	xpt->env.key[i] = NULL;
	xpt->env.content[i] = NULL;
}

void	ft_env(t_struct *xpt)
{
	int	i;

	i = 0;
	while (i < xpt->env.len)
	{
		ft_putstr_fd(xpt->env.key[i], xpt->out_fd);
		ft_putchar_fd('=', xpt->out_fd);
		ft_putendl_fd(xpt->env.content[i], xpt->out_fd);
		i++;
	}
	xpt->ret_number = 0;
}
