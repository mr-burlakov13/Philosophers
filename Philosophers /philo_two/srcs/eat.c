#include "filo_two.h"

void	kush(t_all *all, int i)
{
	dream(time12() + all->time_to_eat);
	sem_post(all->forks_sem);
	sem_post(all->forks_sem);
	all->nb++;
	all->nb++;
	print4(all, i);
	dream(time12() + all->time_to_sleep);
	print5(all, i);
	all->philo[i].status_eat = 0;
}

void	cikl(t_all *all, int i)
{
	while (1)
	{
		if (all->exit == 1)
			return ;
		if (all->philo[i].status_eat == 0 && all->nb >= 2)
		{
			sem_wait(all->forks_sem);
			all->nb--;
			print1(all, i);
			sem_wait(all->forks_sem);
			all->nb--;
			print1(all, i);
			all->philo[i].status_eat = 1;
			all->philo[i].count_eat++;
			print3(all, i);
			all->philo[i].start = time12();
		}
		if (all->philo[i].status_eat == 1)
			kush(all, i);
	}
}

void	*eat(void *list)
{
	t_all	*all;
	int		i;
	int		j;

	all = (t_all *) list;
	sem_wait(all->sem);
	i = all->tek;
	all->tek += 1;
	sem_post(all->sem);
	all->time_open = time12();
	j = -1;
	while (++j < all->quantity)
		all->philo[j].start = time12();
	cikl(all, i);
	return (NULL);
}
