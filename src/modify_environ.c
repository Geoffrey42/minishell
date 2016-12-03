/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:44:24 by ggane             #+#    #+#             */
/*   Updated: 2016/12/03 11:02:54 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_new_var(t_data **modifications, t_data **new)
{
	t_data	*tmp;

	tmp = *new;
	ft_putendl("start add_new_var()");
	while (*modifications)
	{
		ft_putendl("check si il y a des nouvelles variables a ajouter");
		list_push_back(&tmp, *modifications);
		ft_putendl("list_push_back() ok");
		*modifications = (*modifications)->next;
		ft_putendl("passage au prochain maillon liste des modifs");
		delete_this_cell(modifications);
		ft_putendl("delete_this_cell() ok");
	}
	ft_putendl("end add_new_var()");
}

void	modify_existing_var(t_data **modifications, t_data **new)
{
	t_data	*tmp;

	tmp = *new;
	while (tmp && *modifications)
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

void	modify_specific_variables(t_data **new, t_data **modifications)
{
	t_data	*tmp;

	tmp = *modifications;
	ft_putendl("liste des modifs :");
	print_list(*modifications);
	while (tmp)
	{
		ft_putendl("check si variable deja dans env");
		modify_existing_var(&tmp, new);
		if (tmp)
			tmp = tmp->next;
	}
	if (*modifications)
	{
		ft_putendl("modifs est peut-etre une variable nouvelle");
		add_new_var(modifications, new);
		ft_putendl("add_new_var() ok");
	}
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

t_data	*create_modified_env(t_data *data)
{
	t_data	*new_env;
	t_data	*modifications;

	new_env = copy_env(data);
	modifications = get_modifications(data->args);
	modify_specific_variables(&new_env, &modifications);
	ft_putendl("modify_specific_variables() ok");
	if (modifications)
	{
		ft_putendl("liste modifications non vide");
		delete_list(&modifications);
		ft_putendl("delete_list() ok");
	}
	ft_putendl("liste des modifs :");
	print_list(modifications);
	ft_putendl("nouvel environ");
	print_list(new_env);
	ft_putendl("end create_modified_env()");
	return (new_env);
}
