/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:09:45 by ggane             #+#    #+#             */
/*   Updated: 2016/10/10 15:53:09 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_access(char *file_path)
{
	if (access(file_path, X_OK))
		return (print_permission_denied(file_path));
	else if (access(file_path, F_OK))
		return (print_command_not_found(file_path));
	return (0);
}
int		command_is_find(char *command, char *dir)
{
	DIR				*dirp;
	struct dirent	*content;

	if (command == NULL)
		return (1);
	if (!(dirp = opendir(dir)))
		return (1);
	while ((content = readdir(dirp)))
	{
		if (!ft_strcmp(content->d_name, command, ))
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
		if (!check_access(file_path))
			return (file_path);
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
