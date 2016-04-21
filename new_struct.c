#include "fillit.h"
#include "libft/libft.h"

char    *copy(char *dst, const char *src, size_t n, char c)
{
	size_t  i;

	i = 0;
	while (i < n && src[i])
	{
		if (src[i] == '#')
			dst[i] = c;
		else
                	dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}


void	add_tetri(t_tetri **alst, t_tetri *new)
{
	t_tetri	*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_tetri	*new_tetri(t_tetri *content)
{
	t_tetri *new;

	if (!(new = (t_tetri*)malloc(sizeof(content))))
		return (NULL);
	else
	{
		new->motif = (char**)malloc(sizeof(content->motif));
		new->motif = content->motif;
		new->lon = content->lon;
		new->hau = content->hau;
	}
	new->next = NULL;
	return (new);
}
