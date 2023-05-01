/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:12:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/30 15:09:25 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*camm(void	*arg)
{
	t_loco *loco;
	int	i;
	int j;

	i = 0;
	j = 0;
	loco = (t_loco *)arg;
	// printf("%d\n", loco->n_philos);
	while(loco->flag_death == 0)
	{
		j = 0;
		while (j < loco->n_philos)
		{
			// printf("time fetch: %lld\n", fetch_time());
			// printf("time go: %lld\n", loco->philo[j].go);
			// printf("time t_die: %d\n", loco->t_die);
			// printf("time tot: %lld\n", (loco->philo->go + loco->t_die) - fetch_time());
			// printf("time: %lld\n", loco->philo[j].go);
			if (fetch_time() >= loco->philo[j].go + loco->t_die)
			{
				pthread_mutex_lock(&loco->monitor);
				loco->flag_death = 1;
				printf("%lld %d died\n", fetch_time(), j);
				exit(1);
				pthread_mutex_unlock(&loco->monitor);
			}
			j++;
		}
		i++;
	}
	return (NULL);
	
}

void	print_fork(t_philo *philo)
{
	printf("%lld %d has taken a fork\n", fetch_time(), philo->pos);
}

void	print_eating(t_philo *philo)
{
	printf("%lld %d is eating\n", fetch_time(), philo->pos);
}

void	print_sleeping(t_philo *philo)
{
	printf("%lld %d is sleeping\n", fetch_time(), philo->pos);
}

void	print_thinking(t_philo *philo)
{
	printf("%lld %d is thinking\n", fetch_time(), philo->pos);
}

void	print_died(t_philo *philo)
{
	printf("%lld %d died\n", fetch_time(), philo->pos);
}