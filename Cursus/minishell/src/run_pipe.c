/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:23:26 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 18:00:45 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_execve_pipe(t_struct *xpt, int i, char *command)
{
	if (xpt->tokens[0])
	{
		xpt->ret_number = execve(xpt->tokens[0], &xpt->tokens[0],
				xpt->env.env);
		while (xpt->path && xpt->path[i] != NULL)
		{
			command = ft_strdup(xpt->path[i]);
			if (xpt->tokens[0][0] == '|' && xpt->tokens[1])
			{
				if (!xpt->tokens[0][1])
					spaces_in_pipe(xpt, 2, command);
				else
				{
					xpt->tokens[0] = &xpt->tokens[0][1];
					spaces_in_pipe(xpt, 1, command);
				}
			}
			else
				spaces_in_pipe(xpt, 1, command);
			i++;
		}
		execve_error(xpt);
	}
}

static void	exec_process(t_struct *xpt, int in, int out)
{
	pid_t	pid;

	if (xpt->is_builtin && xpt->tokens[0])
		run_builtin(xpt);
	else
	{
		pid = fork();
		if (pid < 0)
		{
			printf("Fork error\n");
			xpt->ret_number = 127;
		}
		else if (pid == 0)
		{
			file_descriptor_handler(in, out);
			xpt->ret_number = 127;
			ft_execve_pipe(xpt, 0, "");
			exit(xpt->ret_number);
		}
		else
			waitpid(pid, &xpt->ret_number, WUNTRACED);
		if (WIFEXITED(xpt->ret_number))
			xpt->ret_number = WEXITSTATUS(xpt->ret_number);
	}
}

static void	action(t_struct *xpt)
{
	xpt->line = ft_strdup(xpt->commands[xpt->c]);
	if (xpt->split.n_comand > 1 )
		xpt->c++;
	xpt->error_name_file = NULL;
	while (xpt->commands[xpt->c] && xpt->commands[xpt->c][0] != '|')
	{
		redirect_out(xpt, xpt->c);
		redirect_in(xpt, xpt->c, NULL);
		xpt->c++;
	}
	if (xpt->error_name_file != NULL)
	{
		xpt->ret_number = 1;
		printf("minishell: %s: %s", xpt->error_name_file, ERROR_DIR);
		free(xpt->error_name_file);
	}
}

static void	run_commands_aux(t_struct *xpt)
{
	action(xpt);
	if (xpt->commands[0][0] != '>')
	{
		tokenizer(xpt);
		if (xpt->tokens[0])
			is_builtin(xpt->tokens[0], xpt);
		if (xpt->in_fd != -1)
			exec_process(xpt, xpt->in_fd, xpt->out_fd);
		free_char_array(xpt->tokens);
		free(xpt->token.to_print);
		free(xpt->token.to_exec);
	}
	if (xpt->name_file)
		unlink(xpt->name_file);
}

void	run_commands(t_struct *xpt)
{
	int	j;
	int	fd[2];

	j = 0;
	xpt->c = 0;
	xpt->last_redir = 0;
	while (j < xpt->split.qtt_pipe)
	{
		if (pipe(fd) < 0)
		{
			printf("Pipe error\n");
			xpt->ret_number = 127;
		}
		xpt->out_fd = fd[1];
		run_commands_aux(xpt);
		close(xpt->out_fd);
		if (xpt->in_fd != 0)
			close(xpt->in_fd);
		xpt->in_fd = fd[0];
		j++;
	}
	run_commands_aux(xpt);
}
