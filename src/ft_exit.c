/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:19:05 by ggane             #+#    #+#             */
/*   Updated: 2016/12/28 09:35:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_num(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int				ft_exit(t_data **data)
{
	int		status;

	status = 0;
	ft_putendl((*data)->args[0]);
	if ((*data)->ac == 1)
	{
		delete_list(data);
		exit(EXIT_SUCCESS);
	}
	else if ((*data)->ac == 2)
	{
		if (is_num((*data)->args[1]))
		{
			status = ft_atoi((*data)->args[1]);
			exit(status);
		}
		else
		{
			print_numeric_arg_required((*data)->args[0], (*data)->args[1]);
			exit(255);
		}
	}
	else if ((*data)->ac > 2)
		print_too_many_args((*data)->args[0]);
	return (0);
}
