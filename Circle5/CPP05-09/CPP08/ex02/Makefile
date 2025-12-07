# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 09:31:02 by jramos-a          #+#    #+#              #
#    Updated: 2025/08/12 09:31:02 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
OBJS = $(SRCS:.cpp=.o)

SRCS = main.cpp \

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $@ $^

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re