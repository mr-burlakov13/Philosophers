#include "filo_two.h"

void	dream(double j)
{
	int	i;

	i = -1;
	while (time12() < j)
	{
		usleep(100);
	}
}

int	creat_pthread(t_all *all)
{
	int	i;

	i = -1;
	all->tek = 0;
	while (++i < all->quantity)
	{
		all->status = pthread_create(&all->treads[i], NULL, eat, all);
		if (all->status == -1)
			return (1);
	}
	all->status = pthread_create(&all->time_eat, NULL, control, all);
	if (all->status == -1)
		return (1);
	pthread_join(all->time_eat, NULL);
	sem_post(all->print_sem);
	i = -1;
	while (++i < all->quantity)
		pthread_join(all->treads[i], NULL);
	if (all->exit == 1)
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 6 && argc != 5)
		return (ft_error("\x1b[31m""bad_argument\n"));
	all.exit = 0;
	all.p = 0;
	if (vali(argc, argv) == 1)
		return (0);
	if (init_all(&all, argc, argv) == 1)
		return (ft_error("fatal_error\n"));
	if (creat_pthread(&all) == 1)
		return (ft_error("fatal_error\n"));
	sem_unlink("edik");
	sem_unlink("print_s");
	sem_unlink("fork_sem");
	return (0);
}
