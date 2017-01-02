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

RENDU= ../rendu
NAME= ft_printf
SRC= srcs/*.c
OBJ= *.o
HEADER= ../rendu/includes
FLAGS= -w -g  #-Wall -Wextra -Werror
 

all: $(NAME)

$(NAME):
	@make -C $(RENDU)
	@gcc -o $(NAME) $(FLAGS) -L../rendu -lftprintf main.c -I $(HEADER)
	@echo "Compiling ft_printf... OK"

clean:
#	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(RENDU)

re: fclean all

