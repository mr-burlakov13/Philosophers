#ifndef FILO_TWO_H
# define FILO_TWO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int				exit;
	int				start_eat;
	int				count_eat;
	int				contr_eat;
	int				status_eat;
	int				time_to_die;
	double			start;
	double			time_open;
	pid_t			pid;
}					t_philo;

typedef struct s_all
{
	int				id;
	int				nb;
	int				tek;
	int				sum;
	int				exit;
	int				status;
	int				quantity;
	int				status_m;
	int				coint_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	double			time_open;
	sem_t			*sem;
	sem_t			*print_sem;
	sem_t			*umer_sem;
	sem_t			*forks_sem;
	t_philo			*philo;
	pthread_t		*treads;
	pthread_t		*eating;
	pthread_t		*dead;
	pthread_t		time_eat;
}					t_all;

int		ft_isdigit(int ch);
int		ft_error(char *str);
int		init_philo(t_all *all);
int		ft_atoi(const char *str);
int		vali(int argc, char **argv);
int		valid(t_all *all, int argc, char **argv);
int		init_all(t_all *all, int argc, char **argv);
void	dream(double j);
void	*eat(void *list, int i);
void	*control(void *list);
void	count_eat(t_all *all);
void	cikl(t_all *all, int i);
void	cikl2(t_all *all, int i);
void	print1(t_all *all, int i);
void	print3(t_all *all, int i);
void	print4(t_all *all, int i);
void	print5(t_all *all, int i);
double	time12(void);
size_t	ft_strlen(const char *s);

#endif