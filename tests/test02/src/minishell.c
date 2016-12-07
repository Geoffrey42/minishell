/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2016/12/02 16:04:17 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_builtins_array(void)
{
	return (ft_strsplit("cd,echo,exit,env,setenv,unsetenv", ','));
}

int		check_if_builtin(t_data *data)
{
	static int	(*execute_builtin[])(t_data *) = {BUILTINS};
	char		**builtins;
	int			i;

	i = 0;
	if (!data->args[0])
		return (1);
	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(data->args[0], builtins[i])))
		{
			erase_char_array(&builtins);
			return (execute_builtin[i](data));
		}
		i++;
	}
	erase_char_array(&builtins);
	return (execute_extern_commands(data));
}

int		minishell(t_data *data)
{
	char	*line;

	line = NULL;
	while (1)
	{
		display_prompt();
		get_next_line(0, &line);
		data->args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		check_if_builtin(data);
		erase_char_array(&data->args);
	}
	return (0);
}
