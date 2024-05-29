NAME	=	hordeBrainzzzz

SRC	=	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

OBJ	=	$(SRC:.cpp=.o)

CXX	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
		$(CXX) ${CXXFLAGS} -o $@ -c $<

$(NAME) : $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all : $(NAME)

clean :
		@rm -rf $(OBJ)

fclean : clean
		@rm -rf $(NAME)

re : fclean	all

.PHONY : all clean fclean re