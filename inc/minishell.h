/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:09:20 by ggane             #+#    #+#             */
/*   Updated: 2016/10/05 20:03:43 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include "libft.h"

extern char	**environ;

/*
**path.c
*/

char		*read_path(char *program);

/*
**runner.c
*/

int			extern_commands_launcher(char **words);
int			execute_commands(char **words);
void		looping_runner(void);

/*
**display.c
*/

int			display_str(char *var, int i);
int			print_env(char **env);
void		display_prompt(void);

/*
**delete.c
*/

void		erase_variables(char **words, char *line);

#endif
