# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaradja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 23:23:57 by akaradja          #+#    #+#              #
#    Updated: 2016/02/15 00:28:22 by akaradja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc  *.c -I . -o $(NAME) -L libft/ -lft

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all
