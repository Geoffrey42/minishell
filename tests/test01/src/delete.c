/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:05:33 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 15:20:19 by ggane            ###   ########.fr       */
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

void	delete_data(t_data **del)
{
	ft_strdel(&(*del)->var_name);
	ft_strdel(&(*del)->var_content);
	erase_char_array(&(*del)->args);
}

void	delete_info(t_list **info)
{
	t_list	*tmp;
	t_data	*del;

	tmp = *info;
	del = NULL;
	while (tmp)
	{
		del = (t_data *)tmp->content;
		delete_data(&del);
		tmp = tmp->next;
	}
	ft_memdel((void **)info);
}
