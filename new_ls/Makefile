# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/22 11:11:40 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/03/29 16:33:43 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls

HEADER = ft_ls.h

WFLAGS = -Wall -Wextra -Werror -ggdb

OBJ = $(SRCS:.c=.o)

SRCS = main.c					\
	   ft_verif_flag.c			\
	   ft_print_flag_error.c	\
	   ft_verif_arg.c			\
	   ft_save_arg.c			\
	   ft_verif_file.c			\
	   ft_lancement.c			\
	   ft_save_ldir.c			\
	   ft_new_ldir.c			\
	   ft_creat_ld.c			\
	   ft_search_info.c			\
	   ft_int_len.c				\
	   ft_trad_date.c			\
	   ft_recursive.c			\
	   ft_sort_all.c			\
	   ft_cmp_ret.c				\
	   ft_sort_ldir.c			\
	   ft_swap_lst.c			\
	   ft_total_block.c			\
	   ft_print_all.c			\
	   ft_print_oth.c			\
	   ft_free_all.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	@cd libft && make re && make clean && cd ..
	@gcc $(OBJ) -o $(NAME) libft/libft.a

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean clean all

%.o: %.c $(HEADER)
	gcc -c $< -o $@ $(WFLAGS)
