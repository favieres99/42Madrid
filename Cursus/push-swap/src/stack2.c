/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:15:45 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/10 15:00:03 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

char	*ternary2(t_stacks *sts)
{
	char	*str;

	str = "rrr";
	if (sts->opt_b > 0)
		str = "rr";
	return (str);
}

void	helper(int nodes, t_stack *tmp, t_stack *first, t_stack *st)
{
	int	i;

	i = 0;
	while (i < nodes)
	{
		if (tmp->next == NULL)
		{
			if (first->val < tmp->val)
				break ;
		}
		else
		{
			if (tmp->next->val < tmp->val)
				break ;
		}
		st->sort++;
		i++;
		if (tmp->next == NULL)
			tmp = first;
		else
			tmp = tmp->next;
	}
}

static char	**ternary(int argc, char *argv[])
{
	if (argc == 2)
		return (argv);
	return (NULL);
}

static void	ft_ps_create_stack_a_2(int argc, char *argv[], t_stacks *sts, int i)
{
	int	cur_val;

	argv = ft_strsplit(argv[1], ' ');
	while ((int)argv[i])
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			sts->flag_v = 1;
		else
		{
			cur_val = ft_atoi(argv[i]);
			if (ft_ps_is_valid_int(cur_val, argv[i]) == 0
				|| ft_ps_is_not_dupl(sts->a, cur_val) == 0)
				ft_ps_put_error(&sts, ft_free_array(ternary(argc, argv), 1));
			if ((ft_ps_stack_push_back_int(&sts->a, cur_val)) == NULL)
				ft_ps_put_error(&sts, ft_free_array(ternary(argc, argv), 1));
		}
		i++;
	}
	ft_free_array(ternary(argc, argv), 1);
}

void	ft_ps_create_stack_a(int argc, char *argv[], t_stacks *sts)
{
	int	i;
	int	cur_val;

	i = 1;
	if (argc == 2)
		ft_ps_create_stack_a_2(argc, argv, sts, 0);
	else
	{
		while (i < argc)
		{
			if (ft_strcmp(argv[i], "-v") == 0)
				sts->flag_v = 1;
			else
			{
				cur_val = ft_atoi(argv[i]);
				if (ft_ps_is_valid_int(cur_val, argv[i]) == 0
					|| ft_ps_is_not_dupl(sts->a, cur_val) == 0)
					ft_ps_put_error(&sts, 1);
				if ((ft_ps_stack_push_back_int(&sts->a, cur_val)) == NULL)
					ft_ps_put_error(&sts, 1);
			}
			i++;
		}
		ft_free_array(ternary(argc, argv), 1);
	}
}
