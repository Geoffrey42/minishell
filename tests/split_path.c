/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:34:30 by ggane             #+#    #+#             */
/*   Updated: 2016/10/06 10:38:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"
#include <stdio.h>

int		command_is_find(char *command, char *dir)
{
	DIR				*dirp;
	struct dirent	*content;

	printf("directory : [%s]\n", dir);
	if (!(dirp = opendir(dir)))
		return (0);
	while ((content = readdir(dirp)))
	{
		printf("content->d_name : [%s]\n", content->d_name);
		if (!ft_strcmp(content->d_name, command))
		{
			printf("*******************************\n");
			printf("content->d_name : [%s]\n", content->d_name);
			printf("command : [%s]\n", command);
			printf("*******************************\n");
			closedir(dirp);
			return (1);
		}
	}
	closedir(dirp);
	return (0);
}

char	*get_command(char *command, char **directories)
{
	int		i;

	i = 0;
	while (directories[i])
	{
		if (command_is_find(command, directories[i]))
			return (create_pathname(directories[i], command));
		i++;
	}
	return (NULL);
}

char	*get_path(char **environ)
{
	int		i;
	char	*path;

	i = 0;
	while (environ[i])
	{
		if (ft_strstr(environ[i], "PATH="))
			return (path = ft_strdup(environ[i] + 5));
		i++;
	}
	return (NULL);
}

char **split_path(char *path)
{
	char	**directories;

	directories = ft_strsplit(path, ':');
	return (directories);
}

int		main(int ac, char **av)
{
	int		i;
	char	*path;
	char	**directories;
	char	*command;

	i = 0;
	//i = print_env(environ, "environ");
	path = get_path(environ);
	printf("path : [%s]\n", path);
	directories = split_path(path);
	print_env(directories, "directories");
	if (ac > 1)
	{
		command = get_command(av[1], directories);
		printf("command : [%s]\n", command);
	}
	else
		printf("awaiting command\n");
	return (0);
}
