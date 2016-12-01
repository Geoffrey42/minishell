/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extern_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:43:23 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 16:05:50 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		execute_extern_commands(t_data *data)
{
	char	*path;

	path = NULL;
	if (check_if_environ_is_empty(data))
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
	ft_putendl("chemin absolu");
	(void)data;
	return (0);
}

int		search_command_in_path(t_data *data, char *path)
{
	ft_putendl("commande a chercher dans path");
	(void)data;
	(void)path;
	return (0);
}

char	*get_path(t_data *data)
{
	char	*path;

	path = NULL;
	(void)data;
	return (path);
}
