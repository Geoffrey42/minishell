/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:58:29 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 15:20:47 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(void)
{
	ft_putstr("$> ");
}

void	print_data(t_data *data)
{
	ft_putstr(data->var_name);
	ft_putchar(' ');
	ft_putendl(data->var_content);
}

void	print_list(t_list *list)
{
	t_data		*data;
	int			i;

	data = NULL;
	i = 0;
	ft_putendl("---------");
	while (list)
	{
		data = (t_data *)list->content;
		print_data(data);
		i++;
		list = list->next;
	}
	ft_putstr("la liste a ");
	ft_putnbr(i);
	ft_putendl(" elements.");
	ft_putendl("---------");
}
