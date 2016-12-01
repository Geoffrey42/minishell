/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 14:56:29 by ggane            ###   ########.fr       */
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
			ft_putendl("command is builtin !");
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
	ft_putendl("start minishell()");
	while (1)
	{
		display_prompt();
		get_next_line(0, &line);
		ft_putendl("gnl() ok");
		data->args = ft_strsplit(line, ' ');
		ft_putendl("ft_strsplit() ok");
		ft_strdel(&line);
		ft_putendl("ft_strdel() ok");
		check_if_builtin(data);
		ft_putendl("check_if_builtin() ok");
		erase_char_array(&data->args);
		ft_putendl("erase_char_array() ok");
	}
	ft_putendl("end minishell()");
	return (0);
}
