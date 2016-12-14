/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:23:05 by ggane             #+#    #+#             */
/*   Updated: 2016/12/14 15:22:33 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	add_new_var(t_data **modifications, t_data **new)
void	add_new_var(t_data *modifications, t_data **new)
{
	t_data	*tmp_modifs;

	tmp_modifs = modifications;
	while (tmp_modifs)
	{
		list_push_back(new, copy_data(tmp_modifs));
		tmp_modifs = tmp_modifs->next;
		//delete_this_cell(modifications);
	}
}

//void	modify_existing_var(t_data **modifications, t_data **new)
void	modify_existing_var(t_data *modifications, t_data **new)
{
	t_data	*tmp_new;

	tmp_new = *new;
	while (tmp_new)
	{
		//if (!*modifications)
		if (!modifications)
			return ;
		ft_putendl("******************************************");
		ft_putstr("modif->var_name : ");
		//ft_putendl((*modifications)->var_name);
		ft_putendl(modifications->var_name);
		ft_putstr("new->var_name : ");
		ft_putendl(tmp_new->var_name);
		//if (!ft_strcmp((*modifications)->var_name, tmp_new->var_name))
		if (!ft_strcmp(modifications->var_name, tmp_new->var_name))
		{
			ft_putendl("MATCH !!!!");
			ft_strdel(&tmp_new->var_content);
			//tmp_new->var_content = ft_strdup((*modifications)->var_content);
			tmp_new->var_content = ft_strdup(modifications->var_content);
			//delete_this_cell(modifications);
			delete_this_cell(&modifications);
			ft_putendl("modifications (durant modifs)");
			print_list(modifications);
			return ;
		}
		tmp_new = tmp_new->next;
	}
	ft_putendl("modifications (durant modifs)");
	//print_list(*modifications);
	print_list(modifications);
}

void	modify_specific_variables(t_data **new, t_data **modifications)
{
	t_data	*tmp_modifs;

	tmp_modifs = *modifications;
	while (tmp_modifs)
	{
		modify_existing_var(tmp_modifs, new);
		//if (tmp_modifs)
		tmp_modifs = tmp_modifs->next;
	}
	//if (*modifications)
	//	add_new_var(modifications, new);
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
