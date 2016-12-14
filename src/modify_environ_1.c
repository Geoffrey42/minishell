/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:17:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/13 16:19:37 by ggane            ###   ########.fr       */
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
	while (tmp)
	{
		modify_existing_var(modifications, new);
		if (tmp)
			tmp = tmp->next;
	}
	if (*modifications)
		add_new_var(modifications, new);
}

void	add_var_to_list(t_data **modifications, char *env)
{
	char	*copy;
	char	*del;

	copy = ft_strdup(env);
	del = copy;
	if (!ft_strchr(copy, '='))
	{
		copy = ft_strjoin(copy, "=");
		ft_strdel(&del);
	}
	list_push_back(modifications, parse_env(copy));
	ft_strdel(&copy);
}

t_data	*get_modifications(char **env_args, int (*check)(char *))
{
	t_data	*modifications;
	int		i;

	modifications = NULL;
	i = 0;
	while (env_args[i])
	{
		if (check(env_args[i]))
			add_var_to_list(&modifications, env_args[i]);
		i++;
	}
	return (modifications);
}
