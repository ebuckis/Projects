# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcabus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:05:49 by kcabus            #+#    #+#              #
#    Updated: 2017/11/08 16:19:22 by kcabus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc -c $(NAME).c
	gcc $(FLAG) -o $(NAME) $(NAME).o

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(NAME).o
