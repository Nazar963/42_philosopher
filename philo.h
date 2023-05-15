/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:51:14 by naal-jen          #+#    #+#             */
/*   Updated: 2023/05/15 10:11:22 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0

# define INTMAX 2147483647

struct	s_loco;

typedef struct s_philo
{
	int				i;
	int				f_f;
	int				s_f;
	int				pos;
	long long		go;
	int				next;
	struct s_loco	*loco;
	pthread_mutex_t	mutex_go;
	long int		n_meals;
}		t_philo;

typedef struct s_loco
{
	long long		start_time;
	int				n_philos;
	int				t_die;
	int				result;
	int				t_eat;
	int				t_sleep;
	int				flag_death;
	pthread_t		*phil;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	monitor;
	t_philo			*p;
}		t_loco;

/* ------------------------------- get_time.c ------------------------------- */
long long	fetch_time(void);
void		ft_usleep(int time);

/* --------------------------------- main.c --------------------------------- */
void		free_all_one(char **av, t_loco *loco);
void		free_all_plus(pthread_t com, char **av, t_loco *loco);
pthread_t	go_for_many(char **av, t_loco *loco);

/* ----------------------------- philos_helper.c ---------------------------- */
int			camm_helper(int j, t_loco *loco);
void		*camm(void	*arg);

/* --------------------------------- utils.c -------------------------------- */
long		ft_atoi(const char *nptr);
long		ft_sp_atoi(int ac, char **av);
int			ft_isdigit(int c);
int			ft_isdigit_new(char *str);

/* ------------------------------- validate.c ------------------------------- */
int			check_args(int ac, char **av);
int			check_values(t_loco *loco);
t_loco		*initialize_helper_1(char **av, t_loco *loco);
t_loco		*initialize_philos(int ac, char **av, int i, t_loco *loco);
t_loco		*initialize(int ac, char **av, t_loco *loco);

/* ------------------------------- one_philo.c ------------------------------ */
void		*one(void *arg);

/* --------------------------------- print.c -------------------------------- */
void		print_fork(t_philo *philo);
void		print_eating(t_philo *philo);
void		print_thinking(t_philo *philo);
void		print_sleeping(t_philo *philo);
void		print_died(t_philo *philo);

/* ------------------------------ many_philos.c ----------------------------- */
void		*multi(void	*arg);

#endif