/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:30:18 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/10 14:50:43 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_ps_set_index(t_stack *st)
{
	int	i;

	i = 0;
	while (st)
	{
		st->i = i;
		i++;
		st = st->next;
	}
}

t_stack	*ft_ps_get_max_sort(t_stack *st)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*max;
	int		nodes;

	first = st;
	max = st;
	nodes = ft_ps_get_count_nodes(st);
	while (st)
	{
		tmp = st;
		helper(nodes, tmp, first, st);
		if (st->sort >= max->sort)
			max = st;
		st = st->next;
	}
	return (max);
}

int	ft_ps_node_iter_to_up(int st_len, int node_i)
{
	if (st_len / 2 >= node_i)
		return (node_i);
	else
		return ((st_len - node_i) * -1);
}

int	ft_ps_get_node_place_i(t_stack *st, int node_val)
{
	t_stack	*optim;
	int		last_min;

	optim = NULL;
	last_min = 0;
	while (st)
	{
		if ((last_min == 0) || (last_min < 0 && st->val - node_val < 0
				&& st->val - node_val > last_min)
			|| (last_min > 0 && st->val - node_val < last_min))
		{
			last_min = st->val - node_val;
			optim = st;
		}
		if (st->next == NULL)
			break ;
		st = st->next;
	}
	if (optim == st && last_min < 0)
		return (-1);
	if (last_min < 0)
		return (optim->i + 1);
	return (optim->i);
}

int	ft_ps_node_b_to_a_count(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a < 0 && b < 0 && place_b != -1)
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		return (ft_abs(b));
	}
	else
		return (ft_abs(a) + ft_abs(b));
}
