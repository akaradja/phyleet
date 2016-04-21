#include "fillit.h"
#include "libft/libft.h"

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
