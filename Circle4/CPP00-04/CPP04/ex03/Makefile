# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 12:40:48 by jramos-a          #+#    #+#              #
#    Updated: 2025/07/16 14:11:53 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Materia
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
OBJS = $(SRCS:.cpp=.o)

SRCS = main.cpp			\
	AMateria.cpp		\
	MateriaSource.cpp	\
	Cure.cpp			\
	Ice.cpp				\
	ICharacter.cpp		\
	IMateriaSource.cpp	\
	Character.cpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
