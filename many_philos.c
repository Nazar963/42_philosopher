/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/27 21:46:25 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *death_check(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	long long currentTime;

	while (1)
	{
		currentTime = fetch_time();
		if (currentTime >= philo->loco->go + philo->loco->t_die)
		{
			pthread_mutex_lock(&philo->loco->print);
			print_died(philo);
			pthread_mutex_unlock(&philo->loco->print);
			break;
		}
	}
	return (0);
}

void	*multi_philos(void	*arg)
{
	t_philo	*philo;
	int		next;
	pthread_t	death_check_thread;

	philo = (t_philo *)arg;
	next = 0;
	philo->loco->go = fetch_time();
	pthread_create(&death_check_thread, NULL, death_check, (void *)philo);
	while (--philo->n_meals)
	{
		if (philo->pos + 1 == philo->loco->n_philos)
			next = 0;
		else
			next = philo->pos + 1;
		// if (fetch_time() == philo->loco->go + philo->loco->t_die)
		// {
		// 	pthread_mutex_lock(&philo->loco->print);
		// 	print_died(philo);
		// 	pthread_mutex_unlock(&philo->loco->print);
		// 	break ;
		// }

		pthread_mutex_lock(&philo->loco->monitor);
		pthread_mutex_lock(&philo->loco->forks[philo->pos]);
		print_fork(philo);
		pthread_mutex_lock(&philo->loco->forks[next]);
		print_fork(philo);
		print_eating(philo);
		ft_usleep(philo->loco->t_eat);
		pthread_mutex_unlock(&philo->loco->forks[philo->pos]);
		pthread_mutex_unlock(&philo->loco->forks[next]);
		pthread_mutex_unlock(&philo->loco->monitor);

		philo->loco->go = fetch_time();

		pthread_mutex_lock(&philo->loco->print);
		print_sleeping(philo);
		ft_usleep(philo->loco->t_sleep);
		pthread_mutex_unlock(&philo->loco->print);

		pthread_mutex_lock(&philo->loco->print);
		print_thinking(philo);
		pthread_mutex_unlock(&philo->loco->print);
	}
	return (0);
}