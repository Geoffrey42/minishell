/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:09:20 by ggane             #+#    #+#             */
/*   Updated: 2016/10/10 14:53:19 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef	struct	s_shell
{
	char		**env;
	char		**args;
}				t_shell;

/*
**path.c
*/

int		command_is_find(char *command, char *dir);
char	*get_command(char *command, char **directories);
char	*get_path(char **environ);

/*
**runner.c
*/

int			wait_child_process(pid_t child);
void		execute_file(char **words, char *file);
int			fork_process(char *file, char **words);
int			extern_commands_launcher(char **words);
int			execute_commands(char **words);

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
