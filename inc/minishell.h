/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:09:20 by ggane             #+#    #+#             */
/*   Updated: 2016/10/06 10:10:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>

extern char	**environ;

/*
**path.c
*/

char		*search_command(char *program);

/*
**runner.c
*/

int			extern_commands_launcher(char **words);
int			execute_commands(char **words);
void		looping_runner(void);

/*
**display.c
*/

int			display_str(char *var, int i, char *name);
int			print_env(char **env, char *name);
void		display_prompt(void);

/*
**delete.c
*/

void		erase_variables(char **words, char *line);

#endif
