/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:32:11 by ggane             #+#    #+#             */
/*   Updated: 2016/12/15 14:27:00 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(void)
{
	ft_putstr("$> ");
}

void	display_setenv_variables(t_data *data)
{
	ft_putstr(data->var_name);
	ft_putchar('=');
	if (ft_strlen(data->var_content) != 0)
		ft_putendl(data->var_content);
	else
		ft_putendl("''");
}

void	display_env_variables(t_data *data)
{
	if (ft_strlen(data->var_content) > 0)
	{
		ft_putstr(data->var_name);
		ft_putchar('=');
		ft_putendl(data->var_content);
	}
}

void	display_env_list(t_data *data, void (*display)(t_data *))
{
	while (data)
	{
		display(data);
		data = data->next;
	}
}
