/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2016/12/17 11:16:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_builtins_array(void)
{
	return (ft_strsplit("cd,echo,exit,env,setenv,unsetenv", ','));
}

int		execute_command(t_data *data)
{
	static int	(*execute_builtin[])(t_data *) = {BUILTINS};
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
			erase_char_array(&builtins);
			return (execute_builtin[i](data));
		}
		i++;
	}
	erase_char_array(&builtins);
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

/*void	trim_each_arg(char ***args)
{
	char	**tmp;
	char	*del;
	int		i;

	i = 0;
	del = NULL;
	ft_putendl("start trim_each_arg()");
	tmp = *args;
	while (tmp[i])
	{
		ft_putstr("*args[");
		ft_putnbr(i);
		ft_putstr("] : ");
		ft_putendl(tmp[i]);
		del = tmp[i];
		ft_putendl("del = *args[i]");
		tmp[i] = ft_strtrim(tmp[i]);
		ft_putendl("ft_strtrim() ok");
		ft_strdel(&del);
		ft_putendl("ft_strdel() ok");
	//	ft_putendl("del = *args[i]");
		tmp[i] = ft_strtrim(tmp[i]);
	//	ft_putendl("ft_strtrim() ok");
		ft_strdel(&del);
	//	ft_putendl("ft_strdel() ok");
		i++;
	}
	ft_putendl("tmp after trim");
	print_char_array(tmp);
	ft_putendl("end trim_each_arg()");
}*/

int		minishell(t_data *data)
{
	char	*line;

	line = NULL;
	while (1)
	{
		display_prompt();
		get_next_line(0, &line);
		data->args = ft_strsplit(line, ' ');
//		ft_putendl("args before trim");
//		print_char_array(data->args);
//		ft_putendl("args after trim");
//		print_char_array(data->args);
		data->args = trim_args(data->args);
		data->ac = args_number(data->args);
		ft_strdel(&line);
		//execute_command(data);
		//erase_char_array(&data->args);
	}
	return (0);
}
