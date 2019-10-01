# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 15:03:33 by ndremora          #+#    #+#              #
#    Updated: 2019/01/14 12:11:05 by ndremora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all : $(NAME)

$(NAME) :
	gcc -c -Wall -Wextra -Werror ./ft_*.c -I ./
	ar rc $(NAME) ft_*.o
	ranlib $(NAME)

clean :
	/bin/rm -f ft_*.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re