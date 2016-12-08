/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:46:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/08 18:34:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_extern_commands(char *args)
{
	return (0);
}

int		check_builtins(char *args)
{
	int			i;

	i = 0;
	builtins = create_builtins_array();
	while (builtins[i])
	{
		if (!(ft_strcmp(args, builtins[i])))
		{
			erase_char_array(&builtins);
			return (1);
		}
		i++;
	}
	erase_char_array(&builtins);
	return (0);
}

int		check_executable(char *args)
{
	if (check_builtins(args) || check_extern_commands(args))
		return (1);
	return (0);
}

int		check_env_errors(t_data *data)
{
	int		i;

	i = 1;
	while (data->args[i])
	{
		if (check_dash_or_equal(data->args[i]) ||
			check_executable(data->args[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
