# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:45:12 by bfresque          #+#    #+#              #
#    Updated: 2024/02/01 10:12:36 by bfresque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

SRC	=	main.cpp \
		PhoneBook.cpp \
		Contact.cpp

OBJ	=	$(SRC:.cpp=.o)

CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

%.o: %.cpp
	$(CC) ${CFLAGS} -o $@ -c $<

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32m[$(NAME)] Make is done\033[0m"

all : $(NAME)

clean :
	@rm -rf $(OBJ)
	@echo "\033[1;33m[$(NAME)] Objects files removed\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\033[1;33m[$(NAME)] Binary file removed\033[0m"

re : fclean	all

.PHONY : all clean fclean re
