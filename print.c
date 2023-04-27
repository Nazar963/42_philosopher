/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:12:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/27 19:41:21 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork(t_philo *philo)
{
	printf("%lld %d has taken a fork\n", fetch_time(), philo->pos);
}

void	print_eating(t_philo *philo)
{
	printf("%lld %d is eating\n", fetch_time(), philo->pos);
}

void	print_sleeping(t_philo *philo)
{
	printf("%lld %d is sleeping\n", fetch_time(), philo->pos);
}

void	print_thinking(t_philo *philo)
{
	printf("%lld %d is thinking\n", fetch_time(), philo->pos);
}
void	print_died(t_philo *philo)
{
	printf("%lld %d died\n", fetch_time(), philo->pos);
}