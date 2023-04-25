/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:24:33 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/25 19:26:21 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_loco	*loco;

	if (ac != 5 || ac != 6)
		return (0);
	if (check_args(ac, av) == FALSE)
		return (0);
	initialize(ac, av, loco);
	if (loco->philo->n_philos == 1)
		if (pthread_create(loco->philosopher, NULL, one_philo, (void *)&loco) != 0)
			return (0);
	//!you have to join the thread
	//! you have to destroy the mutex

}
