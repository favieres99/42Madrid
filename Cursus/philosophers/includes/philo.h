/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 00:59:07 by gfaviere          #+#    #+#             */
/*   Updated: 2021/08/26 14:30:00 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		t_last_meal;
	struct s_rules	*rules;
	pthread_t		thread_id;
}				t_phil;

typedef struct s_rules
{
	int				nb_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	int				died;
	int				all_eat;
	long long		first_timestamp;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	forks[250];
	pthread_mutex_t	thinking;
	t_phil			philo[250];
}				t_rules;

int			error_manage(int error);
int			write_error(char *str);
int			launcher(t_rules *rules);
void		action_print(t_rules *rules, int id, char *string);
void		smart_sleep(long long time, t_rules *rules);
long long	time_diff(long long past, long long pres);
long long	timestamp(void);
void		unlocker(t_rules *r, int i, t_phil *p);

#endif