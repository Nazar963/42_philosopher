/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/30 15:34:13 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	*multi_philos(void	*arg)
{
	t_philo	*philo;
	int		next;
	int		i;

	philo = (t_philo *)arg;

	// printf("my pos is: %d\n", philo->pos);
	i = 0;
	next = 0;
	// pthread_mutex_lock(&philo->loco->monitor);
	// philo->go = fetch_time();
	// pthread_mutex_unlock(&philo->loco->monitor);
	ft_usleep(philo->pos % 2);
	// printf("meals%ld\n", philo->n_meals);
	while (--philo->loco->n_meals)
	{
		printf("meals left%ld\n", philo->loco->n_meals);
		i++;
		printf("your i is: %d\n", i);
		// pthread_mutex_lock(&philo->loco->monitor);
		if (philo->pos + 1 == philo->loco->n_philos)
			next = 0;
		else
			next = philo->pos + 1;
		printf("first: %d next: %d\n", philo->pos, next);
		// pthread_mutex_unlock(&philo->loco->monitor);
		
		// printf("time fetch: %lld\n", fetch_time());
		// printf("time go: %lld\n", philo->go);
		// printf("time t_die: %d\n", philo->loco->t_die);
		// printf("time tot: %lld\n", (philo->go + philo->loco->t_die) - fetch_time());


		// printf("here am at: %d\n", philo->pos)
		// pthread_mutex_lock(&philo->loco->monitor);
		pthread_mutex_lock(&philo->loco->forks[philo->pos]);
		print_fork(philo);
		pthread_mutex_lock(&philo->loco->forks[next]);
		print_fork(philo);
		print_eating(philo);
		philo->go = fetch_time();
		ft_usleep(philo->loco->t_eat);
		pthread_mutex_unlock(&philo->loco->forks[next]);
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


		pthread_mutex_lock(&philo->loco->print);
		print_sleeping(philo);
		ft_usleep(philo->loco->t_sleep);
		pthread_mutex_unlock(&philo->loco->print);

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

		pthread_mutex_lock(&philo->loco->print);
		print_thinking(philo);
		pthread_mutex_unlock(&philo->loco->print);
	}
	exit(1);
	return (0);
}