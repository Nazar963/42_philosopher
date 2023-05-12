/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:29:49 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/12 14:39:28 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	print_sleeping(philo);
	ft_usleep(philo->loco->t_sleep);
	print_thinking(philo);
}

void	*multi(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_usleep((philo->pos % 2) * 100);
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
	while (philo->n_meals)
	{
		pthread_mutex_lock(&philo->loco->forks[philo->f_f]);
		if (pthread_mutex_lock(&philo->loco->forks[philo->s_f]) == 0)
		{
			print_fork(philo);
			print_fork(philo);
			print_eating(philo);
			philo->n_meals--;
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
		}
		else
		{
			pthread_mutex_unlock(&philo->loco->forks[philo->f_f]);
			ft_usleep(1);
		}
	}
	return (0);
}

/* ---------------------------------------------------------------------------------------------- */

// static int	first(t_philo *philo)
// {
// 	if (philo->pos < philo->next)
// 		return (philo->pos);
// 	else
// 		return (philo->next);
// }

// static int	second(t_philo *philo)
// {
// 	if (philo->pos < philo->next)
// 		return (philo->next);
// 	else
// 		return (philo->pos);
// }

// static void	think(t_philo *philo)
// {
// 	print_sleeping(philo);
// 	ft_usleep(philo->loco->t_sleep);
// 	print_thinking(philo);
// }

// void	*multi(void	*arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
	// philo->f_f = first(philo);
	// philo->s_f = second(philo);
// 	ft_usleep((philo->pos % 2) * 100);
// 	while (philo->n_meals)
// 	{
// 		pthread_mutex_lock(&philo->loco->forks[philo->f_f]);
// 		print_fork(philo);
// 		pthread_mutex_lock(&philo->loco->forks[philo->s_f]);
// 		print_fork(philo);
// 		print_eating(philo);
// 		philo->n_meals--;
// 		pthread_mutex_lock(&philo->mutex_go);
// 		philo->go = fetch_time() - philo->loco->start_time;
// 		pthread_mutex_unlock(&philo->mutex_go);
// 		ft_usleep(philo->loco->t_eat);
// 		pthread_mutex_unlock(&philo->loco->forks[philo->s_f]);
// 		pthread_mutex_unlock(&philo->loco->forks[philo->f_f]);
// 		think(philo);
// 		if (philo->loco->flag_death == 1)
// 			break ;
// 	}
// 	return (0);
// }

/* ---------------------------------------------------------------------------------------------- */


// void	*multi(void	*arg)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)arg;
// 	ft_usleep((philo->pos % 2) * 100);
// 	while (philo->n_meals)
// 	{
// 		pthread_mutex_lock(&philo->loco->forks[philo->pos]);
// 		print_fork(philo);
// 		pthread_mutex_lock(&philo->loco->forks[philo->next]);
// 		print_fork(philo);
// 		print_eating(philo);
// 		philo->n_meals--;
// 		pthread_mutex_lock(&philo->mutex_go);
// 		philo->go = fetch_time() - philo->loco->start_time;
// 		pthread_mutex_unlock(&philo->mutex_go);
// 		ft_usleep(philo->loco->t_eat);
// 		pthread_mutex_unlock(&philo->loco->forks[philo->next]);
// 		pthread_mutex_unlock(&philo->loco->forks[philo->pos]);
// 		print_sleeping(philo);
// 		ft_usleep(philo->loco->t_sleep);
// 		print_thinking(philo);
// 		if (philo->loco->flag_death == 1)
// 			break ;
// 	}
// 	return (0);
// }
