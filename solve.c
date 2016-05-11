#include "fillit.h"
#include <stdio.h>

int	tetri_count(t_tetri *liste)
{
	int	i;
	t_tetri	*list;

	list = liste;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	if (i < 4)
		i = 4;
	return (i);
}

int	ispossible(char **map, char **tetri, int i, int x)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while(tetri[k] && map[i])
	{
		if (isalpha(map[i][l + x]) && isalpha(tetri[k][l]))
			return (0);
		if (isalpha(tetri[k][l]) && map[i][l + x] == 0)
			return (0);
		if (!(tetri[k][l]))
		{
			k++;
			i++;
			l = 0;
		}
		else
			l++;
	}
	if (tetri[k] && !(map[i]))
		return (0);
	return (1);
}

void	place_tetri(char **map, char **tetri, int i, int j)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while(tetri[k] && map[i])
	{
		while (tetri[k][l])
		{
			if (!(isalpha(map[i][l + j])))
				map[i][l + j] = tetri[k][l];
			l++;
		}
		i++;
		k++;
		l = 0;
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
		
void	solve(t_tetri *liste, int size)
{
	t_tetri	*list;
	int	i;
	int	j;
	char	**map;
	int	b;

	map = newmap(size);
	list = liste;
	i = 0;
	j = 0;
	b = 0;
	while (map[i] && list)
	{
		while (j <= size - list->lon)
		{
			if (ispossible(map, list->motif, i, j))
			{
				place_tetri(map, list->motif, i, j);
				list = list->next;
				b = 1;
			}
			if (b)
				break;
			j++;
		}
		if (b)
		{
			i = 0;
			b = 0;
		}
		else
			i++;
		j = 0;
	}
	if (list)
		return (solve(liste, size + 1));
	else
		print(map);
}
