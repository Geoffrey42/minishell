/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_test_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:31:07 by ggane             #+#    #+#             */
/*   Updated: 2016/12/14 13:57:33 by ggane            ###   ########.fr       */
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
		ft_putendl(target[i]);
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
	}
	ft_putstr("la liste a ");
	ft_putnbr(i);
	ft_putendl(" elements.");
	ft_putendl("---------");
}
