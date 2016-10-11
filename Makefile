# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2016/10/11 01:38:48 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell
SRC= src/delete.c \
	 src/display.c \
	 src/display_errors.c \
	 src/path.c \
	 src/builtins.c \
	 src/cd.c \
	 src/echo.c \
	 src/exit.c \
	 src/env.c \
	 src/setenv.c \
	 src/unsetenv.c \
	 src/process.c \
	 src/search_commands.c \
	 src/looping_shell.c \
	 src/main.c
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
