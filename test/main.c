#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct s_loco;

typedef struct s_philo
{
	int	i;
	struct s_loco *loco;
}	t_philo;

typedef struct s_loco
{
	int		x;
	t_philo		*philo;
	pthread_t	*philosopher;
}	t_loco;

void	*what(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// printf("%d\n", philo->loco->x);
	printf("%d\n", philo->i);
	printf("%d\n", philo->loco->x);
}

int main(void)
{
	t_loco	*loco;

	loco = (t_loco *)malloc(sizeof(t_loco));

	loco->philo = (t_philo *)malloc(sizeof(t_philo) * 2);

	loco->philosopher = (pthread_t *)malloc(sizeof(pthread_t) * 2);

	loco->x = 5;

	loco->philo[0].i = 10;
	loco->philo[0].loco = loco;
	pthread_create(&loco->philosopher[0], NULL, what, (void *)&loco->philo[0]);

	loco->x = 23423;
	loco->philo[1].i = 20;
	loco->philo[1].loco = loco;
	pthread_create(&loco->philosopher[1], NULL, what, (void *)&loco->philo[1]);

	pthread_join(loco->philosopher[0], NULL);
	pthread_join(loco->philosopher[1], NULL);

}
