# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/10 11:19:54 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/01/31 08:41:58 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

HEADER = fractol.h

WFLAGS = -Wall -Wextra -Werror

OSXFLAGS = -framework Opengl -framework Appkit

OBJ = $(SRCS:.c=.o)

SRCS = main.c				\
	   ft_mandelbrot.c		\
	   ft_julia.c			\
	   bandeau_cmd.c		\
	   bandeau_fract.c		\
	   ft_fill_img.c		\
	   ft_init_zero.c		\
	   ft_mouse_hook.c		\
	   ft_key_event.c		\
	   ft_newton.c			\
	   ft_divise.c			\
	   ft_event.c

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	@cd libft && make re && cd ..
	@cd minilibx_macos && make re && cd ..
	@gcc $(OSXFLAGS) $(OBJ) -o $(NAME) libft/libft.a minilibx_macos/libmlx.a

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean clean all

%.o: %.c $(HEADER)
	gcc -c $< -o $@ $(WFLAGS)
