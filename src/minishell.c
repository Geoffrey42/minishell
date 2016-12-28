/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2016/12/28 10:00:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_builtins_array(void)
{
	return (ft_strsplit("cd,echo,exit,env,setenv,unsetenv", ','));
}

int		execute_command(t_data *data)
{
	static int	(*execute_builtin[])(t_data **) = {BUILTINS};
	char		**builtins;
	int			i;

	i = 0;
	if (!data->args[0])
		return (-1);
	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(data->args[0], builtins[i])))
		{
			erase_char_array(builtins);
			return (execute_builtin[i](&data));
		}
		i++;
	}
	erase_char_array(builtins);
	return (execute_extern_commands(data));
}

int		args_number(char **args)
{
	int		i;

	i = 0;
	if (args)
		while (args[i])
			i++;
	return (i);
}

void	int_handler(int sig)
{
	signal(sig, SIG_IGN);
}

int		minishell(t_data *data)
{
	char	*line;
	char	*epur;

	line = NULL;
	while (1)
	{
		display_prompt();
		signal(SIGINT, int_handler);
		get_next_line(0, &line);
		epur = epur_str(line);
		ft_strdel(&line);
		data->args = ft_strsplit(epur, ' ');
		ft_strdel(&epur);
		data->ac = args_number(data->args);
		execute_command(data);
		erase_char_array(data->args);
	}
	return (0);
}
