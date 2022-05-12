/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:39:03 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 18:39:32 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	is_builtin(char *cmd, t_struct *xpt)
{
	if ((!ft_strncmp("echo", cmd, 4) && ft_strlen(cmd) == 4)
		|| (!ft_strncmp("cd", cmd, 2) && ft_strlen(cmd) == 2)
		|| (!ft_strncmp("pwd", cmd, 3) && ft_strlen(cmd) == 3)
		|| (!ft_strncmp("export", cmd, 6) && ft_strlen(cmd) == 6)
		|| (!ft_strncmp("unset", cmd, 5) && ft_strlen(cmd) == 5)
		|| (!ft_strncmp("env", cmd, 3) && ft_strlen(cmd) == 3)
		|| (!ft_strncmp("exit", cmd, 4) && ft_strlen(cmd) == 4))
		xpt->is_builtin = true;
	else
		xpt->is_builtin = false;
}

void	run_builtin(t_struct *xpt)
{
	if (!ft_strncmp(xpt->tokens[0], "exit", 4))
		ft_exit(xpt);
	if (!ft_strncmp(xpt->tokens[0], "pwd", 3))
		ft_pwd(xpt);
	if (!ft_strncmp(xpt->tokens[0], "echo", 4))
		ft_echo(xpt);
	if (!ft_strncmp(xpt->tokens[0], "cd", 2))
		ft_cd(xpt);
	if (!ft_strncmp(xpt->tokens[0], "env", 3))
		ft_env(xpt);
	if (!ft_strncmp(xpt->tokens[0], "export", 6))
		ft_export(xpt);
	if (!ft_strncmp(xpt->tokens[0], "unset", 5))
		ft_unset(xpt);
}
