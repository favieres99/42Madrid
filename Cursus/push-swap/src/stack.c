/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:30:34 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/10 14:42:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_stack	*ft_ps_create_new_node(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_ps_get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int	ft_ps_get_count_nodes(t_stack *st)
{
	int	count;

	count = 0;
	while (st)
	{
		st = st->next;
		count++;
	}
	return (count);
}

t_stacks	*ft_ps_create_stacks(int argc, char **argv)
{
	t_stacks	*sts;

	sts = (t_stacks *)malloc(sizeof(t_stacks));
	if (sts == NULL)
		ft_ps_put_error(&sts, 1);
	sts->a = NULL;
	sts->b = NULL;
	sts->flag_v = 0;
	sts->cmds_cnt = 0;
	sts->cmd_print = 0;
	ft_ps_create_stack_a(argc, argv, sts);
	return (sts);
}
