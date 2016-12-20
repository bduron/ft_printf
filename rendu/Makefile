# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 14:17:35 by bduron            #+#    #+#              #
#*   Updated: 2016/12/13 22:07:23 by bduron           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXE= ft_printf
NAME= libftprintf.a
SRC= srcs/*.c
OBJ= *.o
HEADER= includes
FLAGS= -g -w # -Wall -Wextra -Werror
#FLAGS= -g -fsanitize=address -Wall -Wextra -Werror
 

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I $(HEADER) -c $(SRC) 
	@ar rc $(NAME) $(OBJ)
#	@ranlib $(NAME)
	@echo "Compiling libftprintf.a... OK"

exe:
	@gcc -o $(EXE) $(FLAGS) -L. -lftprintf ../other/main.c -I $(HEADER)
	@echo "Compiling ft_printf... OK"

test: 
	@gcc -o $(EXE) $(FLAGS) -L. -lftprintf ../other/main_ftprintf.c -I $(HEADER)
	@echo "Compiling main_test... OK"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

