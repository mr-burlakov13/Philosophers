#include "filo_one.h"

int	valid(t_all *all, int argc, char **argv)
{
	int	i;
	int	j;

	all->quantity = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	j = 0;
	while (++j <= 4)
	{
		i = -1;
		while (argv[j][++i])
			if (!ft_isdigit(argv[j][i]))
				return (1);
	}
	if (argc == 6)
		all->coint_eat = ft_atoi(argv[5]);
	else
		all->coint_eat = 0;
	if (all->quantity > 200 || all->quantity < 1 || all->time_to_die \
	< 60 || all->time_to_eat < 60 || all->time_to_sleep < 60)
		return (1);
	return (0);
}

int	vali(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 6)
		while (argv[5][++i])
			if (!ft_isdigit(argv[5][i]))
				return (1);
	if (argc == 6)
		if (ft_atoi(argv[5]) == 0)
			return (1);
	return (0);
}
