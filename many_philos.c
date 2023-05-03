/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/03 10:38:04 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*multi_philos(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_usleep((philo->pos % 2) * 100);
	while (philo->n_meals)
	{
		pthread_mutex_lock(&philo->loco->forks[philo->pos]);
		print_fork(philo);
		pthread_mutex_lock(&philo->loco->forks[philo->next]);
		print_fork(philo);
		print_eating(philo);
        philo->n_meals--;
		philo->go = fetch_time() - philo->loco->start_time;
		ft_usleep(philo->loco->t_eat);
		pthread_mutex_unlock(&philo->loco->forks[philo->next]);
		pthread_mutex_unlock(&philo->loco->forks[philo->pos]);

		print_sleeping(philo);
		ft_usleep(philo->loco->t_sleep);
		
		print_thinking(philo);
	}
	return (0);
}
