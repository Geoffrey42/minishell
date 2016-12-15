/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_setenv_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:00:37 by ggane             #+#    #+#             */
/*   Updated: 2016/12/15 13:28:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_alpha(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
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
			return (1);
		i++;
	}
	return (0);
}
