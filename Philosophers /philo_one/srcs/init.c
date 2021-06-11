#include "filo_one.h"

int	init_philo(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->quantity)
	{
		all->philo[i].count_eat = 0;
		all->philo[i].contr_eat = 0;
		all->philo[i].lfork = i;
		all->philo[i].rfork = i + 1;
		all->philo[i].start = 0;
		if (i == all->quantity - 1)
			all->philo[i].rfork = 0;
	}
	all->mutex_fokrs = malloc(sizeof(pthread_mutex_t) * all->quantity);
	if (!all->mutex_fokrs)
		return (1);
	i = -1;
	while (++i < all->quantity)
	{
		all->status_m = pthread_mutex_init(&all->mutex_fokrs[i], NULL);
		if (all->status_m != 0)
			return (1);
	}
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
	all->status_m = pthread_mutex_init(&all->dop_mutex, NULL);
	if (all->status_m != 0)
		return (1);
	all->status_m = pthread_mutex_init(&all->print_mutex, NULL);
	if (all->status_m != 0)
		return (1);
	if (init_philo(all) == 1)
		return (1);
	return (0);
}
