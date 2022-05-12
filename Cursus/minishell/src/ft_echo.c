/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jballest <jballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:40:31 by gfaviere          #+#    #+#             */
/*   Updated: 2021/11/05 13:07:44 by jballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	init_echo(t_struct *xpt, int n)
{
	if (xpt->tokens[0][0] != '|')
		n = 1;
	else
		n = 2;
	return (n);
}

static void	print_echo(t_struct *xpt, char *xpt_tokens_i)
{
	if (!ft_strncmp(xpt_tokens_i, "$?", 2))
		ft_putnbr_fd(xpt->ret_number, xpt->out_fd);
	else
	{
		ft_putstr_fd(xpt_tokens_i, xpt->out_fd);
		xpt->ret_number = 0;
	}
}

void	ft_echo(t_struct *xpt)
{
	int		j;
	int		n;

	n = init_echo(xpt, 0);
	j = 0;
	if (xpt->tokens[1])
	{
		print_echo(xpt, xpt->token.to_print);
		if (!xpt->has_flag)
			ft_putstr_fd("\n", xpt->out_fd);
	}
	else
		ft_putstr_fd("\n", xpt->out_fd);
}
