/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:12:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/02 18:46:53 by naal-jen         ###   ########.fr       */
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
	while(loco->flag_death == 0)
	{
		j = 0;
		while (j < loco->n_philos)
		{
			pthread_mutex_lock(&loco->philo[j].mutex_go);
			if ((fetch_time() - loco->start_time) >= (loco->philo[j].go + loco->t_die))
			{
				pthread_mutex_unlock(&loco->philo[j].mutex_go);
				pthread_mutex_lock(&loco->monitor);
				loco->flag_death = 1;
				printf("%lld %d died\n", fetch_time() - loco->start_time, j);
				exit(1);
				pthread_mutex_unlock(&loco->monitor);
			}
			pthread_mutex_unlock(&loco->philo[j].mutex_go);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->loco->print);
	printf("%lld %d has taken a fork\n", fetch_time() - philo->loco->start_time, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->loco->print);
	printf("\033[35m%lld %d is eating\n\033[0m", fetch_time() - philo->loco->start_time, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->loco->print);
	printf("\033[37m%lld %d is sleeping\n\033[0m", fetch_time() - philo->loco->start_time, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->loco->print);
	printf("%lld %d is thinking\n", fetch_time() - philo->loco->start_time, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_died(t_philo *philo)
{
	printf("%lld %d died\n", fetch_time() - philo->loco->start_time, philo->pos);
}