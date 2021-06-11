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
		if (all->philo[i].status_eat == 0 && all->nb >= 0)
		{
			sem_wait(all->forks_sem);
			all->nb--;
			print1(all, i);
			sem_wait(all->forks_sem);
			all->nb--;
			print1(all, i);
			all->philo[i].status_eat = 1;
			print3(all, i);
			all->philo[i].start = time12();
			all->philo[i].count_eat++;
		}
		if (all->philo[i].status_eat == 1)
			kush(all, i);
	}
}

void	*potok(void *list)
{
	int		i;
	t_all	*all;

	all = (t_all *) list;
	i = all->id;
	while (1)
	{
		if ((int)(time12() - all->philo[i].start) > all->philo[i].time_to_die)
		{
			sem_wait(all->print_sem);
			all->exit = 1;
			printf("\x1b[36m""%d\t\x1b[31m""filo %d is dead\n""\x1b[0m", \
			(int)(time12() - all->philo[i].time_open), i + 1);
			sem_post(all->umer_sem);
		}
		if (all->coint_eat > 0)
		{
			if (all->philo[all->quantity - 1].count_eat == all->coint_eat)
				all->sum++;
			if (all->sum == all->coint_eat)
				sem_post(all->umer_sem);
		}
	}
	return (NULL);
}

void	*dead(void *list)
{
	t_all	*all;

	all = (t_all *) list;
	while (1)
	{
		sem_wait(all->umer_sem);
		sem_post(all->umer_sem);
		exit(1);
	}
	return (NULL);
}

void	*eat(void *list, int i)
{
	t_all	*all;

	all = (t_all *) list;
	all->id = i;
	all->time_open = time12();
	all->philo[i].time_open = time12();
	all->philo[i].start = time12();
	all->status = pthread_create(&all->treads[i], NULL, potok, all);
	if (all->status == -1)
	{
		sem_post(all->umer_sem);
		return (NULL);
	}
	all->status = pthread_create(&all->dead[i], NULL, dead, all);
	if (all->status == -1)
	{
		sem_post(all->umer_sem);
		return (NULL);
	}
	cikl(all, i);
	pthread_join(all->treads[i], NULL);
	pthread_join(all->dead[i], NULL);
	return (NULL);
}
