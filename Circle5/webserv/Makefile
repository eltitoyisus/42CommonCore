CXX       = c++
CXXFLAGS  = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDE)

NAME      = webserv

GREEN   = \033[0;32m
RED     = \033[0;31m
NC      = \033[0m

INCLUDE   = include

SRC       = src/ConfigFile.cpp \
			src/Location.cpp \
			src/paths.cpp \
			src/logging.cpp \
			src/ReadConfig.cpp \
			src/ServerUnit.cpp \
			src/main.cpp \
			src/statusCode.cpp \
			src/utils.cpp \
			src/Request.cpp \
			src/HttpResponse.cpp \
			src/ServerManager.cpp \
			src/Cgi.cpp \

BUILD_DIR = build

OBJ       = $(SRC:src/%.cpp=$(BUILD_DIR)/%.o)

all: $(NAME)

CGI_SCRIPTS = cgi_tester \
              cgi-bin/deleteFile.py \
              cgi-bin/getFile.py \
              cgi-bin/getIndex.py \
              cgi-bin/saveFile.py

$(NAME): $(OBJ)
	@chmod +x $(CGI_SCRIPTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
