#include "filo_two.h"

void	count_eat(t_all *all)
{
	int	sum;

	sum = 0;
	while (1)
	{
		if (all->philo[all->quantity - 1].count_eat == all->coint_eat)
			sum++;
		if (sum == all->coint_eat)
			sem_post(all->umer_sem);
	}
}

void	print1(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1)
	{
		sem_post(all->print_sem);
		exit(1);
		return ;
	}	
	printf("\x1b[36m""%d\t\x1b[33m""filo %d has taken a fork\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}

void	print3(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1)
	{
		sem_post(all->print_sem);
		exit(1);
		return ;
	}	
	printf("\x1b[36m""%d\t\x1b[32m""filo %d is eating\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}

void	print4(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1)
	{
		sem_post(all->print_sem);
		exit(1);
		return ;
	}
	printf("\x1b[36m""%d\t\x1b[35m""filo %d is sleeping\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}

void	print5(t_all *all, int i)
{	
	sem_wait(all->print_sem);
	if (all->exit == 1)
	{
		sem_wait(all->print_sem);
		exit(1);
		return ;
	}
	printf("\x1b[36m""%d\t\x1b[34m""filo %d is thinking\n", \
	(int)(time12() - all->time_open), i + 1);
	sem_post(all->print_sem);
}
