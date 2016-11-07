/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:58:52 by ggane             #+#    #+#             */
/*   Updated: 2016/11/07 17:31:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		execute_extern_commands(t_shell *info)
{
	char	*path;

	path = NULL;
	if (info->env)
		path = get_path(info->env);
	if (ft_strchr(info->args[0], '/'))
		try_to_execute_command_directly(info);
	else
		search_command_in_path(info, path);
	ft_strdel(&path);
	return (0);
}

int		execute_command(t_shell *info)
{
	static int	(*execute_builtin[])(t_shell *) = {BUILTINS_FUNCTIONS};
	char		**builtins;
	int			i;

	i = 0;
	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(info->args[0], builtins[i])))
		{
			erase_char_array(&builtins);
			return (execute_builtin[i](info));
		}
		i++;
	}
	erase_char_array(&builtins);
	return (execute_extern_commands(info));
}

int		looping_shell(t_shell *info)
{
	int		status;
	char	*line;

	status = 0;
	info->args = NULL;
	line = NULL;
	while (!status)
	{
		display_prompt();
		if (get_next_line(0, &line) == -1)
			return (1);
		if (ft_strlen(line) == 0)
			continue ;
		info->args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		status = execute_command(info);
		erase_char_array((char ***)&info->args);
	}
	ft_strdel(&line);
	return (0);
}
