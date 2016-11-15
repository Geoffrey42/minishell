/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:33 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 11:25:47 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_environ(void *content, size_t size)
{
	char	*var;

	var = (char *)content;
	ft_strdel(&var);
	size = 0;
}

void	delete_content_data(t_shell **del)
{
	ft_strdel(del->var_name);
	ft_strdel(del->var_content);
	erase_char_array(del->args);
}

void	delete_data(t_list **data)
{
	t_list	*tmp;
	t_shell	*del;

	tmp = *data;
	del = NULL;
	while (tmp)
	{
		del = tmp->content; 
		delete_content_data(&del);
		tmp = tmp->next;
	}
	ft_memdel(data);
}
