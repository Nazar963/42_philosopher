/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/02 10:28:30 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*multi_philos(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// pthread_mutex_lock(&philo->loco->monitor);
	// philo->go = fetch_time();
	// pthread_mutex_unlock(&philo->loco->monitor);
	ft_usleep(philo->pos % 2 * 10);
	// printf("meals%ld\n", philo->n_meals);
	while (--philo->loco->n_meals)
	{
		// printf("meals left%ld\n", philo->loco->n_meals);
		// printf("your i is: %d\n", i);
		// pthread_mutex_lock(&philo->loco->monitor);

		// printf("first: %d next: %d\n", philo->pos, next);
		// pthread_mutex_unlock(&philo->loco->monitor);
		
		// printf("time fetch: %lld\n", fetch_time());
		// printf("time go: %lld\n", philo->go);
		// printf("time t_die: %d\n", philo->loco->t_die);
		// printf("time tot: %lld\n", (philo->go + philo->loco->t_die) - fetch_time());


		// printf("here am at: %d\n", philo->pos)
		// pthread_mutex_lock(&philo->loco->monitor);
		pthread_mutex_lock(&philo->loco->forks[philo->pos]);
		print_fork(philo);
		pthread_mutex_lock(&philo->loco->forks[philo->next]);
		print_fork(philo);
		philo->go = fetch_time();
		print_eating(philo);
		ft_usleep(philo->loco->t_eat);
		pthread_mutex_unlock(&philo->loco->forks[philo->next]);
		pthread_mutex_unlock(&philo->loco->forks[philo->pos]);
		// pthread_mutex_unlock(&philo->loco->monitor);

		// printf("time fetch2: %lld\n", fetch_time());
		// printf("time go2: %lld\n", philo->go);
		// printf("time t_die2: %d\n", philo->loco->t_die);
		// printf("time tot2: %lld\n", (philo->go + philo->loco->t_die) - fetch_time());

		// if (fetch_time() >= philo->go + philo->loco->t_die)
		// {
		// 	philo->loco->flag_death = 1;
		// 	pthread_mutex_lock(&philo->loco->monitor);
		// 	print_died(philo);
		// 	pthread_mutex_unlock(&philo->loco->monitor);
		// 	exit(1);
		// 	break ;
		// }


		
		print_sleeping(philo);
		ft_usleep(philo->loco->t_sleep);

		// printf("time fetch3: %lld\n", fetch_time());
		// printf("time g3o: %lld\n", philo->go);
		// printf("time t_die3: %d\n", philo->loco->t_die);
		// printf("time tot3: %lld\n", (philo->go + philo->loco->t_die) - fetch_time());


		// if (fetch_time() >= philo->go + philo->loco->t_die)
		// {
		// 	philo->loco->flag_death = 1;
		// 	pthread_mutex_lock(&philo->loco->monitor);
		// 	print_died(philo);
		// 	pthread_mutex_unlock(&philo->loco->monitor);
		// 	exit(1);
		// 	break ;
		// }

		print_thinking(philo);
	}
	exit(1);
	return (0);
}

/**
 * * try do to a mutex lock on all the prints
 * * try to mke the next operation claculator before the thread
*/