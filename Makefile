# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/05 15:27:09 by arusso            #+#    #+#              #
#    Updated: 2018/08/23 16:52:05 by arusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
#-fsanitize=address -g3#
CFLAGS =  -Wall -Werror -Wextra
MLXFLAGS = -framework OpenGL -framework AppKit

SRC_PATH = ./srcs/
SRC_NAME = main.c init_map.c draw.c keys.c
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDES_PATH = ./includes/
INCLUDES_NAME = fdf.h
INCLUDES = $(addprefix $(INCLUDES_PATH), $(INCLUDES_NAME))

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

LIBRARY_PATH = ./mlx/
LIBRARY_NAME = libmlx.a
LIBRARY = $(addprefix $(LIBRARY_PATH), $(LIBRARY_NAME))

OBJ = $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRC) $(HEADER) $(LIBRARY) -o $(NAME)

clean :
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all
