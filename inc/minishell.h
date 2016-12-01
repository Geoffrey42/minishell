/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:40:09 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 16:03:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"

# define BUILTINS &ft_cd, &ft_echo, &ft_exit, &ft_env, &ft_setenv, &ft_unsetenv

typedef struct		s_data
{
	char			*var_name;
	char			*var_content;
	char			**args;
	struct s_data	*next;
}					t_data;

/*
** ft_cd.c
*/

int					ft_cd(t_data *data);

/*
** ft_echo.c
*/

int					ft_echo(t_data *data);

/*
** ft_exit.c
*/

int					ft_exit(t_data *data);

/*
** ft_env.c
*/

int					ft_env(t_data *data);

/*
** ft_setenv.c
*/

int					ft_setenv(t_data *data);

/*
** ft_unsetenv.c
*/

int					ft_unsetenv(t_data *data);

/*
** minishell.c
*/

char				**create_builtins_array(void);
int					check_if_builtin(t_data *data);
int					minishell(t_data *data);

/*
** list_functions.c
*/

void				list_push_back(t_data **list, t_data *new);
t_data				*create_elem(void);
void				delete_list(t_data **list);

/*
** extern_command.c
*/

int					execute_extern_commands(t_data *data);
int					try_to_execute_command_directly(t_data *data);
int					search_command_in_path(t_data *data, char *path);
char				*get_path(t_data *data);

/*
** environ.c
*/

int					check_if_environ_is_empty(t_data *data);
t_data				*parse_env(char *env);
t_data				*create_env_list(char **env);

/*
** display.c
*/

void				display_prompt(void);
void				print_char_array(char **target);
void				print_data(t_data *data);
void				print_list(t_data *list);

/*
** delete.c
*/

void				delete_data(t_data **del);

#endif
