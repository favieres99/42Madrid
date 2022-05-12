/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:29:40 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/10 13:07:51 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_ps_cmd_apply_s(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int	ft_ps_cmd_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_ps_stack_push_back(stack, ft_ps_stack_pop_front(stack));
		return (1);
	}
	return (-1);
}

int	ft_ps_cmd_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_ps_stack_push_front(stack, ft_ps_stack_pop_back(stack));
		return (1);
	}
	return (-1);
}

int	ft_ps_cmd_apply_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_ps_stack_push_front(to, ft_ps_stack_pop_front(from));
		return (1);
	}
	return (-1);
}
