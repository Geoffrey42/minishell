/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:02:30 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 17:52:20 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		wait_child_process(pid_t child)
{
	int		status;

	status = 0;
	waitpid(child, &status, WUNTRACED);
	if (WIFEXITED(status))
		return (0);
	else
	{
		ft_putendl("child process terminated brutally");
		return (1);
	}
}

void	execute_file(char **words, char *file)
{
	if (execve(file, words, copy_array_str(environ)) == -1)
	{
		ft_putendl("execve() failed");
		return ;
	}
}

int		fork_process(char *file, char **words)
{
	pid_t	child;

	if ((child = fork()) == 0)
		execute_file(words, file);
	else if (child < 0)
		ft_putendl("fork() failed");
	if (wait_child_process(child))
		return (1);
	return (0);
}

int		extern_commands_launcher(char **words)
{
	char	**directories;
	char	*path;
	char	*command;

	path = get_path(environ);
	directories = ft_strsplit(path, ':');
	if (!(command = get_command(words[0], directories)))
		return (2);
	if (fork_process(command, words))
	{
		return (1);
	}
	return (0);
}

int		execute_commands(char **words)
{
	int		status;

	if (!words)
		return (0);
	status = extern_commands_launcher(words);
	if (status == 2)
		status = 0;
	return (status);
}
