/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:24:33 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/11 16:18:14 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_loco	*loco;

	loco = (t_loco *)malloc(sizeof(t_loco));
	if (!loco)
		return (0);
	if (error_ac(ac, av, loco) == FALSE)
		return (TRUE);
}













// void	process(void *forks)
// {
	
// }

// int	main(int ac, char **av)
// {
// 	pthread_t	thread[ft_atoi(av[1])];
// 	pthread_mutex_t	forks[ft_atoi(av[1])];
// 	int			i;

// 	i = 0;
// 	if (ac != 5 || ac != 6)
// 		return (0);
// 	while (i < ft_atoi(av[1]))
// 	{
// 		pthread_create(thread[i], NULL, process, &forks);
// 		i++;
// 	}

// }