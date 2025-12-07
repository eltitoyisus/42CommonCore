# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 12:40:14 by jramos-a          #+#    #+#              #
#    Updated: 2025/07/23 12:40:14 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serializer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 --pedantic

SRCS = main.cpp Serializer.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
