/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_setenv_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:00:37 by ggane             #+#    #+#             */
/*   Updated: 2016/12/15 14:50:59 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_alpha(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isalpha(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int		check_setenv_errors(t_data *data)
{
	int		i;

	i = 0;
	while (data->args[i])
	{
		if (check_alpha(data->args[i]))
		{
			print_invalid_identifier(data->args[1], data->args[0]);
			return (0);
		}
		i++;
	}
	return (1);
}
