# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:03:33 by brandebr          #+#    #+#              #
#    Updated: 2024/03/13 11:52:13 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -I. 

all: $(NAME)

%.o: %.c ft_printf.h Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $^ $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	 /bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

