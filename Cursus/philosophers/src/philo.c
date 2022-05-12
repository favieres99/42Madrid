/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 01:01:51 by gfaviere          #+#    #+#             */
/*   Updated: 2021/07/21 15:23:23 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(rules->thinking), NULL))
		return (1);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (1);
	return (0);
}

static void	init_philosophers(t_rules *rules)
{
	int	i;

	i = rules->nb_philo;
	while (--i >= 0)
	{
		rules->philo[i].id = i;
		rules->philo[i].x_ate = 0;
		rules->philo[i].left_fork_id = i;
		rules->philo[i].right_fork_id = (i + 1) % rules->nb_philo;
		rules->philo[i].t_last_meal = 0;
		rules->philo[i].rules = rules;
	}
}

static int	init_all(t_rules *rules, char *argv[])
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_death = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->all_eat = 0;
	rules->died = 0;
	if (rules->nb_philo < 1 || rules->time_death < 0 || rules->time_eat < 0
		|| rules->time_sleep < 0 || rules->nb_philo > 250)
		return (1);
	if (argv[5])
	{
		rules->nb_eat = ft_atoi(argv[5]);
		if (rules->nb_eat <= 0)
			return (1);
	}
	else
		rules->nb_eat = -1;
	if (init_mutex(rules))
		return (2);
	init_philosophers(rules);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_rules	rules;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error("Not the right amount of parameters"));
	ret = init_all(&rules, argv);
	if (ret)
		return (error_manage(ret));
	if (launcher(&rules))
		return (write_error("Error creating the threads"));
	return (0);
}
