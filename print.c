/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:12:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/12 12:36:34 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(t_philo *philo)
{
	long long	what;

	pthread_mutex_lock(&philo->loco->print);
	if (philo->loco->flag_death == 1)
	{
		pthread_mutex_unlock(&philo->loco->print);
		return ;
	}
	what = fetch_time() - philo->loco->start_time;
	printf("\033[0;35m%lld %d has taken a fork\n\033[0;37m", what, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_eating(t_philo *philo)
{
	long long	what;

	pthread_mutex_lock(&philo->loco->print);
	if (philo->loco->flag_death == 1)
	{
		pthread_mutex_unlock(&philo->loco->print);
		return ;
	}
	what = fetch_time() - philo->loco->start_time;
	printf("\033[0;33m%lld %d is eating\n\033[0;37m", what, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_sleeping(t_philo *philo)
{
	long long	what;

	pthread_mutex_lock(&philo->loco->print);
	if (philo->loco->flag_death == 1)
	{
		pthread_mutex_unlock(&philo->loco->print);
		return ;
	}
	what = fetch_time() - philo->loco->start_time;
	printf("\033[0;32m%lld %d is sleeping\n\033[0;37m", what, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_thinking(t_philo *philo)
{
	long long	what;

	pthread_mutex_lock(&philo->loco->print);
	if (philo->loco->flag_death == 1)
	{
		pthread_mutex_unlock(&philo->loco->print);
		return ;
	}
	what = fetch_time() - philo->loco->start_time;
	printf("\033[0;34m%lld %d is thinking\n\033[0;37m", what, philo->pos);
	pthread_mutex_unlock(&philo->loco->print);
}

void	print_died(t_philo *philo)
{
	long long	what;

	what = fetch_time() - philo->loco->start_time;
	printf("%lld %d died\n", what, philo->pos);
}
