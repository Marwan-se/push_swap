# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 18:51:49 by msekhsou          #+#    #+#              #
#    Updated: 2022/11/12 22:32:40 by msekhsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC =	ft_printf.c\
		ft_putadd.c\
		ft_putchar.c\
		ft_puthexlow.c\
		ft_puthexup.c\
		ft_putnbr.c\
		ft_putnbr_u.c\
		ft_putstr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c ft_printf.h
		$(CC) $(CFLAGS) -o $@ -c $<
		
$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean