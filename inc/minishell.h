/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:40:09 by ggane             #+#    #+#             */
/*   Updated: 2016/12/07 15:31:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>

# define BUILTINS &ft_cd, &ft_echo, &ft_exit, &ft_env, &ft_setenv, &ft_unsetenv

typedef struct		s_data
{
	char			*var_name;
	char			*var_content;
	char			**args;
	int				ac;
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

char				**get_utility(char **args);
void				get_args(t_data **new_env, t_data *data);
void				modify_temporary_env(t_data *data);
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
** function_pointers.c
*/

int					check_dash_equals(char **args, int i);
int					check_dash_only(char **args, int i);

/*
** merge_sort.c
*/

t_data				*merge_lists(t_data *a, t_data *b);
void				partition(t_data *head, t_data **front, t_data **back);
void				merge_sort(t_data **source);

/*
** minishell.c
*/

char				**create_builtins_array(void);
int					check_if_builtin(t_data *data);
int					args_number(char **args);
int					minishell(t_data *data);

/*
** list_functions.c
*/

void				list_push_back(t_data **list, t_data *new);
t_data				*create_elem(void);
t_data				*create_env_list(char **env);
size_t				list_size(t_data *data);

/*
** extern_command.c
*/

int					execute_extern_commands(t_data *data);
int					try_to_execute_command_directly(t_data *data);
int					search_command_in_path(t_data *data, char *path);

/*
** path.c
*/

int					check_permission(char *file_name,
					char *full_path, char *command);
int					command_is_find(char *file_path, char *command, char *dir);
char				*get_command(char *command, char **directories);
char				*get_path(t_data *data);

/*
** process.c
*/

int					wait_child_process(pid_t child);
void				execute_file(t_data *data, char *file);
int					create_and_execute_new_process(char *file, t_data *data);

/*
** create_environ.c
*/

int					check_if_environ_is_empty(t_data *data);
t_data				*parse_env(char *env);
char				*join_variables(t_data *data, char *env);
void				copy_each_cell(t_data *data, char **env);
char				**create_env_array(t_data *data);

/*
** modify_environ.c
*/

void				add_new_var(t_data **modifications, t_data **new);
void				modify_existing_var(t_data **modifications, t_data **new);
void				modify_specific_variables(t_data **new,
					t_data **modifications);
t_data				*get_modifications(char **env_args);
t_data				*copy_data(t_data *data);
t_data				*copy_env(t_data *data);
t_data				*create_modified_env(t_data *data);

/*
** display.c
*/

void				display_prompt(void);
void				display_env_variables(t_data *data);
void				display_env_list(t_data *data);

/*
** display_test_functions.c
*/

void				print_char_array(char **target);
void				print_data(t_data *data);
void				print_list(t_data *list);

/*
** display_errors.c
*/

void				print_invalid_identifier(char *invalid, char *builtin);
void				print_oldpwd_not_set(void);
void				print_permission_denied(char *source, char *target);
int					print_command_not_found(char *source, char *target);
void				print_no_such_file_or_dir(char *source, char *target);

/*
** delete.c
*/

void				delete_data(t_data **del);
void				delete_this_cell(t_data **list);
void				delete_list(t_data **list);

#endif
