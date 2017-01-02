# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 14:17:35 by bduron            #+#    #+#              #
#*   Updated: 2016/12/27 15:23:15 by bduron           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXE= ft_printf
NAME= libftprintf.a
SRC= srcs/*.c
OBJ= *.o
HEADER= includes
FLAGS= -w -g  #-Wall -Wextra -Werror
#FLAGS= -g -fsanitize=address -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I $(HEADER) -c $(SRC) 
	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)
	@echo "Compiling libftprintf.a... OK"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

