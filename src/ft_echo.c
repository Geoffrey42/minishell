/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:22:32 by ggane             #+#    #+#             */
/*   Updated: 2016/12/15 11:31:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_var(t_data *data, char *arg)
{
	while (data)
	{
		if (!ft_strcmp(arg + 1, data->var_name))
			ft_putstr(data->var_content);
		data = data->next;
	}
}

void	print_message(t_data *data, char *arg)
{
	if (arg[0] != '$')
		ft_putstr(arg);
	else if (arg[0] == '$' && ft_strlen(arg) == 1)
		ft_putstr(arg);
	else if (arg[0] == '$' && ft_strlen(arg) > 1)
		print_env_var(data, arg);
}

int		ft_echo(t_data *data)
{
	int		i;

	i = 1;
	while (data->args[i])
	{
		print_message(data, data->args[i]);
		if (data->args[i])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
