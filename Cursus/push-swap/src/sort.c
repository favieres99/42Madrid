/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 18:29:58 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/10 15:05:38 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	ft_ps_st_a_norm(t_stacks *sts)
{
	int		com;
	char	*str;

	ft_ps_set_index(sts->a);
	sts->max_sort = ft_ps_get_max_sort(sts->a);
	sts->len_a = ft_ps_get_count_nodes(sts->a);
	if (sts->len_a - sts->max_sort->i - sts->max_sort->sort > 0)
		com = sts->len_a - (sts->len_a - sts->max_sort->i
				- sts->max_sort->sort);
	else
		com = ft_abs(sts->len_a - sts->max_sort->i - sts->max_sort->sort);
	com = ft_ps_node_iter_to_up(sts->len_a, com);
	str = "rra";
	if (com > 0)
		str = "ra";
	ft_ps_cmd_apply_cnt(str, com, sts);
}

void	ft_ps_st_a_to_b(t_stacks *sts)
{
	t_stack	*st_a;

	st_a = sts->a;
	while (st_a && st_a->i != sts->max_sort->i)
	{
		st_a = st_a->next;
		ft_ps_cmd_apply_cnt("pb", 1, sts);
	}
}

void	ft_ps_node_b_to_a(t_stacks *sts)
{
	char	*str;

	sts->tmp_b = ft_abs(sts->opt_b);
	sts->tmp_a = ft_abs(sts->opt_a);
	while (((sts->opt_b > 0 && sts->opt_a > 0) || (sts->opt_b < 0
				&& sts->opt_a < 0)) && sts->tmp_b && sts->tmp_a
		&& sts->opt_pl != -1)
	{
		ft_ps_cmd_apply_cnt(ternary2(sts), 1, sts);
		sts->tmp_b--;
		sts->tmp_a--;
	}
	str = "rrb";
	if (sts->opt_b > 0)
		str = "rb";
	ft_ps_cmd_apply_cnt(str, sts->tmp_b, sts);
	str = "rra";
	if (sts->opt_a > 0)
		str = "ra";
	if (sts->opt_pl != -1)
		ft_ps_cmd_apply_cnt(str, sts->tmp_a, sts);
	ft_ps_cmd_apply_cnt("pa", 1, sts);
	if (sts->opt_pl == -1)
		ft_ps_cmd_apply_cnt("ra", 1, sts);
}

void	ft_ps_st_b_to_a(t_stacks *sts)
{
	t_stack	*tmp_b;
	int		min_cmds;
	int		cmds;

	while (sts->b)
	{
		tmp_b = sts->b;
		ft_ps_set_index(sts->a);
		ft_ps_set_index(sts->b);
		sts->len_a = ft_ps_get_count_nodes(sts->a);
		sts->len_b = ft_ps_get_count_nodes(sts->b);
		min_cmds = ft_ps_st_set_tmp_cmds(sts, tmp_b);
		ft_ps_st_copy_tmp_to_opt_cmds(sts);
		while (tmp_b)
		{
			cmds = ft_ps_st_set_tmp_cmds(sts, tmp_b);
			if (min_cmds > cmds)
			{
				min_cmds = cmds;
				ft_ps_st_copy_tmp_to_opt_cmds(sts);
			}
			tmp_b = tmp_b->next;
		}
		ft_ps_node_b_to_a(sts);
	}
}

void	ft_ps_st_a_min_to_top(t_stacks *sts)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		iter_to_up;
	char	*str;

	tmp_a = sts->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		if (tmp_a->val < min_node->val)
			min_node = tmp_a;
		tmp_a = tmp_a->next;
	}
	sts->len_a = ft_ps_get_count_nodes(sts->a);
	ft_ps_set_index(sts->a);
	iter_to_up = ft_ps_node_iter_to_up(sts->len_a, min_node->i);
	str = "rra";
	if (iter_to_up > 0)
		str = "ra";
	ft_ps_cmd_apply_cnt(str, iter_to_up, sts);
}
