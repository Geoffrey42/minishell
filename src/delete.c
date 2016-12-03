/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/03 11:10:45 by ggane            ###   ########.fr       */
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

	if (*list)
	{
		del = *list;
		next = del->next;
		delete_data(&del);
		free(del);
		del = NULL;
		*list = next;
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
			del = tmp;
		}
		*list = NULL;
	}
}
