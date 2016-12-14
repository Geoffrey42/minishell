/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:18:39 by ggane             #+#    #+#             */
/*   Updated: 2016/12/13 16:20:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

t_data	*create_modified_env(t_data *data)
{
	t_data	*new_env;
	t_data	*modifications;
	int		(*check)(char *);

	new_env = copy_env(data);
	check = &check_dash_and_equal;
	modifications = get_modifications(data->args, check);
	modify_specific_variables(&new_env, &modifications);
	if (modifications)
		delete_list(&modifications);
	return (new_env);
}
