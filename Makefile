# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2016/10/05 19:42:55 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell
SRC= src/delete.c \
	 src/display.c \
	 src/main.c \
	 src/path.c \
	 src/runner.c 
CC= clang
CFLAGS= -Wall -Werror -Wextra
INC= inc/
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

%.o: %.c
		$(CC) $(CFLAGS) $< -c -o $@

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all
