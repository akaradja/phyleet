#include "libft/libft.h"
#include "fillit.h"

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
