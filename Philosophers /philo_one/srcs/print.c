#include "filo_one.h"

void	poel(t_all *all)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < all->quantity)
	{
		if (all->philo[i].count_eat >= all->coint_eat)
		{
			sum += 1;
		}
		else
			return ;
		if (sum == all->quantity)
		{
			all->p = 1;
			return ;
		}
	}
	return ;
}

void	print1(t_all *all, int i)
{	
	pthread_mutex_lock(&all->print_mutex);
	if (all->exit == 1 || all->p == 1)
	{
		pthread_mutex_unlock(&all->print_mutex);
		return ;
	}	
	printf("\x1b[36m""%d\t\x1b[33m""filo %d has taken a fork\n", \
	(int)(time12() - all->time_open), i + 1);
	pthread_mutex_unlock(&all->print_mutex);
}

void	print3(t_all *all, int i)
{	
	pthread_mutex_lock(&all->print_mutex);
	if (all->exit == 1 || all->p == 1)
	{
		pthread_mutex_unlock(&all->print_mutex);
		return ;
	}	
	printf("\x1b[36m""%d\t\x1b[32m""filo %d is eating\n", \
	(int)(time12() - all->time_open), i + 1);
	if (all->coint_eat > 0)
		poel(all);
	pthread_mutex_unlock(&all->print_mutex);
}

void	print4(t_all *all, int i)
{	
	pthread_mutex_lock(&all->print_mutex);
	if (all->exit == 1 || all->p == 1)
	{
		pthread_mutex_unlock(&all->print_mutex);
		return ;
	}
	printf("\x1b[36m""%d\t\x1b[35m""filo %d is sleeping\n", \
	(int)(time12() - all->time_open), i + 1);
	pthread_mutex_unlock(&all->print_mutex);
}

void	print5(t_all *all, int i)
{	
	pthread_mutex_lock(&all->print_mutex);
	if (all->exit == 1 || all->p == 1)
	{
		pthread_mutex_unlock(&all->print_mutex);
		return ;
	}
	printf("\x1b[36m""%d\t\x1b[34m""filo %d is thinking\n", \
	(int)(time12() - all->time_open), i + 1);
	pthread_mutex_unlock(&all->print_mutex);
}
