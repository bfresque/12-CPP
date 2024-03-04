NAME	=	DiamondTrap

SRC	=	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \

OBJ	=	$(SRC:.cpp=.o)

CC	=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

%.o: %.cpp
		$(CC) ${CFLAGS} -o $@ -c $<

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re : fclean	all

.PHONY : all clean fclean re