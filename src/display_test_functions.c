/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_test_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:31:07 by ggane             #+#    #+#             */
/*   Updated: 2016/12/16 14:09:12 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_char_array(char **target)
{
	int		i;

	i = 0;
	ft_putendl("*******");
	while (target[i])
	{
		ft_putchar('[');
		ft_putstr(target[i]);
		ft_putendl("]");
		i++;
	}
	ft_putendl("*******");
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
		if (i == 100)
			break ;
	}
	ft_putstr("la liste a ");
	ft_putnbr(i);
	ft_putendl(" elements.");
	ft_putendl("---------");
}
