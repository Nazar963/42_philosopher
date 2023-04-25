/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:12:25 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/25 19:52:46 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_l_fork(t_loco *loco)
{
	printf("%ld %d has taken a fork", clock(), *loco->i);
}

void	print_died(t_loco *loco)
{
	printf("%ld %d died", clock(), *loco->i);
}