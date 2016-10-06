/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:02:30 by ggane             #+#    #+#             */
/*   Updated: 2016/10/06 13:49:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fork_process(char *file, char **words)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	status = 0;
	if ((pid = fork()) == 0)
	{
		if (execve(file, words, copy_array_str(environ)) == -1)
		{
			ft_putendl("execve() failed");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		ft_putendl("fork() failed");
	else
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	return (1);
}

int		extern_commands_launcher(char **words)
{
	char	**directories;
	char	*path;
	char	*command;

	path = get_path(environ);
	directories = ft_strsplit(path, ':');
	command = get_command(words[0], directories);
	if (fork_process(command, words))
		return (1);
	return (0);
}

int		execute_commands(char **words)
{
	if (!words)
		return (0);
	return (extern_commands_launcher(words));
}

void	looping_runner(void)
{
	char	**words;
	char	*line;
	int		status;

	status = 1;
	while (status)
	{
		display_prompt();
		if ((get_next_line(0, &line) == -1))
		{
			ft_putendl("gnl() failed");
			return ;
		}
		words = ft_strsplit(line, ' ');
		status = execute_commands(words);
		erase_variables(words, line);
	}
}
