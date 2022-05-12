/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:12:46 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 19:35:25 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_pipe(t_struct *xpt, char *in, int i)
{
	if (in[i] == '|' || in[i] == '<' || in[i] == '>')
	{
		if (in[i] == '|' && xpt->split.q == 0)
			xpt->split.qtt_pipe++;
		if (xpt->split.q == 0 && i > 1 && xpt->split.len > 0)
		{
			xpt->commands[xpt->split.n_comand] = ft_substr(in,
					xpt->split.ini, xpt->split.len);
			xpt->split.ini = i;
			xpt->split.len = 0;
			xpt->split.n_comand++;
			if (in[i] == '>')
				xpt->last_redir = 1;
			else
				xpt->last_redir = 0;
			if (in[i] == in[i + 1])
			{
				i++;
				xpt->split.len = 1;
			}
		}
	}
	return (i);
}

static char	*clean_spaces(char *in)
{
	char	*aux;

	aux = ft_strtrim(in, " ");
	in = aux;
	return (in);
}

static void	init_split_struct(t_struct *xpt)
{
	xpt->split.n_comand = 0;
	xpt->split.ini = 0;
	xpt->split.len = 0;
	xpt->split.qtt_pipe = 0;
	xpt->split.q = 0;
	xpt->last_redir = 0;
}

void	split_cmd(t_struct *xpt, char *in, int i)
{
	init_split_struct(xpt);
	in = clean_spaces(in);
	while (i < (int)ft_strlen(in))
	{
		if (xpt->split.q == 0 && (in[i] == D_QUOTE || in[i] == QUOTE))
			xpt->split.q = in[i];
		else
		{
			if (xpt->split.q == in[i])
				xpt->split.q = 0;
			else
				i = count_pipe(xpt, in, i);
		}
		xpt->split.len++;
		i++;
	}
	if (ft_strlen(in) > 0)
	{
		xpt->commands[xpt->split.n_comand]
			= ft_substr(in, xpt->split.ini, i);
		xpt->split.n_comand++;
	}
	free(in);
	xpt->commands[xpt->split.n_comand] = NULL;
}
