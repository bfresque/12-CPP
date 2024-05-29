NAME	= megaphone

CC		= g++
FLAGS	= -Wall -Wextra -Werror -std=c++98

SRC		= ./megaphone.cpp
RM		= rm -rf

all : $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\033[1;32m[$(NAME)] Make is done\033[0m"

fclean :
	@$(RM) $(NAME)
	@echo "\033[1;33m[$(NAME)] Binary file removed\033[0m"

re : fclean all

.PHONY: all fclean re
