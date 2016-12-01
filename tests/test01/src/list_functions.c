/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:18:28 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 11:34:14 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_push_back(t_data **list, t_data *new)
{
	t_data	*tmp;

	tmp = NULL;
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_data	*create_elem(void)
{
	t_data	*new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->var_name = NULL;
	new->var_content = NULL;
	new->args = NULL;
	new->next = NULL;
	return (new);
}

void	delete_list(t_data **list)
{
	t_data	*cpy;
	t_data	*temp;

	if (*list)
	{
		cpy = *list;
		while (cpy)
		{
			temp = cpy->next;
			delete_data(&cpy);
			free(cpy);
			cpy = temp;
		}
		*list = NULL;
	}
}
