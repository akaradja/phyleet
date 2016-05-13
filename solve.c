#include "fillit.h"

int	ispossible(char **map, t_tetri *tetri, t_p *p)
{
	int	i;
	int	j;

	i = 0;
	while(i < tetri->lon)
	{
		j = 0;
		while (j < tetri->hau)
		{
			if (ft_isalpha(tetri->motif[j][i]) && map[p->y + j][p->x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place_tetri(map, tetri, p, 0);
	return (1);
}

void	place_tetri(char **map, t_tetri *tetri, t_p *p, char c)
{
	int	i;
	int	j;

	i = 0;
	while(i < tetri->lon)
	{
		j = 0;
		while (j < tetri->hau)
		{
			if (ft_isalpha(tetri->motif[j][i]))
			{
				if (c)
					map[p->y + j][p->x + i] = c;
				else
					map[p->y + j][p->x + i] = tetri->motif[j][i];
			}
			j++;
		}
		i++;
	}
}
		
void	print(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
		
int	algo(char **map, t_tetri *liste, int size)
{
	t_p	*p;

	if (!liste)
		return (1);
	p = ft_memalloc(sizeof(t_p));
	p->y = 0;
	while (p->y <= size - liste->hau)
	{
		p->x = 0;
		while (p->x <= size - liste->lon)
		{
			if (ispossible(map, liste, p))
			{
				if (algo(map, liste->next, size))
					return (1);
				else
					place_tetri(map, liste, p, '.');
			}
			p->x++;
		}
		p->y++;
	}
	return (0);
}

void	solve(t_tetri *liste)
{
	char	**map;
	int	size;

	size = 2;
	map = newmap(size);
	while (!algo(map, liste, size))
	{
		size++;
		map = newmap(size);
	}
	print(map);
}
