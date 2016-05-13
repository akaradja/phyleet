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

char    **newmap(int size)
{
        int     i;
        char    **new;

        i = 0;
        new = ft_memalloc(sizeof(char*) * size);
        while (i < size)
        {
                new[i] = ft_strnew(size);
                ft_memset(new[i], '.', size);
                i++;
        }
        new[i] = NULL;
        return (new);
}
