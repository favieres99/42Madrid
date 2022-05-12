/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:39:48 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 12:32:20 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static bool	there_is_home(t_struct *xpt)
{
	if (find_env(xpt, "HOME"))
		return (true);
	else
		return (false);
}

int	ft_cd(t_struct *xpt)
{
	char	*token_aux;
	bool	home;

	home = there_is_home(xpt);
	if (xpt->tokens[1])
		token_aux = ft_strdup(xpt->token.to_print);
	else
	{
		if (home == true)
			token_aux = ft_strdup(xpt->home);
		else
		{
			xpt->ret_number = 1;
			printf(ERROR_HOME);
			return (1);
		}
	}
	xpt->ret_number = chdir(token_aux);
	if (xpt->ret_number == -1)
		printf("minishell: cd: %s: %s", xpt->tokens[1], ERROR_DIR);
	free(token_aux);
	return (0);
}
