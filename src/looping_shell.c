/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:58:52 by ggane             #+#    #+#             */
/*   Updated: 2016/10/10 15:37:58 by ggane            ###   ########.fr       */
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

void	execute_file(char **args, char *file)
{
	if (execve(file, args, copy_array_str(environ)) == -1)
	{
		ft_putendl("execve() failed");
		return ;
	}
}

int		fork_process(char *file, char **args)
{
	pid_t	child;

	if ((child = fork()) == 0)
		execute_file(args, file);
	else if (child < 0)
		ft_putendl("fork() failed");
	if (wait_child_process(child))
		return (1);
	return (0);
}

int		extern_commands_launcher(t_shell *info)
{
	char	**directories;
	char	*path;
	char	*command;

	path = get_path(info->env);
	directories = ft_strsplit(path, ':');
	if (!(command = get_command(info->args[0], directories)))
		return (0);
	if (fork_process(command, info->args))
		return (1);
	return (0);
}

int		execute_command(t_shell *info)
{
	int		(*execute_builtin[])(t_shell *) = {&cd, &echo, &exit,
			&env, &setenv, &unsetenv};
	char	**builtins;
	int		i;

	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(info->args[0], builtin[i])))
			return (execute_builtin[i](info));
		i++;
	}
	return (execute_extern_command(info));
}

int		looping_shell(t_shell *info)
{
	int		status;
	char	*line;

	status = 0;
	while (!status)
	{
		display_prompt();
		if (get_next_line(0, &line) == -1)
			return (1);
		if (!line)
			continue ;
		info->args = ft_strsplit(line, ' ');
		status = execute_command(info);
		free(line);
	}
	return (0);
}
