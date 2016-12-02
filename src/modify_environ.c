/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:24 by ggane             #+#    #+#             */
/*   Updated: 2016/12/02 21:11:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_new_var(t_data **modifications, t_data **new)
{
	t_data	*tmp;

	tmp = *new;
	while (*modifications)
	{
		list_push_back(&tmp, *modifications);
		*modifications = (*modifications)->next;
		delete_this_cell(modifications);
	}
}

void	modify_existing_var(t_data **modifications, t_data **new)
{
	t_data	*tmp;

	tmp = *new;
	while (tmp)
	{
		if (!ft_strcmp((*modifications)->var_name, tmp->var_name))
		{
			ft_strdel(&tmp->var_content);
			tmp->var_content = ft_strdup((*modifications)->var_content);
			delete_this_cell(modifications);
		}
		tmp = tmp->next;
	}
}

void	modify_specific_variables(t_data **new, t_data *modifications)
{
	while (modifications)
	{
		modify_existing_var(&modifications, new);
		modifications = modifications->next;
	}
	if (modifications)
		add_new_var(&modifications, new);
}

t_data	*get_modifications(char **env_args)
{
	t_data	*modifications;
	int		i;

	modifications = NULL;
	i = 0;
	while (env_args[i])
	{
		if (env_args[i][0] != '-' && ft_strchr(env_args[i], '='))
			list_push_back(&modifications, parse_env(env_args[i]));
		i++;
	}
	return (modifications);
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
	if (modifications)
		delete_list(&modifications);
	return (new_env);
}
