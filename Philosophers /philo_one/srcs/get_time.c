#include "filo_one.h"

double	time12(void)
{
	double			start;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	start = (tp.tv_sec) * 1000 + (tp.tv_usec) / 1000;
	return (start);
}
