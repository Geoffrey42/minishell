/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 21:20:10 by ggane             #+#    #+#             */
/*   Updated: 2016/12/19 13:55:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_content(char *var)
{
	char	*value;
	int		equal;

	equal = len_till_c(var, '=');
	value = ft_strsub(var, equal + 1, ft_strlen(var) - equal - 1);
	return (value);
}

char	*extract_name(char *var)
{
	char	*name;
	int		equal;

	equal = len_till_c(var, '=');
	name = ft_strsub(var, 0, equal);
	return (name);
}

void	add_var_directly(t_data **data, char *var)
{
	t_data	*tmp;
	char	*name;
	char	*value;

	tmp = *data;
	name = extract_name(var);
	value = extract_content(var);
	while (tmp)
	{
		if (!(ft_strcmp(tmp->var_name, name)))
		{
			ft_strdel(&tmp->var_content);
			tmp->var_content = ft_strdup(value);
			ft_strdel(&name);
			ft_strdel(&value);
			return ;
		}
		tmp = tmp->next;
	}
	list_push_back(data, parse_env(var));
	ft_strdel(&name);
	ft_strdel(&value);
}
