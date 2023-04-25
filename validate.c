/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:20:32 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/16 16:10:33 by naal-jen         ###   ########.fr       */
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

t_nabo	*initialize(int ac, char **av, t_nabo *nabo)
{
	nabo = (t_loco *)malloc(sizeof(t_loco));
	if (!loco)
		return (0);
	loco->i = 0;
	loco->id = 0;
	loco->start = get_time();
	loco->philos = ft_atoi(av[1]);
	loco->die = ft_atoi(av[2]);
	loco->eat = ft_atoi(av[3]);
	loco->sleep = ft_atoi(av[4]);
	loco->eat_times = ft_sp_atoi(ac, av);
	loco->dead = FALSE;
	loco->forks = (pthread_mutex_t *)malloc(loco->philos
			* sizeof(pthread_mutex_t));
	if (!loco->forks)
		return (NULL);
	if (!pthread_mutex_init(&loco->print, NULL))
		return (NULL);
}

void	just_one_philo(t_loco *loco)
{
	if (loco->philos == 1)
	{
		if (pthread_create(loco->))
	}
}