# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2016/10/07 08:46:51 by ggane            ###   ########.fr        #
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
INC= inc
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

%.o: %.c
		$(CC) $(CFLAGS) -I $(INC) $< -c -o $@
swipe:
		@echo "\033[31mSay bye to all .DS_STORE ;)\033[0m"
		@find ./ -name ".DS_Store" -depth -exec rm {} \;
		@echo "\033[31mSay bye to all .swo/swp ;)\033[0m"
		@find ./ -name "*.swp" -depth -exec rm {} \;
		@find ./ -name "*.swo" -depth -exec rm {} \;

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all
