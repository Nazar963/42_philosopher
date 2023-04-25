/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:51:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/17 20:43:57 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <pthread.h> //! for the pthread functions
#include <string.h> //! to be checked
#include <sys/time.h> //! for the usleep function

#define TRUE 1
#define FALSE 0

typedef struct s_loco
{
	int		i;
	size_t	start;
	int		dead;
	int		philos;
	int		die;
	int		eat;
	int		sleep;
	int		eat_times;
	pthread_t	philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}		t_loco;

typedef struct s_nabo
{
	t_loco	*loco;
	int		id;
	int		n_eat;
	int		last_meal;
	pthread_t	*philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*order;
}		t_nabo;

/* --------------------------------- utils.c -------------------------------- */
int		ft_atoi(const char *nptr);

/* ------------------------------- validate.c ------------------------------- */
int		check_args(int ac, char **av);

#endif