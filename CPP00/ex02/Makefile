# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 11:22:59 by bfresque          #+#    #+#              #
#    Updated: 2024/01/31 11:58:57 by bfresque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lost_file

SRC	=	Account.cpp \
		tests.cpp \

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