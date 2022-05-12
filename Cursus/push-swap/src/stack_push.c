/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:31:21 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/09 19:09:28 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_ps_stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_ps_get_last_node(*stack);
	last->next = new;
}

void	ft_ps_stack_push_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack	*ft_ps_stack_push_back_int(t_stack **stack, int val)
{
	t_stack	*new;

	new = ft_ps_create_new_node(val);
	if (new == NULL)
		return (NULL);
	ft_ps_stack_push_back(stack, new);
	return (*stack);
}
