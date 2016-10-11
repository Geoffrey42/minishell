/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looping_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:58:52 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 02:49:57 by ggane            ###   ########.fr       */
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
	return (0);
}

int		execute_command(t_shell *info)
{
	int			(*execute_builtin[])(t_shell *) = {BUILTINS_FUNCTIONS};
	char		**builtins;
	int			i;

	i = 0;
	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(info->args[0], builtins[i])))
		{
			free(builtins);
			return (execute_builtin[i](info));
		}
		i++;
	}
	free(builtins);
	return (execute_extern_commands(info));
}

int		looping_shell(t_shell *info)
{
	int		status;
	char	*line;

	status = 0;
	while (!status)
	{
		display_prompt();
		if (get_next_line(0, &line) == -1)
			return (1);
		if (!line)
			continue ;
		info->args = ft_strsplit(line, ' ');
		status = execute_command(info);
		free(line);
	}
	return (0);
}
