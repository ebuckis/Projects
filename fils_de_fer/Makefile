# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/22 11:11:40 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/01/08 17:26:24 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

HEADER = fdf.h

WFLAGS = -Wall -Wextra -Werror

OSXFLAGS = -framework Opengl -framework Appkit

OBJ = $(SRCS:.c=.o)

SRCS = main.c				\
	   ft_lecture.c			\
	   ft_transforme.c		\
	   ft_tracage.c			\
	   ft_event.c			\
	   ft_gestion_coord.c	\
	   ft_image_color.c		\
	   ft_free.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	@cd libft && make re && cd ..
	@cd minilibx_macos && make re && cd ..
	@gcc $(OSXFLAGS) $(OBJ) -o $(NAME) libft/libft.a minilibx_macos/libmlx.a -g

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean clean all

%.o: %.c $(HEADER)
	gcc -c $< -o $@ $(WFLAGS)
