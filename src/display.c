/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:58:29 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 11:32:50 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_prompt(void)
{
	ft_putstr("$> ");
}

void	print_data(t_data *data)
{
	ft_putstr("data : [");
	ft_putstr(data->var_name);
	ft_putstr("] [");
	ft_putstr(data->var_content);
	ft_putendl("]");
}

void	print_list(t_data *list)
{
	int		i;

	i = 0;
	ft_putendl("---------");
	while (list)
	{
		print_data(list);
		i++;
		list = list->next;
	}
	ft_putstr("la liste a ");
	ft_putnbr(i);
	ft_putendl(" elements.");
	ft_putendl("---------");
}
