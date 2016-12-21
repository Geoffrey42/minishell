/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:23:05 by ggane             #+#    #+#             */
/*   Updated: 2016/12/21 15:55:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_new_var(t_data *modifications, t_data **new)
{
	t_data	*tmp_modifs;

	tmp_modifs = modifications;
	while (tmp_modifs)
	{
		list_push_back(new, copy_data(tmp_modifs));
		tmp_modifs = tmp_modifs->next;
	}
}

void	modify_existing_var(t_data **modifications, t_data **new)
{
	t_data	*tmp_new;

	tmp_new = *new;
	while (tmp_new)
	{
		if (!*modifications)
			return ;
		if (tmp_new->var_name &&
			!ft_strcmp((*modifications)->var_name, tmp_new->var_name))
		{
			ft_strdel(&tmp_new->var_content);
			tmp_new->var_content = ft_strdup((*modifications)->var_content);
			return ;
		}
		tmp_new = tmp_new->next;
	}
	list_push_back(new, copy_data(*modifications));
	return ;
}

void	modify_specific_variables(t_data **new, t_data **modifications)
{
	t_data	*tmp_modifs;

	tmp_modifs = *modifications;
	while (tmp_modifs)
	{
		modify_existing_var(&tmp_modifs, new);
		if (tmp_modifs)
			tmp_modifs = tmp_modifs->next;
		else
			break ;
	}
	if (tmp_modifs)
		while (tmp_modifs->prev)
			tmp_modifs = tmp_modifs->prev;
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
