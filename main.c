/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:24:33 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/02 10:27:52 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_loco	*loco;
	pthread_t com;
	int		i;

	i = 0;

	//* -------------------------------------------------------------------------- */
	if (!(ac == 5 || ac == 6))
		return (0);

	//* -------------------------------------------------------------------------- */
	if (check_args(ac, av) == FALSE)
		return (0);

	//* -------------------------------------------------------------------------- */
	loco = (t_loco *)malloc(sizeof(t_loco));
	if (!loco)
		return (0);

	//* -------------------------------------------------------------------------- */
	loco->philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!loco->philo)
		return (0);

	//* -------------------------------------------------------------------------- */
		loco->philosopher = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]));
		if (!loco->philosopher)
			return (0);

	//* -------------------------------------------------------------------------- */
		loco = initialize(ac, av, loco);

	//! -------------------------------------------------------------------------- */
	if (ft_atoi(av[1]) == 1)
	{
		loco->philo[i].loco = loco;
		if (pthread_create(&loco->philosopher[i], NULL, one_philo, (void *)&loco->philo[i]) != 0)
			return (0);
	}
	else
	{
		// printf("%d\n", loco->n_philos);
		if (pthread_create(&com, NULL, camm, loco) != 0)
			printf("fuck");
		while (i < ft_atoi(av[1]))
		{
			loco->philo[i].pos = i;
			if (loco->philo[i].pos + 1 == loco->n_philos)
				loco->philo[i].next = 0;
			else
				loco->philo[i].next = loco->philo[i].pos + 1;
			loco->philo[i].loco = loco;

			if (pthread_create(&loco->philosopher[i], NULL, multi_philos, (void *)&loco->philo[i]) != 0)
				return (0);
			i++;
		}
	}
	i = 0;
	
	//! -------------------------------------------------------------------------- */
	while (i < ft_atoi(av[1]))
	{
		pthread_join(loco->philosopher[i], NULL);
		i++;
	}
	i = 0;

	//! -------------------------------------------------------------------------- */
	pthread_mutex_destroy(&loco->print);
	pthread_mutex_destroy(&loco->monitor);

	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_destroy(loco->forks); 
		i++;
	}

	exit(1);
}


// void *multi_philos(void *arg) {
//     t_loco *loco = (t_loco *)arg;
//     t_philo *philo = &loco->philo[loco->current_index];
//     // ...

//     printf("%d\n", philo->pos);

//     // ...
// }
