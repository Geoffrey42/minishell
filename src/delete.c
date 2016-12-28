/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/28 09:45:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_data(t_data **del)
{
	ft_strdel(&(*del)->var_name);
	ft_strdel(&(*del)->var_content);
	if ((*del)->args)
		erase_char_array(&(*del)->args);
}

void	delete_this_cell(t_data **list)
{
	t_data	*del;
	t_data	*next;
	t_data	*prev;

	if (*list)
	{
		del = *list;
		next = del->next;
		prev = del->prev;
		delete_data(&del);
		ft_memdel((void **)&del);
		if (prev)
		{
			*list = prev;
			(*list)->next = next;
			if (next)
				next->prev = *list;
		}
		else
		{
			*list = next;
			if (*list)
				(*list)->prev = prev;
		}
	}
}

void	delete_list(t_data **list)
{
	t_data	*del;
	t_data	*tmp;

	if (*list)
	{
		del = *list;
		while (del)
		{
			tmp = del->next;
			delete_data(&del);
			free(del);
			del = NULL;
			del = tmp;
		}
		*list = NULL;
	}
}
