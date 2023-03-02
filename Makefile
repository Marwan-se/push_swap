# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 15:36:00 by msekhsou          #+#    #+#              #
#    Updated: 2023/03/01 02:15:42 by msekhsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = push_swap.h
PRINTF = ft_printf/libftprintf.a
SRC = instructions.c push_swap_utils.c tools.c main.c

OBJ = $(SRC:.c=.o)
OFILES := $(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC) $(PRINTF)
	$(CC) $(CFLAGS) $(SRC) $(PRINTF) -o $(NAME)

$(PRINTF):
	make -C ft_printf

clean :
	@rm -rf $(OBJ)
	make -C ft_printf clean
fclean : clean
	@rm -rf $(NAME)
	make -C ft_printf fclean

re : fclean all

.PHONY: all fclean clean re 