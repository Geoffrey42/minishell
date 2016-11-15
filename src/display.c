/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:58:29 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 13:38:57 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(void)
{
	ft_putstr("$> ");
}

void	print_data(t_shell *data)
{
	ft_putstr(data->var_name);
	ft_putchar(' ');
	ft_putendl(data->var_content);
}

void	print_list(t_list *list)
{
	t_shell		*data;

	data = NULL;
	ft_putendl("---------");
	while (list)
	{
		data = (t_shell *)list->content;
		print_data(data);
		list = list->next;
	}
	ft_putendl("---------");
}
