#include "filo_two.h"

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
	sem_wait(all->print_sem);
	if (all->exit == 1 || all->p == 1)
	{
		sem_post(all->print_sem);
		return ;
	}	
	printf("\x1b[36m""%d\t\x1b[33m""filo %d has taken a fork\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}

void	print3(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1 || all->p == 1)
	{
		sem_post(all->print_sem);
		return ;
	}	
	printf("\x1b[36m""%d\t\x1b[32m""filo %d is eating\n", \
	(int)(time12() - all->time_open), i + 1);
	if (all->coint_eat > 0)
		poel(all);
	sem_post(all->print_sem);
}

void	print4(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1 || all->p == 1)
	{
		sem_post(all->print_sem);
		return ;
	}
	printf("\x1b[36m""%d\t\x1b[35m""filo %d is sleeping\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}

void	print5(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1 || all->p == 1)
	{
		sem_post(all->print_sem);
		return ;
	}
	printf("\x1b[36m""%d\t\x1b[34m""filo %d is thinking\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}
