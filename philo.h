/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:51:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/25 20:09:21 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

#include <pthread.h> //! for the pthread functions
#include <string.h> //! to be checked
#include <sys/time.h> //! for the usleep function

#define TRUE 1
#define FALSE 0

typedef struct s_philo
{
	int		n_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meals;
	pthread_mutex_t	print;
}		t_philo;

typedef struct s_loco
{
	int			*i;
	long long	*go;
	pthread_t	*philosopher;
	pthread_mutex_t	*forks;
	t_philo	*philo;
}		t_loco;

/* --------------------------------- utils.c -------------------------------- */
int		ft_atoi(const char *nptr);

/* ------------------------------- validate.c ------------------------------- */
int		check_args(int ac, char **av);
void	*initialize(int ac, char **av, t_loco *loco);

/* ------------------------------- one_philo.c ------------------------------ */
void	*one_philo(void *arg);

/* ------------------------------- get_time.c ------------------------------- */
long long	fetch_time(void);

/* --------------------------------- print.c -------------------------------- */
void	print_l_fork(t_loco *loco);
void	print_died(t_loco *loco);

#endif