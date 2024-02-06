NAME	=	Harl2.0

SRC	=	main.cpp \
		Harl.cpp

OBJ	=	$(SRC:.cpp=.o)

CC	=	clang++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

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