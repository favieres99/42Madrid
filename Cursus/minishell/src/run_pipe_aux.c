/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:29:55 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 12:32:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execve_error(t_struct *xpt)
{
	xpt->ret_number = 127;
	if (xpt->tokens[0][0] != '|')
		printf("minishell: %s: %s", xpt->tokens[0], ERROR_CMD);
	else if (xpt->tokens[1])
		printf("minishell: %s: %s", xpt->tokens[1], ERROR_CMD);
}

void	spaces_in_pipe(t_struct *xpt, int i, char *command)
{
	char	*aux;

	if (ft_strlen(xpt->token.to_print) && xpt->tokens[i]
		&& (xpt->tokens[i][0] == QUOTE || xpt->tokens[i][0] == D_QUOTE)
		&& ft_strncmp(xpt->tokens[i - 1], "sed", 3))
	{
		aux = ft_strtrim(xpt->token.to_print, D_QUOTE_S);
		free_char_array2(&xpt->tokens[i + 1]);
	}
	else
		aux = ft_strtrim(xpt->tokens[i], D_QUOTE_S);
	free(xpt->tokens[i]);
	xpt->tokens[i] = aux;
	command = ft_strjoin(command, xpt->tokens[i - 1]);
	xpt->ret_number = execve(command, &xpt->tokens[i - 1], xpt->env.env);
	free(command);
}

int	file_descriptor_handler(int in, int out)
{
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{
		dup2(out, 1);
		close(out);
	}
	return (0);
}
