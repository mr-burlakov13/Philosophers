#include "filo_one.h"

int	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}
