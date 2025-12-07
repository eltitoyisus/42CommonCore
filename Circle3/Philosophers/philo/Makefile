# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 09:52:34 by jramos-a          #+#    #+#              #
#    Updated: 2025/04/11 08:06:14 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Werror -Wall -Wextra -pthread
NAME = philo
RM = rm -rf
SRC_DIR = src/

SRC = $(SRC_DIR)philo.c				\
		$(SRC_DIR)base.c			\
		$(SRC_DIR)adv.c				\
		$(SRC_DIR)utils.c			\
		$(SRC_DIR)routine.c			\
		$(SRC_DIR)do_mutex.c		\
		$(SRC_DIR)do_thread.c		\
		$(SRC_DIR)init_routine.c	\
		$(SRC_DIR)parse.c			\
		$(SRC_DIR)prevent.c			\
		$(SRC_DIR)free_philo.c		\
		$(SRC_DIR)fork.c			\
		$(SRC_DIR)monitor.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@$(RM) $(OBJ)

fclean: 
	@$(RM) $(OBJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re
