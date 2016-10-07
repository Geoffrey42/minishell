/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:09:45 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 17:52:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		command_is_find(char *command, char *dir)
{
	DIR				*dirp;
	struct dirent	*content;

	if (command == NULL)
	{
		return (1);
	}
	if (!(dirp = opendir(dir)))
	{
		return (1);
	}
	while ((content = readdir(dirp)))
	{
		if (!ft_strcmp(content->d_name, command))
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
	int		i;

	i = 0;
	while (directories[i])
	{
		if (!command_is_find(command, directories[i]))
		{
			return (create_pathname(directories[i], command));
		}
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
