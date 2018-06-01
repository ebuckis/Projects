# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcabus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:05:49 by kcabus            #+#    #+#              #
#    Updated: 2017/11/08 12:31:09 by kcabus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

DIR = ./srcs

FCT = ft_putchar.c		\
	  ft_putstr.c		\
	  ft_strcmp.c		\
	  ft_strlen.c		\
	  ft_swap.c

BIN = ft_putchar.o		\
	  ft_putstr.o		\
	  ft_strcmp.o		\
	  ft_strlen.o		\
	  ft_swap.o

P_C = $(addprefix $(DIR)/,$(FCT))

all : $(NAME)

$(NAME): 
	gcc -c $(FLAG) $(P_C)
	ar rc $(NAME) $(BIN)

re : fclean all

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(BIN)
