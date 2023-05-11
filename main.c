/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:24:33 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/11 19:15:41 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_one(char **av, t_loco *loco)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_join(loco->phil[i], NULL);
		i++;
	}
	i = 0;
	pthread_mutex_destroy(&loco->print);
	pthread_mutex_destroy(&loco->monitor);
	pthread_mutex_destroy(&loco->p->mutex_go);
	pthread_mutex_destroy(&loco->p->death_duck);
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_destroy(loco->forks);
		i++;
	}
	free(loco->phil);
	free(loco->forks);
	free(loco->p);
	free (loco);
	exit(1);
}

void	free_all_plus(pthread_t com, char **av, t_loco *loco)
{
	int			i;

	if (pthread_join(com, NULL) != 0)
		return ;
	i = -1;
	while (++i < ft_atoi(av[1]))
		pthread_join(loco->phil[i], NULL);
	i = 0;
	pthread_mutex_destroy(&loco->print);
	pthread_mutex_destroy(&loco->monitor);
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_destroy(&loco->p[i].mutex_go);
		pthread_mutex_destroy(&loco->p[i].death_duck);
		pthread_mutex_destroy(&loco->p[i].shit);
		pthread_mutex_destroy(&loco->forks[i]);
		i++;
	}
	free(loco->phil);
	free(loco->forks);
	free(loco->p);
	free(loco);
	exit(1);
}

void	go_for_one(t_loco *loco)
{
	int	i;

	i = 0;
	loco->p[i].loco = loco;
	if (pthread_create(&loco->phil[i], NULL, one, (void *)&loco->p[i]))
		return ;
}

pthread_t	go_for_many(char **av, t_loco *loco)
{
	int			i;
	pthread_t	com;

	i = 0;
	if (pthread_create(&com, NULL, camm, loco) != 0)
		return (0);
	while (i < ft_atoi(av[1]))
	{
		loco->p[i].pos = i;
		if (loco->p[i].pos + 1 == loco->n_philos)
			loco->p[i].next = 0;
		else
			loco->p[i].next = loco->p[i].pos + 1;
		loco->p[i].loco = loco;
		if (pthread_create(&loco->phil[i], 0, multi, (void *)&loco->p[i]))
			return (0);
		i++;
	}
	return (com);
}

int	main(int ac, char **av)
{
	t_loco		*loco;
	pthread_t	com;

	if (!(ac == 5 || ac == 6))
		return (0);
	if (check_args(ac, av) == FALSE)
		return (printf("ERROR INPUT!!!\n"));
	loco = (t_loco *)malloc(sizeof(t_loco));
	if (!loco)
		return (0);
	loco->p = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!loco->p)
		return (0);
	loco->phil = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	if (!loco->phil)
		return (0);
	loco = initialize(ac, av, loco);
	if (ft_atoi(av[1]) == 1)
		go_for_one(loco);
	else
		com = go_for_many(av, loco);
	if (ft_atoi(av[1]) > 1)
		free_all_plus(com, av, loco);
	else
		free_all_one(av, loco);
}
