/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2016/11/29 16:46:40 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_builtins_array(void)
{
	return (ft_strsplit("cd,echo,exit,env,setenv,unsetenv", ','));
}

int		check_if_builtin(t_list *data)
{
	static int	(*execute_builtin[])(t_list *) = {BUILTINS};
	char		**builtins;
	int			i;
	t_data		*tmp;

	i = 0;
	builtins = create_builtins_array();
	tmp = (t_data *)data->content;
	while (builtins[i])
	{
		if (!(ft_strcmp(tmp->args[0], builtins[i])))
		{
			erase_char_array(&builtins);
			return (execute_builtin[i](data));
		}
		i++;
	}
	erase_char_array(&builtins);
	i = execute_extern_commands(data);
	return (execute_extern_commands(data));
}

int		minishell(t_list *data)
{
	char	*line;
	t_data		*tmp;

	line = NULL;
	tmp = (t_data *)data->content;
	while (1)
	{
		display_prompt();
		get_next_line(0, &line);
		tmp->args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		check_if_builtin(data);
		erase_char_array(&tmp->args);
	}
	return (0);
}
