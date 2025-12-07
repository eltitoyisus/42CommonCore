# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesus <jesus@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 13:26:34 by jesus             #+#    #+#              #
#    Updated: 2024/09/30 13:29:14 by jesus            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar crs
RM = rm -rf

SRC	=	ft_printf.c			\
		ft_str.c			\
		ft_ptr.c			\
		ft_uns.c			\
		ft_hex.c			\
		ft_nbr.c			\
		ft_percent.c		\
		ft_putchar_fd.c		\
		ft_itoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean: 
	@$(RM) $(OBJ)

fclean: 
	@$(RM) $(OBJ) $(NAME)

re: fclean all