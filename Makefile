# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2016/12/07 15:29:18 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell
SRC= src/main.c \
	 src/ft_cd.c \
	 src/ft_echo.c \
	 src/ft_exit.c \
	 src/ft_env.c \
	 src/ft_setenv.c \
	 src/ft_unsetenv.c \
	 src/merge_sort.c \
	 src/function_pointers.c \
	 src/delete.c \
	 src/display.c \
	 src/display_test_functions.c \
	 src/display_errors.c \
	 src/create_environ.c \
	 src/modify_environ.c \
	 src/extern_command.c \
	 src/path.c \
	 src/process.c \
	 src/list_functions.c \
	 src/minishell.c
CC= clang
CFLAGS= -Wall -Werror -Wextra -g
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
