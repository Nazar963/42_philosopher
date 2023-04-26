/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:12:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/26 22:03:03 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(t_loco *loco)
{
	printf("%lld %d has taken a fork\n", fetch_time(), loco->pos);
}

void	print_eating(t_loco *loco)
{
	printf("%lld %d is eating\n", fetch_time(), loco->pos);
}

void	print_sleeping(t_loco *loco)
{
	printf("%lld %d is sleeping\n", fetch_time(), loco->pos);
}

void	print_thinking(t_loco *loco)
{
	printf("%lld %d is thinking\n", fetch_time(), loco->pos);
}
void	print_died(t_loco *loco)
{
	printf("%lld %d died\n", fetch_time(), loco->pos);
}