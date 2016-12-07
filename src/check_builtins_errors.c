/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_errors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 22:10:37 by ggane             #+#    #+#             */
/*   Updated: 2016/12/07 22:59:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		nb_env_var(char **args)
{
	int		limits;

	limits = 1;
	return (limits);
}

int		check_env_errors(t_data *data)
{
	int		i;
	int		limits;

	i = 1;
	limits = nb_env_var(data->args);
	while (i <= limits)
	{
		if (data->args[i][0] == '-')
		{
			print_illegal_option("env", data->args[i][1]);
			return (0);
		}
		if (!ft_strchr(data->args[i], '='))
		{
			print_no_such_file_or_dir("env", data->args[i]);
			return (0);
		}
		i++;
	}
	return (1);
}
