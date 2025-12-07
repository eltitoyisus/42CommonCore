# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 11:47:28 by marvin            #+#    #+#              #
#    Updated: 2024/11/21 11:47:28 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm -rf

SRC = push_swap.c			\
		operands.c			\
		atoi.c				\
		ft_atoll.c			\
		is_push.c			\
		is_swap.c			\
		is_rotate.c			\
		is_reverse.c		\
		error.c				\
		error2.c			\
		moves.c				\
		moves2.c			\
		is_digit.c			\
		ft_lstsize.c		\
		ft_lstnew.c			\
		ft_lstaddback.c		\
		ft_split.c			\
		ft_strlcpy.c		\
		ft_lstlast.c		\
		ft_lstclear.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)

	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	@$(RM) $(OBJ)


fclean: 
	@$(RM) $(OBJ) $(NAME)

re: fclean all
