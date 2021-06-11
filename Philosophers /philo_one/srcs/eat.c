#include "filo_one.h"

void	cikl(t_all *all, int i)
{
	while (1)
	{
		if (all->exit == 1)
			return ;
		pthread_mutex_lock(&all->mutex_fokrs[all->philo[i].lfork]);
		print1(all, i);
		if (all->quantity == 1)
		{
			pthread_mutex_unlock(&all->mutex_fokrs[all->philo[i].lfork]);
			return ;
		}
		pthread_mutex_lock(&all->mutex_fokrs[all->philo[i].rfork]);
		print1(all, i);
		all->philo[i].count_eat++;
		print3(all, i);
		all->philo[i].start = time12();
		dream(time12() + all->time_to_eat);
		pthread_mutex_unlock(&all->mutex_fokrs[all->philo[i].rfork]);
		pthread_mutex_unlock(&all->mutex_fokrs[all->philo[i].lfork]);
		print4(all, i);
		dream(time12() + all->time_to_sleep);
		print5(all, i);
	}
}

void	cikl2(t_all *all, int i)
{
	while (1)
	{
		if (all->exit == 1)
			return ;
		pthread_mutex_lock(&all->mutex_fokrs[all->philo[i].rfork]);
		print1(all, i);
		pthread_mutex_lock(&all->mutex_fokrs[all->philo[i].lfork]);
		print1(all, i);
		all->philo[i].count_eat++;
		print3(all, i);
		all->philo[i].start = time12();
		dream(time12() + all->time_to_eat);
		pthread_mutex_unlock(&all->mutex_fokrs[all->philo[i].lfork]);
		pthread_mutex_unlock(&all->mutex_fokrs[all->philo[i].rfork]);
		print4(all, i);
		dream(time12() + all->time_to_sleep);
		print5(all, i);
	}
}

void	*eat(void *list)
{
	t_all	*all;
	int		i;
	int		j;

	all = (t_all *) list;
	pthread_mutex_lock(&all->dop_mutex);
	i = all->tek;
	all->tek += 1;
	pthread_mutex_unlock(&all->dop_mutex);
	all->time_open = time12();
	j = -1;
	while (++j < all->quantity)
		all->philo[j].start = time12();
	if (i % 2 == 0)
		cikl(all, i);
	else
		cikl2(all, i);
	return (NULL);
}
