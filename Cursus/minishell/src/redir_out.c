/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:35:06 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 19:25:36 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle)
			return (i);
		i++;
	}
	return (i);
}

static void	simple_redir_out(t_struct *xpt, int j, int flags)
{
	char	*aux;
	char	*file;

	aux = ft_strtrim(&xpt->commands[j][1], " ");
	file = ft_substr(aux, 0, find_char(aux, ' '));
	xpt->out_fd = open(file, flags | O_TRUNC, 0777);
	free (aux);
	free (file);
}

void	redirect_out(t_struct *xpt, int j)
{
	int		flags;
	char	*file;

	flags = O_WRONLY | O_CREAT;
	j = xpt->c;
	if (xpt->commands[j] && xpt->commands[j][0] == '>')
	{
		if (xpt->commands[j] && xpt->commands[j][1] == '>')
		{
			file = ft_strtrim(&xpt->commands[j][2], " ");
			xpt->out_fd = open(file, flags | O_APPEND, 0777);
			free (file);
		}
		else
			simple_redir_out(xpt, j, flags);
		xpt->last_redir = 1;
		if (xpt->split.n_comand == 1)
			free(xpt->line);
	}
}
