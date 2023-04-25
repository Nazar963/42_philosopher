/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:59:09 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/25 19:53:12 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_loco	*loco;

	loco = (t_loco *)arg;
	*loco->go = fetch_time();
	print_l_fork(loco);
	while (loco->philo->n_meals)
	{
		if (fetch_time() == *loco->go + loco->philo->t_die)
			print_died(loco);
		break ;
	}
	exit(1);
}