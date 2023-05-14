/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/14 12:05:15 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	print_sleeping(philo);
	ft_usleep(philo->loco->t_sleep);
	print_thinking(philo);
}

static t_philo	*position(t_philo *philo)
{
	if (philo->pos % 2 == 0)
	{
		philo->f_f = philo->pos;
		philo->s_f = philo->next;
	}
	else
	{
		philo->f_f = philo->next;
		philo->s_f = philo->pos;
	}
	return (philo);
}

static void	*star_tech(t_philo *philo)
{
	print_fork(philo);
	print_fork(philo);
	print_eating(philo);
	pthread_mutex_lock(&philo->loco->print);
	philo->n_meals--;
	pthread_mutex_unlock(&philo->loco->print);
	pthread_mutex_lock(&philo->mutex_go);
	philo->go = fetch_time() - philo->loco->start_time;
	pthread_mutex_unlock(&philo->mutex_go);
	ft_usleep(philo->loco->t_eat);
	pthread_mutex_unlock(&philo->loco->forks[philo->s_f]);
	pthread_mutex_unlock(&philo->loco->forks[philo->f_f]);
	think(philo);
	pthread_mutex_lock(&philo->loco->print);
	if (philo->loco->flag_death == 1)
	{
		pthread_mutex_unlock(&philo->loco->print);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->loco->print);
	philo->i = 0;
	return ((void *)1);
}

void	*multi(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo = position(philo);
	while (philo->n_meals)
	{
		if (philo->i < 3)
			ft_usleep(1);
		pthread_mutex_lock(&philo->loco->forks[philo->f_f]);
		if (pthread_mutex_lock(&philo->loco->forks[philo->s_f]) == 0)
		{
			if (star_tech(philo) == NULL)
				return (NULL);
		}
		else
		{
			pthread_mutex_unlock(&philo->loco->forks[philo->f_f]);
			if (philo->i < 2)
				ft_usleep(1);
		}
		philo->i++;
	}
	return (0);
}
