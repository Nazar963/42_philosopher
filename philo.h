/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:51:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/11 11:28:43 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef struct s_loco
{
	int		philos;
	int		die;
	int		sleep;
	int		eat;
	int		eat_times;
	int		fork_l;
	int		fork_r;
	int		id;
	int		ate_times;
	long long	die_2;
	pthread_t	philo;
	int		n_philo;
	int		philo_no_more;
	long long	what;
	pthread_t	yellow;
	pthread_mutex_t	*forka;
	pthread_mutex_t	sino;
}		t_loco;

/* --------------------------------- utils.c -------------------------------- */
int		ft_atoi(const char *nptr);

#endif