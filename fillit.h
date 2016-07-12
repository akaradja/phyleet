/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaradja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 09:18:04 by akaradja          #+#    #+#             */
/*   Updated: 2016/07/12 09:21:26 by akaradja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H__
# define __FILLIT_H__
# include "libft/libft.h"

typedef	struct		s_point
{
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
}					t_point;

typedef	struct		s_p
{
	int				x;
	int				y;
}					t_p;

typedef	struct		s_tetri
{
	char			**motif;
	int				lon;
	int				hau;
	struct s_tetri	*next;
}					t_tetri;

void				crop(char *buf, t_point *ref);
int					isvalid(char *s, int n);
int					reallyvalid(char *s);
t_tetri				*get_list(int fd);
t_tetri				*get_tetri(char *buf, char c);
void				add_tetri(t_tetri **alst, t_tetri *new);
char				*copy(char *dst, const char *src, size_t n, char c);
char				**newmap(int size);
void				solve(t_tetri *liste);
int					ispossible(char **map, t_tetri *tetri, t_p *p);
void				place_tetri(char **map, t_tetri *tetri, t_p *p, char c);
#endif
