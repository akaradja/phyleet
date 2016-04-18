#ifndef __FILLIT__
#define __FILLIT__

typedef	struct	s_point
{
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;
}		t_point;

typedef	struct	s_tetri
{
	char	**motif;
	int	lon;
	int	hau;
}		t_tetri;

void	crop(char *buf, t_point *ref);
int	isvalid(char *s, int n);
int	reallyvalid(char *s);
t_list	*get_list(int fd);
t_tetri	*get_tetri(char *buf, char c);
#endif
