# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 14:15:17 by jramos-a          #+#    #+#              #
#    Updated: 2025/07/28 14:15:17 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realType
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 --pedantic

SRCS = main.cpp Base.cpp A.cpp B.cpp C.cpp \

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
