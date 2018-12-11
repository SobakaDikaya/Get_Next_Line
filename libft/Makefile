# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srafe <srafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:47:07 by srafe             #+#    #+#              #
#    Updated: 2018/12/03 15:03:34 by srafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I. -c
FILES = *.c \
		*.h
NAME = libft.a
OBJ	= *.o

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
		gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
