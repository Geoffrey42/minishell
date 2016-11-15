/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:40:09 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 10:34:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"

typedef struct	s_shell
{
	char		*var_name;
	char		*var_content;
	char		**args;
}				t_shell;

/*
** minishell.c
*/

int				minishell(t_list *environ);

/*
** environ.c
*/

t_list			*create_env_list(char **env);
void			print_list(t_list *list);

/*
** delete.c
*/

void			delete_environ(void *content, size_t size);

#endif
