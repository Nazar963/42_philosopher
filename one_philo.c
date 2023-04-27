/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:59:09 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/27 20:16:53 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->loco->go = fetch_time();
	print_fork(philo);
	while (--philo->n_meals)
	{
		if (fetch_time() == philo->loco->go + philo->loco->t_die)
		{
			print_died(philo);
			break ;
		}
	}
	return (0);
}