/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:57:11 by marvin            #+#    #+#             */
/*   Updated: 2021/08/26 14:30:26 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eats(t_phil *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&(rules->forks[philo->left_fork_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->forks[philo->right_fork_id]));
	action_print(rules, philo->id, "has taken a fork");
	pthread_mutex_lock(&(rules->meal_check));
	action_print(rules, philo->id, "is eating");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
	pthread_mutex_unlock(&(rules->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(rules->forks[philo->right_fork_id]));
}

static void	*p_thread(void *void_philosopher)
{
	int		i;
	t_phil	*philo;
	t_rules	*rules;

	i = 0;
	philo = (t_phil *)void_philosopher;
	rules = philo->rules;
	if (philo->id % 2)
		usleep(15000);
	while (!(rules->died))
	{
		philo_eats(philo);
		if (rules->all_eat)
			break ;
		action_print(rules, philo->id, "is sleeping");
		smart_sleep(rules->time_sleep, rules);
		action_print(rules, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

static void	exit_launcher(t_rules *rules, t_phil *philo)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_join(philo[i].thread_id, NULL);
	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&(rules->forks[i]));
	pthread_mutex_destroy(&(rules->thinking));
}

static void	death_checker(t_rules *r, t_phil *p)
{
	int	i;

	while (!(r->all_eat))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->died))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->time_death)
			{
				action_print(r, i, "died");
				r->died = 1;
				unlocker(r, i, p);
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->died)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_eat = 1;
	}
}

int	launcher(t_rules *rules)
{
	int		i;
	t_phil	*phi;

	i = 0;
	phi = rules->philo;
	rules->first_timestamp = timestamp();
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, p_thread, &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(rules, rules->philo);
	exit_launcher(rules, phi);
	return (0);
}
