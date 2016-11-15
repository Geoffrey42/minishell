/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:40:09 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 15:13:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"

typedef struct	s_data
{
	char		*var_name;
	char		*var_content;
	char		**args;
}				t_data;

/*
** minishell.c
*/

int				minishell(t_list *info);

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
