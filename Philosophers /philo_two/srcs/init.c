#include "filo_two.h"

int	init_philo(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->quantity)
	{
		all->philo[i].start = 0;
		all->philo[i].count_eat = 0;
		all->philo[i].contr_eat = 0;
		all->philo[i].status_eat = 0;
	}
	sem_unlink("fork_sem");
	all->forks_sem = sem_open("fork_sem", O_CREAT, 0777, all->quantity);
	if (all->forks_sem == SEM_FAILED)
		return (1);
	all->nb = all->quantity;
	return (0);
}

int	init_all(t_all *all, int argc, char **argv)
{
	all->status_m = 0;
	if (valid(all, argc, argv) == 1)
		return (1);
	all->philo = NULL;
	all->philo = malloc(sizeof(t_philo) * all->quantity);
	if (!all->philo)
		return (1);
	all->treads = malloc(sizeof(pthread_t) * all->quantity);
	if (!all->treads)
		return (1);
	sem_unlink("edik");
	all->sem = sem_open("edik", O_CREAT, 0777, 1);
	if (all->sem == SEM_FAILED)
		return (1);
	sem_unlink("print_s");
	all->print_sem = sem_open("print_s", O_CREAT, 0777, 1);
	if (all->print_sem == SEM_FAILED)
		return (1);
	if (init_philo(all) == 1)
		return (1);
	return (0);
}
