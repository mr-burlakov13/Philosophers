#include "filo_two.h"

int	contr3(t_all *all, int i)
{
	int	j;
	int	s;

	if (all->philo[i].count_eat >= all->coint_eat)
		all->philo[i].contr_eat = 1;
	j = -1;
	s = 0;
	while (++j < all->quantity)
		s += all->philo[j].contr_eat;
	if (s == all->quantity)
	{
		sem_wait(all->print_sem);
		all->exit = 1;
		return (1);
	}
	return (0);
}

void	contr2(t_all *all)
{
	int	i;
	int	j;
	int	s;

	s = 0;
	while (1)
	{
		i = -1;
		while (++i < all->quantity)
		{
			if (all->philo[i].count_eat >= all->coint_eat)
				all->philo[i].contr_eat = 1;
		}
		j = -1;
		s = 0;
		while (++j < all->quantity)
			s += all->philo[j].contr_eat;
		if (s == all->quantity)
		{
			sem_wait(all->print_sem);
			all->exit = 1;
			return ;
		}
	}
}

void	*control(void *list)
{
	t_all	*all;
	int		i;

	all = (t_all *) list;
	while (1)
	{
		i = -1;
		while (++i < all->quantity)
		{
			if ((int)(time12() - all->philo[i].start) > all->time_to_die)
			{
				sem_wait(all->print_sem);
				all->exit = 1;
				printf("\x1b[36m""%d\t\x1b[31m""filo %d is dead\n""\x1b[0m", \
				(int)(time12() - all->time_open), i + 1);
				return (NULL);
			}
			if (all->coint_eat > 0)
			{
				if (contr3(all, i) == 1)
					return (NULL);
			}
		}	
	}
}
