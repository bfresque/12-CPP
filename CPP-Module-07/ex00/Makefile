NAME	=	whatever

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
RESET=\033[0m

SRC	=	./srcs/main.cpp \

OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

CXX	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM = rm -rf

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: srcs/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)[Make : '$(NAME)' is done]$(RESET)"

clean :
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)[clean : .o of $(NAME) have been deleted]$(RESET)"

fclean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "$(BLUE)[fclean : '$(NAME)' is done]$(RESET)"

re: fclean all

.PHONY: fclean all re

