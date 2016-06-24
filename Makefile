# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2016/06/24 18:01:08 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -O2

INCLUDES = ./includes

INCLUDES_LIBFT = ./libft/includes

LIBFT_PATH = ./libft

SRC_NAME =	main.c ft_ant_number.c ft_env_new.c ft_env_del.c ft_graph_new.c \
			ft_graph_del.c ft_head_del.c ft_head_new.c ft_parser.c ft_part_nb.c \
			ft_room_list.c ft_create_new_room.c ft_head_realloc.c ft_command.c \
			ft_check_room_parsing.c ft_room_connect.c ft_room_link.c \
			ft_has_same.c ft_create_link.c ft_graph_realloc.c ft_seek_node.c \
			ft_inv_split.c ft_solver.c ft_graph_seek_name.c ft_graph_seek_end.c \
			ft_strjoin_cat.c ft_disp_path.c ft_error.c ft_read_inputs.c \
			ft_init_lst.c ft_lstread_prompt.c

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =	$(SRC_NAME:.c=.o)

NAME = lem-in

all :	libft $(NAME)

libft :
	make -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lft -I$(INCLUDES) -I$(INCLUDES_LIBFT) -L$(LIBFT_PATH)

$(OBJ) :
	$(CC) -c $(SRC) $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_LIBFT)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all clean fclean re libft
