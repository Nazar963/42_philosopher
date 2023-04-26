/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:24:33 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/26 22:06:33 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_loco	*loco;
	int		num;

	num = 0;
	if (!(ac == 5 || ac == 6))
		return (0);
	if (check_args(ac, av) == FALSE)
		return (0);
	loco = (t_loco *)malloc(sizeof(t_loco));
	if (!loco)
		return (0);
	loco->philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!loco->philo)
		return (0);
	loco->philosopher = malloc(sizeof(loco->philosopher) * 2);
	loco = initialize(ac, av, loco);
	if (loco->philo->n_philos == 1)
	{
		if (pthread_create(loco->philosopher, NULL, one_philo, (void *)loco) != 0)
			return (0);
	}
	else
	{
		while (num < loco->philo->n_philos)
		{
			loco->pos = num;
			if (pthread_create(loco->philosopher, NULL, multi_philos, (void *)loco) != 0)
				return (0);
			num++;
		}
	}
	pthread_join(*loco->philosopher, NULL);
	pthread_mutex_destroy(&loco->philo->print);
	exit(1);
	//!you have to join the thread
	//! you have to destroy the mutex

}


void *multi_philos(void *arg) {
    t_loco *loco = (t_loco *)arg;
    t_philo *philo = &loco->philo[loco->current_index];
    // ...

    printf("%d\n", philo->pos);

    // ...
}
