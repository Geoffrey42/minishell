/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:43:23 by ggane             #+#    #+#             */
/*   Updated: 2016/12/27 15:25:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		execute_extern_commands(t_data *data)
{
	char	*path;

	path = NULL;
	if (!check_if_environ_is_empty(data))
		path = get_path(data);
	if (ft_strchr(data->args[0], '/'))
		try_to_execute_command_directly(data);
	else
		search_command_in_path(data, path);
	ft_strdel(&path);
	return (0);
}

int		try_to_execute_command_directly(t_data *data)
{
	if (!(access(data->args[0], F_OK)) && !(access(data->args[0], X_OK)))
		create_and_execute_new_process(data->args[0], data);
	else if (!(access(data->args[0], F_OK)) && access(data->args[0], X_OK))
		print_permission_denied("minishell", data->args[0]);
	else if (access(data->args[0], F_OK))
		print_no_such_file_or_dir("minishell", data->args[0]);
	return (0);
}

int		search_command_in_path(t_data *data, char *path)
{
	char	**directories;
	char	*path_command;

	directories = NULL;
	path_command = NULL;
	if (!path)
		return (print_command_not_found("minishell", data->args[0]));
	directories = ft_strsplit(path, ':');
	if (!(path_command = get_command(data->args[0], directories)))
	{
		ft_strdel(&path_command);
		erase_char_array(directories);
		return (1);
	}
	if (create_and_execute_new_process(path_command, data))
	{
		ft_strdel(&path_command);
		erase_char_array(directories);
		return (1);
	}
	ft_strdel(&path_command);
	erase_char_array(directories);
	return (0);
}
