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
	mat = get_list(open(av[1], O_RDONLY));
	if (mat == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	int i = 0;
	while (mat)
	{
		i = 0;
		while(i < mat->hau)
		{
			ft_putstr(mat->motif[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
		mat = mat->next;
	}
	return (0);
}
