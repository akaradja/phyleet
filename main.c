#include "fillit.h"
#include <stdio.h>

int	main(int ac, char **av)
{
//	if (ac != 2)
//	{
//		ft_putstr("error");
//		return (1);
//	}
	if (isvalid("..#.\n.###\n....\n.....\n", 21))
		printf("ok\n");
	else
		printf("niktamer\n");
	return (0);
}
