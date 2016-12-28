/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environ_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:11:14 by ggane             #+#    #+#             */
/*   Updated: 2016/12/28 09:55:46 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			list_push_back(t_data **list, t_data *new)
{
	t_data	*tmp;

	tmp = NULL;
	if (!*list)
		*list = new;
	else if (!(*list)->var_name)
	{
		delete_list(list);
		*list = new;
	}
	else if (*list && (*list)->var_name)
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
	if (!data)
		data = create_elem();
	return (data);
}

size_t			list_size(t_data *data)
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
