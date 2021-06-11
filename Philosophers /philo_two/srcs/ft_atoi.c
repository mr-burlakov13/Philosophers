#include "filo_two.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	s;

	s = 0;
	k = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + str[i] - '0';
		i++;
	}
	return (s * k);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int ch)
{
	if (!(ch >= 48 && ch <= 57))
		return (0);
	else
		return (1);
}
