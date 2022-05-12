/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:34:15 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 18:01:42 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	restore_prompt(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

static void	ctrl_c(int sig)
{
	write(1, "\n", 1);
	(void)sig;
}

static void	back_slash(int sig)
{
	printf("Quit (core dumped)\n");
	(void)sig;
}

void	run_signals(int sig)
{
	if (sig == 0)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 3)
	{
		printf("exit\n");
		exit(0);
	}
}
