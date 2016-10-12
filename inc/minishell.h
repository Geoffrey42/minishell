/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:09:20 by ggane             #+#    #+#             */
/*   Updated: 2016/10/12 15:10:19 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>

# define OVERWRITE 1
# define DONT_OVERWRITE 0
# define BUILTINS_FUNCTIONS	&ft_cd, &ft_echo, &ft_exit, \
							&ft_env, &ft_setenv, &ft_unsetenv
typedef	struct	s_shell
{
	char		**env;
	char		**args;
}				t_shell;

/*
**builtins.c
*/

char			**create_builtins_array(void);

/*
**cd.c
*/

int				change_directory(char *dir, t_shell *info);
int				check_cd_access(t_shell *info, char *dir);
char			*go_to_previous_dir(t_shell *info);
int				ft_cd(t_shell *info);

/*
**echo.c
*/

int				ft_echo(t_shell *info);

/*
**exit.c
*/

int				ft_exit(t_shell *info);

/*
**env.c
*/

int				ft_env(t_shell *info);

/*
**setenv_basic_func.c
*/

char			*copy_name(char *src, size_t size);
int				variables_cmp(char *to_trim, char *var1);
int				check_variable_existence(char *var, char **env);
int				check_letters(char *str);
int				nb_args(char **args);

/*
**setenv.c
*/

char			**reset_value(char **env, char *var, char *arg);
int				setenv_func(char *arg, char ***env);
int				execute_setenv(t_shell *info);
int				ft_setenv(t_shell *info);

/*
**unsetenv.c
*/

int				ft_unsetenv(t_shell *info);

/*
**path.c
*/

int				check_permission(char *file_name,
					char *full_path, char *command);
int				command_is_find(char *file_path, char *command, char *dir);
char			*get_command(char *command, char **directories);
char			*get_path(char **environ);

/*
**process.c
*/

int				wait_child_process(pid_t child);
void			execute_file(t_shell *info, char *file);
int				create_and_execute_new_process(char *file, t_shell *info);

/*
**search_commands.c
*/

int				try_to_execute_command_directly(t_shell *info);
int				search_command_in_path(t_shell *info, char *path);

/*
**looping_shell.c
*/

int				execute_extern_commands(t_shell *info);
int				execute_commands(t_shell *info);
int				looping_shell(t_shell *info);

/*
**display_errors.c
*/

void			print_invalid_identifier(char *invalid);
void			print_oldpwd_not_set(void);
void			print_permission_denied(char *source, char *target);
int				print_command_not_found(char *source, char *target);
void			print_no_such_file_or_dir(char *source, char *target);

/*
**display.c
*/

void			display_env(char **env);
int				display_str(char *var, int i, char *name);
int				print_env(char **env, char *name);
void			display_prompt(void);

/*
**delete.c
*/

void			erase_variables(char **words, char *line);

#endif
