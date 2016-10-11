/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:09:45 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 02:02:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_access(char *file_name, char *full_path, char *command)
{
	if (!(ft_strcmp(file_name, command)))
	{
		if (access(full_path, X_OK) != -1)
			return (0);
		else 
			print_permission_denied(command);
	}
	return (1);
}

int		command_is_find(char *file_path, char *command, char *dir)
{
	DIR				*dirp;
	struct dirent	*content;

	if (command == NULL)
		return (1);
	if (!(dirp = opendir(dir)))
		return (1);
	while ((content = readdir(dirp)))
	{
		if (!(check_access(content->d_name, file_path, command)))
		{
			closedir(dirp);
			return (0);
		}
	}
	closedir(dirp);
	return (1);
}

char	*get_command(char *command, char **directories)
{
	char	*file_path;
	int		i;

	i = 0;
	while (directories[i])
	{
		file_path = create_pathname(directories[i], command);
		if (!(command_is_find(file_path, command, directories[i])))
			return (file_path);
		free(file_path);
		i++;
	}
	print_command_not_found(command);
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
