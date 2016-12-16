/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_setenv_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:00:37 by ggane             #+#    #+#             */
/*   Updated: 2016/12/16 09:18:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_alpha(char *arg)
{
	if (!ft_isalpha(arg[0]))
		return (1);
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
