/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:31:01 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/09 19:09:41 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_stack	*ft_ps_stack_pop_front(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*ft_ps_stack_pop_back(t_stack **stack)
{
	t_stack	*pre_last;
	t_stack	*tmp;

	pre_last = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (pre_last->next && pre_last->next->next)
			pre_last = pre_last->next;
		tmp = pre_last->next;
		pre_last->next = NULL;
	}
	return (tmp);
}
