/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:46:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/14 10:48:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_extern_commands(t_data *data, char *args)
{
	char	**directories;
	char	*path;
	int		status;

	path = NULL;
	status = 0;
	if (!check_if_environ_is_empty(data))
		path = get_path(data);
	directories = ft_strsplit(path, ':');
	if (ft_strchr(args, '/') && access(args, F_OK))
		status = 1;
	else if (!ft_strchr(args, '/') && get_command(args, directories))
		status = 1;
	ft_strdel(&path);
	erase_char_array(&directories);
	return (status);
}

int		check_builtins(char *args)
{
	char		**builtins;
	int			i;

	i = 0;
	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(args, builtins[i])))
		{
			erase_char_array(&builtins);
			return (0);
		}
		i++;
	}
	erase_char_array(&builtins);
	return (1);
}

int		check_executable(t_data *data, char *args)
{
	if (check_builtins(args))
		return (1);
	if (!check_extern_commands(data, args))
		return (1);
	return (0);
}

int		check_env_errors(t_data *data)
{
	int		i;

	i = 1;
	while (data->args[i])
	{
		if (data->args[i][0] != '-' && !ft_strchr(data->args[i], '='))
		{
			if (!check_executable(data, data->args[i]))
				return (1);
			else
			{
				ft_putendl_fd("error", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
