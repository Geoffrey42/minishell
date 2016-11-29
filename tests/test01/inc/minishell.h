/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:40:09 by ggane             #+#    #+#             */
/*   Updated: 2016/11/29 16:44:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"

# define BUILTINS &ft_cd, &ft_echo, &ft_exit, &ft_env, &ft_setenv, &ft_unsetenv

typedef struct	s_data
{
	char		*var_name;
	char		*var_content;
	char		**args;
}				t_data;

/*
** ft_cd.c
*/

int				ft_cd(t_list *data);

/*
** ft_echo.c
*/

int				ft_echo(t_list *data);

/*
** ft_exit.c
*/

int				ft_exit(t_list *data);

/*
** ft_env.c
*/

int				ft_env(t_list *data);

/*
** ft_setenv.c
*/

int				ft_setenv(t_list *data);

/*
** ft_unsetenv.c
*/

int				ft_unsetenv(t_list *data);

/*
** minishell.c
*/

char			**create_builtins_array(void);
int				check_if_builtin(t_list *data);
int				minishell(t_list *data);

/*
** extern_command.c
*/

int				execute_extern_commands(t_list *data);

/*
** environ.c
*/

t_list			*create_env_list(char **env);

/*
** display.c
*/

void			display_prompt(void);
void			print_data(t_data *data);
void			print_list(t_list *list);

/*
** delete.c
*/

void			delete_environ(void *content, size_t size);
void			delete_data(t_data **del);
void			delete_info(t_list **info);

#endif
