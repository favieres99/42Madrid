/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:31:57 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/10 13:12:01 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int	ft_ps_is_valid_int(int val_i, char *val_c)
{
	char	*cur_val;
	int		res;

	res = 0;
	cur_val = ft_itoa(val_i);
	if (ft_strcmp(cur_val, val_c) == 0)
		res = 1;
	if (cur_val)
		free(cur_val);
	return (res);
}

int	ft_ps_is_not_dupl(t_stack *st, int val)
{
	while (st)
	{
		if (st->val == val)
			return (0);
		st = st->next;
	}
	return (1);
}

int	ft_ps_is_sort_stacks(t_stacks *sts)
{
	t_stack	*st_a;
	int		last_val;

	if (sts->b != NULL)
		return (0);
	st_a = sts->a;
	last_val = st_a->val;
	while (st_a)
	{
		if (last_val > st_a->val)
			return (0);
		last_val = st_a->val;
		st_a = st_a->next;
	}
	return (1);
}
