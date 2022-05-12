/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:07:42 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 18:01:00 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*create_prompt(void)
{
	char	*buf;
	char	*prompt;
	char	*cyan;
	char	*white;

	buf = get_cwd_buf();
	cyan = ft_strdup(CYAN);
	white = ft_strdup(WHITE);
	prompt = ft_strjoin(cyan, buf);
	free(buf);
	prompt = ft_strjoin(prompt, white);
	free(white);
	prompt = ft_strjoin(prompt, " $ ");
	return (prompt);
}

static void	get_line(t_struct *xpt)
{
	char	*prompt;

	prompt = create_prompt();
	xpt->line_read = readline(prompt);
	if (xpt->line_read && *xpt->line_read)
		add_history(xpt->line_read);
	free(prompt);
}

static void	init(t_struct *xpt)
{
	run_signals(0);
	xpt->ret_number = 0;
	xpt->last_redir = 0;
	xpt->ret_number = 0;
	xpt->tokens = (char **) NULL;
	create_env(xpt, environ);
	init_path(xpt);
	xpt->home = ft_strdup(find_env(xpt, "HOME"));
}

int	main(void)
{
	t_struct	xpt;

	init(&xpt);
	while (1)
	{
		xpt.out_fd = STDOUT_FILENO;
		xpt.in_fd = STDIN_FILENO;
		get_line(&xpt);
		if (xpt.line_read)
		{
			if (ft_strlen(xpt.line_read) != 0)
			{
				split_cmd(&xpt, xpt.line_read, 0);
				if (xpt.split.n_comand > 0 && xpt.commands[0][0] != '|')
					run_commands(&xpt);
				if (xpt.commands[0] && xpt.commands[0][0] == '|')
					printf(ERROR_PIPE);
				free_char_array2(xpt.commands);
			}
			free(xpt.line_read);
		}
		else
			run_signals(3);
	}
}
