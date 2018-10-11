# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/06 14:53:11 by kcabus       #+#   ##    ##    #+#        #
#    Updated: 2018/06/05 11:39:27 by kcabus      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = minishell

WFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LIB_PATH = ./libft/


SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = -I $(INC_PATH) -I $(LIB_PATH)

OBJ_NAME = $(N_SRCS:.c=.o)

N_SRCS =	main.c				\
			ft_parse.c			\
			ft_save_env.c		\
			ft_lancement.c		\
			ft_env.c			\
			ft_setenv.c			\
			ft_unsetenv.c		\
			ft_echo.c			\
			ft_cd.c				\
			ft_change_pwd.c		\
			ft_search_env.c		\
			ft_transforme_arg.c	\
			ft_each_path.c		\
			ft_commande.c		\
			ft_verif_path.c		\
			ft_print_env.c		\
			ft_free.c

all : $(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIB_PATH)
			@gcc $(WFLAGS) $(OBJ) $(INC) -L$(LIB_PATH) -lft -o $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@gcc -c $(FLAGS) $(INC) -o $@ $<
	
clean :
		@make -C $(LIB_PATH) clean
		@rm -rf $(OBJ_PATH)

fclean : 	clean
			@make -C $(LIB_PATH) fclean
			@rm -rf $(NAME)

re : fclean clean all
