/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:51:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/04/26 22:02:30 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <pthread.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0

#define INTMAX 2147483647

typedef struct s_philo
{
	int			n_philos;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	long int	n_meals;
	pthread_mutex_t	print;
}		t_philo;

typedef struct s_loco
{
	int			i;
	int			pos;
	long long	go;
	pthread_t	*philosopher;
	pthread_mutex_t	*forks;
	t_philo	*philo;
}		t_loco;

/* --------------------------------- utils.c -------------------------------- */
long	ft_atoi(const char *nptr);
long	ft_sp_atoi(int ac, char **av);
int		ft_isdigit(int c);
int		ft_isdigit_new(char *str);

/* ------------------------------- validate.c ------------------------------- */
int		check_args(int ac, char **av);
t_loco	*initialize(int ac, char **av, t_loco *loco);

/* ------------------------------- one_philo.c ------------------------------ */
void	*one_philo(void *arg);

/* ------------------------------- get_time.c ------------------------------- */
long long	fetch_time(void);
void		ft_usleep(useconds_t time);

/* --------------------------------- print.c -------------------------------- */
void	print_fork(t_loco *loco);
void	print_eating(t_loco *loco);
void	print_thinking(t_loco *loco);
void	print_sleeping(t_loco *loco);
void	print_died(t_loco *loco);

/* ------------------------------ many_philos.c ----------------------------- */
void	*multi_philos(void	*arg);

#endif