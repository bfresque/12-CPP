# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:45:12 by bfresque          #+#    #+#              #
#    Updated: 2024/01/25 12:55:10 by bfresque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRC	=	Main.cpp \
		PhoneBook.cpp \
		Contact.cpp

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
