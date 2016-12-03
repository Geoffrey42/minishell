/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:32:11 by ggane             #+#    #+#             */
/*   Updated: 2016/12/03 07:38:35 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(void)
{
	ft_putstr("$> ");
}

void	display_env_variables(t_data *data)
{
	ft_putstr(data->var_name);
	ft_putchar('=');
	ft_putendl(data->var_content);
}

void	display_env_list(t_data *data)
{
	while (data)
	{
		display_env_variables(data);
		data = data->next;
	}
}
