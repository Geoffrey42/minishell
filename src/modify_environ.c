/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:24 by ggane             #+#    #+#             */
/*   Updated: 2016/12/02 17:33:17 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	modify_specific_variables(t_data **new, t_data *modifications)
{
	t_data	*tmp;

	tmp = *new;
	(void)modifications; //to delete
	while (tmp)
	{
		// if () 
		tmp = tmp->next;
	}
}

t_data	*copy_data(t_data *data)
{
	t_data	*copy;

	copy = create_elem();
	copy->var_name = ft_strdup(data->var_name);
	copy->var_content = ft_strdup(data->var_content);
	return (copy);
}

t_data	*copy_env(t_data *data)
{
	t_data		*new_env;

	new_env = NULL;
	while (data)
	{
		list_push_back(&new_env, copy_data(data));
		data = data->next;
	}
	return (new_env);
}

t_data	*modify_env(t_data *data)
{
	t_data	*new_env;
	t_data	*modifications;

	new_env = copy_env(data);
	modifications = get_modifications(data->args);
	modify_specific_variables(&new_env, modifications);
	return (new_env);
}
