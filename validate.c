/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:20:32 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/06 14:13:54 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (ft_isdigit_new(av[1]) && ft_isdigit_new(av[2])
		&& ft_isdigit_new(av[3]) && ft_isdigit_new(av[4]))
	{
		if (ac == 6)
		{
			if (ft_isdigit_new(av[5]))
				return (TRUE);
			else
				return (FALSE);
		}
		else
			return (TRUE);
	}
	return (0);
}

int	check_values(t_loco *loco)
{
	if (loco->n_philos < 0 || loco->t_die < 0 || loco->t_eat < 0
		|| loco->t_sleep < 0)
		return (0);
	return (1);
}

t_loco	*initialize(int ac, char **av, t_loco *loco)
{
	int	i;

	i = 0;
	loco->flag_death = 0;
	loco->n_philos = ft_atoi(av[1]);
	loco->t_die = ft_atoi(av[2]);
	loco->t_eat = ft_atoi(av[3]);
	loco->t_sleep = ft_atoi(av[4]);
	loco->start_time = fetch_time();
	loco->result = 0;
	if (check_values(loco) == 0)
		return (NULL);
	while (i < loco->n_philos)
	{
		loco->philo[i].n_meals = ft_sp_atoi(ac, av);
		loco->philo[i].go = fetch_time();
		//* --------------------------------------------- new -------------------------------------------- */
		loco->philo[i].pos = 0;
		loco->philo[i].next = 0;
		if (pthread_mutex_init(&loco->philo[i].mutex_go, NULL) != 0)
			return(NULL);
		i++;
	}
	i = 0;
	loco->forks = (pthread_mutex_t *)malloc(loco->n_philos
			* sizeof(pthread_mutex_t));
	if (!loco->forks)
		return (NULL);
	while (i < loco->n_philos)
	{
		if (pthread_mutex_init(&loco->forks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	if (pthread_mutex_init(&loco->print, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&loco->monitor, NULL) != 0)
		return (NULL);
	return (loco);
}
