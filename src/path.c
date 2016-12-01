/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:09:45 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 18:03:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_permission(char *file_name, char *full_path, char *command)
{
	if (!(ft_strcmp(file_name, command)))
	{
		if (access(full_path, X_OK) != -1)
			return (0);
		else
			print_permission_denied("minishell", command);
	}
	return (1);
}

int		command_is_find(char *file_path, char *command, char *dir)
{
	DIR				*dirp;
	struct dirent	*content;

	if (!command || !(dirp = opendir(dir)))
		return (1);
	while ((content = readdir(dirp)))
	{
		if (!(check_permission(content->d_name, file_path, command)))
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
	file_path = NULL;
	while (directories[i])
	{
		file_path = create_pathname(directories[i], command);
		ft_putstr("file_path : ");
		ft_putendl(file_path);
		if (!(command_is_find(file_path, command, directories[i])))
			return (file_path);
		ft_strdel(&file_path);
		i++;
	}
	print_command_not_found("minishell", command);
	return (NULL);
}

char	*get_path(t_data *data)
{
	char	*path;

	while (data)
	{
		if (ft_strstr(data->var_name, "PATH"))
		{
			path = ft_strdup(data->var_content);
			return (path);
		}
		data = data->next;
	}
	return (NULL);
}
