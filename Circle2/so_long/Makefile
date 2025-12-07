# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 13:53:41 by jramos-a          #+#    #+#              #
#    Updated: 2025/01/30 13:53:41 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
RM = rm -rf
CC = cc
SRC_DIR = mandatory/src/
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx
MLXFLAGS = -lm -lX11 -lXext

SRCS = $(SRC_DIR)main.c				\
		$(SRC_DIR)movement.c		\
		$(SRC_DIR)map_parse.c		\
		$(SRC_DIR)convert_image.c	\
		$(SRC_DIR)draw_map.c		\
		$(SRC_DIR)end_map.c			\
		$(SRC_DIR)error.c			\
		$(SRC_DIR)generate_game.c	\
		$(SRC_DIR)init_map.c		\
		$(SRC_DIR)keys.c			\
		$(SRC_DIR)validate_name.c	\
		$(SRC_DIR)map_parse2.c		\
		$(SRC_DIR)map_parse3.c		\
		$(SRC_DIR)map_parse4.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

libft/libft.a:
	@$(MAKE) -C libft
minilibx/libmlx.a:
	@$(MAKE) -C minilibx

$(NAME): $(OBJS) libft/libft.a minilibx/libmlx.a
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx/libmlx.a $(MLXFLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) 
	@ cd libft && make clean
	@ cd minilibx && make clean

fclean: clean
	@$(RM) $(NAME)
	@ cd libft && make fclean

re: fclean all
