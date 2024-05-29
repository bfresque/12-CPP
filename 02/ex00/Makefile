NAME	=	Cannon

SRC	=	main.cpp \
		Fixed.cpp \

OBJ	=	$(SRC:.cpp=.o)

CC	=	c++
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