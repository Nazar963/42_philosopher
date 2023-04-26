/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/26 22:03:16 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*multi_philos(void	*arg)
{
	t_loco	*loco;
	int		next;

	loco = (t_loco *)arg;
	next = 0;
	loco->go = fetch_time();
	printf("%d\n", loco->pos);
	while (loco->philo->n_meals)
	{
		if (loco->pos == loco->philo->n_philos)
			next = 0;
		else
			next = loco->pos + 1;
		if (fetch_time() == loco->go + loco->philo->t_die)
		{
			pthread_mutex_lock(&loco->philo->print);
			print_died(loco);
			pthread_mutex_unlock(&loco->philo->print);
			break ;
		}
		//? take first fork and second fork
		pthread_mutex_lock(&loco->forks[loco->pos]);
		print_fork(loco);
		pthread_mutex_lock(&loco->forks[next]);
		print_fork(loco);
		print_eating(loco);
		ft_usleep(loco->philo->t_eat);
		pthread_mutex_unlock(&loco->forks[loco->pos]);
		pthread_mutex_unlock(&loco->forks[next]);
		loco->go = fetch_time();
		//? start sleeping
		pthread_mutex_lock(&loco->philo->print);
		print_sleeping(loco);
		ft_usleep(loco->philo->t_sleep);
		pthread_mutex_unlock(&loco->philo->print);
		//? start thinking
		pthread_mutex_lock(&loco->philo->print);
		print_thinking(loco);
		pthread_mutex_unlock(&loco->philo->print);
		loco->philo->n_meals--;
	}
	return (0);
}