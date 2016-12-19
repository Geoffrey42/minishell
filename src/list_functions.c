/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:18:28 by ggane             #+#    #+#             */
/*   Updated: 2016/12/19 13:52:03 by ggane            ###   ########.fr       */
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
		new->prev = tmp;
	}
}

t_data	*create_elem(void)
{
	t_data	*new;

	if (!(new = (t_data *)ft_memalloc(sizeof(t_data))))
		return (NULL);
	new->var_name = NULL;
	new->var_content = NULL;
	new->args = NULL;
	new->ac = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_data	*create_env_list(char **env)
{
	t_data		*data;
	int			i;

	i = 0;
	data = NULL;
	while (env[i])
		list_push_back(&data, parse_env(env[i++]));
	return (data);
}

size_t	list_size(t_data *data)
{
	size_t	size;

	size = 0;
	while (data)
	{
		size++;
		data = data->next;
	}
	return (size);
}
