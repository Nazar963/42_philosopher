/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:59:09 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/06 12:25:12 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->go = fetch_time();
	print_fork(philo);
	printf("philo->meals: %ld\n", philo->n_meals);
	while (--philo->n_meals)
	{
		// printf("fetch_time: %lld\nphilo->go: %lld\nphilo->loco->t_die: %d\n the sum: %lld\n", fetch_time(), philo->go, philo->loco->t_die, philo->go + philo->loco->t_die); 
		printf("fetch:%lld\n sum:%lld\n  remain: %lld\n", fetch_time(), philo->go + philo->loco->t_die, (philo->go + philo->loco->t_die) - fetch_time());
		if (fetch_time() == philo->go + philo->loco->t_die)
		{
			print_died(philo);
			break ;
		}
	}
	return (0);
}