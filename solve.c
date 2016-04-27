#include "fillit.h"
#include <stdio.h>


char	**newmap(int size)
{
	int	i;
	char	**new;

	i = 0;
	new = ft_memalloc(sizeof(char*) * size);
	while (i < size)
	{
		new[i] = ft_strnew(size);
		ft_memset(new[i], '.', size);
		i++;
	}
	return (new);
}

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

int	ispossible(char **map, char **tetri, int i; int x)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while(tetri[k] && map[i])
	{
		if (isalpha(map[i][l + x]) && isalpha(tetri[k][l]))
			return (0);
		else if (!(tetri[k][l]))
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
	while(tetri[k] && map[i])
	{
		if(map[i][j] == '.' && isalpha(tetri[k][l]))
		{
			map[i][j] = 
	
void	solve(t_tetri *liste)
{
	char	*list;
	int	i;
	int	j;
	char	**map;

	map = newmap(tetri_count(liste));
	list = liste;
	i = 0;
	j = 0;
	while (map[i])
	{
		while (isalpha(map[i][j]) && j <= map->size - list->lon)
			j++;
		if (isalpha(map[i][j]))
		{
			i++;
			j = 0;
		}
		else
		{
			if (ispossible(map, list->motif, i, j);
				place_tetri(map, list->motif, i, j);
		}
	}
}
