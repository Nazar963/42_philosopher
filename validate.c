/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:20:32 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/25 20:09:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (ft_isdigit(ft_atoi(av[1])) && ft_isdigit(ft_atoi(av[2]))
		&& ft_isdigit(ft_atoi(av[3])) && ft_isdigit(ft_atoi(av[4])))
	{
		if (ac == 6)
		{
			if (ft_isdigit(ft_atoi(av[5])))
				return (TRUE);
			else
				return (FALSE);
		}
		else
			return (TRUE);
	}
}

void	*initialize(int ac, char **av, t_loco *loco)
{
	loco = (t_loco *)malloc(sizeof(t_loco));
	if (!loco)
		return (NULL);
	loco->i = 0;
	loco->philo->n_philos = ft_atoi(av[1]);
	loco->philo->t_die = ft_atoi(av[2]) * 1000;
	loco->philo->t_eat = ft_atoi(av[3]) * 1000;
	loco->philo->t_sleep = ft_atoi(av[4]) * 1000;
	loco->philo->n_meals = ft_sp_atoi(ac, av) + 1;
	loco->forks = (pthread_mutex_t *)malloc(loco->n_philos
			* sizeof(pthread_mutex_t));
	if (!loco->forks)
		return (NULL);
	if (!pthread_mutex_init(&loco->print, NULL))
		return (NULL);
}
