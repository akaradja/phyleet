#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

int	isvalid(char *s, int n)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (((i + 1) % 5 == 0) && s[i] != '\n')
			return (0);
		if  ((i + 1) % 5 && s[i] != '#' && s[i] != '.')
			return (0);
		i++;
	}
	if (s[n - 1] != '\n' && n == 21)
		return (0);
	if (!(reallyvalid(s)))
		return (0);
	return (1);
}

int	reallyvalid(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (s[i - 1] == '#' || s[i + 1] == '#' ||
			s[i + 5] == '#' || s[i - 5] == '#')
				count++;
			else
				return (0);
		}
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

void	crop(char *buf, t_point *ref)
{
	int i;

	i = 0;
	ref->min_x = 3;
	ref->min_y = 3;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i / 5 < ref->min_y)
				ref->min_y = i / 5;
			if (i % 5 < ref->min_x)
				ref->min_x = i % 5;
			if (i / 5 > ref->max_y)
				ref->max_y = i / 5;
			if (i % 5 > ref->max_x)
				ref->max_x = i % 5;
		}
		i++;
	}
}
t_tetri		*get_tetri(char *buf, char c)
{
	t_tetri	*new;
	t_point	*ref;
	char	**motif;
	int	i;

	i = 0;
	ref = ft_memalloc(sizeof(t_point));
	crop(buf, ref);
	motif = ft_memalloc(sizeof(char*) * (ref->max_y - ref->min_y + 1));
	while (i < ref->max_y - ref->min_y + 1)
	{
		motif[i] = ft_strnew(ref->max_x - ref->min_x + 1);
		copy(motif[i], buf + (ref->min_x) + (i + ref->min_y) * 5, ref->max_x - ref->min_x + 1, c);
		i++;
	}
	new = ft_memalloc(sizeof(t_tetri));
	new->motif = motif;
	new->lon = ref->max_x - ref->min_x + 1;
	new->hau = ref->max_y - ref->min_y + 1;
	ft_memdel((void**)&ref);
	return (new);
}
t_tetri		*get_list(int fd)
{
	t_tetri	*liste;
	char	*buf;
	char	c;
	int	ret;

	buf = ft_strnew(21);
	ret = 0;
	c = 'A';
	liste = ft_memalloc(sizeof(t_tetri));
	while (ret = read(fd, buf, 21) >= 20)
	{
		if (isvalid(buf, ret))
			add_tetri(&liste, new_tetri(get_tetri(buf, c++)));
	}
	if (ret)
		return (NULL);
	liste = liste->next;
	return (liste);
}
