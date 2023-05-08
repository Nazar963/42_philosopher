/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:26:21 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/08 17:03:36 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	camm_helper(int j, t_loco *loco)
{
	if ((fetch_time() - loco->start_time) >= (loco->p[j].go + loco->t_die))
	{
		if (loco->p[j].n_meals == 0)
			return (0);
		pthread_mutex_unlock(&loco->p[j].mutex_go);
		pthread_mutex_lock(&loco->monitor);
		loco->flag_death = 1;
		printf("%lld %d died\n", fetch_time() - loco->start_time, j);
		pthread_mutex_unlock(&loco->monitor);
		return (0);
	}
	return (1);
}

void	*camm(void	*arg)
{
	t_loco	*loco;
	int		j;

	loco = (t_loco *)arg;
	while (loco->flag_death == 0)
	{
		j = -1;
		while (++j < loco->n_philos)
		{
			pthread_mutex_lock(&loco->p[j].mutex_go);
			if (camm_helper(j, loco) == 0)
				return (NULL);
			pthread_mutex_unlock(&loco->p[j].mutex_go);
		}
	}
	return (NULL);
}
