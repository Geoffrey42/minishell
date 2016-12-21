/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:46:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/21 11:26:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_extern_commands(t_data *data, char *args)
{
	char	**directories;
	char	*path;
	char	*command;
	int		status;

	path = NULL;
	status = 0;
	command = NULL;
	if (!check_if_environ_is_empty(data))
		path = get_path(data);
	directories = ft_strsplit(path, ':');
	if (ft_strchr(args, '/') && access(args, F_OK))
		status = 1;
	else if (ft_strchr(args, '/') && !access(args, F_OK))
		status = 1;
	else if (!ft_strchr(args, '/') &&
			(command = get_command(args, directories)))
		status = 1;
	ft_strdel(&path);
	ft_strdel(&command);
	erase_char_array(&directories);
	return (status);
}

static int		check_builtins(char *args)
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

static int		check_executable(t_data *data, char *args)
{
	if (!check_builtins(args))
		return (0);
	else if (check_extern_commands(data, args))
		return (0);
	return (1);
}

static int		check_each_args(t_data *data, char *args)
{
	if (args[0] != '-' && !ft_strchr(args, '='))
	{
		if (!check_executable(data, args))
			return (1);
		else
		{
			ft_putendl(args);
			ft_putendl_fd("error", 2);
			return (0);
		}
	}
	else if (args[0] == '-' && ft_strcmp(args, "-i"))
	{
		print_illegal_option("env", args[1]);
		return (0);
	}
	return (2);
}

int		check_env_errors(t_data *data)
{
	int		i;
	int		ret;

	i = 1;
	ret = -1;
	while (data->args[i])
	{
		if (!(ret = check_each_args(data, data->args[i])))
			return (0);
		else if (ret == 1)
			break ;
		i++;
	}
	return (1);
}
