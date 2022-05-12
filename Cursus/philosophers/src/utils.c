/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:54:13 by marvin            #+#    #+#             */
/*   Updated: 2021/08/26 14:30:38 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	smart_sleep(long long time, t_rules *rules)
{
	long long	i;

	i = timestamp();
	while (!(rules->died))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}

void	action_print(t_rules *rules, int id, char *string)
{
	pthread_mutex_lock(&(rules->thinking));
	if (!(rules->died))
	{
		printf("%lli ", timestamp() - rules->first_timestamp);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(rules->thinking));
	return ;
}

void	unlocker(t_rules *r, int i, t_phil *p)
{
	pthread_mutex_unlock(&(r->forks[p[i].left_fork_id]));
	pthread_mutex_unlock(&(r->forks[p[i].right_fork_id]));
}
