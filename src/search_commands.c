/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 00:55:12 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 02:45:36 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		try_to_execute_command_directly(t_shell *info)
{
	if (!(access(info->args[0], F_OK) && access(info->args[0], X_OK)))
		create_and_execute_new_process(info->args[0], info);
	else if (!(access(info->args[0], F_OK)) && access(info->args[0], X_OK))
		print_permission_denied(info->args[0]);
	else if (access(info->args[0], F_OK))
		print_no_such_file_or_dir(info->args[0]);
	return (0);
}

int		search_command_in_path(t_shell *info, char *path)
{
	char	**directories;
	char	*path_command;

	if (!path)
		return (print_command_not_found(info->args[0]));
	directories = ft_strsplit(path, ':');
	if (!(path_command = get_command(info->args[0], directories)))
		return (1);
	if (create_and_execute_new_process(path_command, info))
		return (1);
	return (0);
}
