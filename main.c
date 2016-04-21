#include "fillit.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_tetri *mat;

	mat = ft_memalloc(sizeof(t_tetri));
	if (ac != 2)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (mat = get_list(open(av[1], O_RDONLY)) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
