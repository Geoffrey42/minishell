/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_environ_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:22:54 by ggane             #+#    #+#             */
/*   Updated: 2016/12/14 12:14:26 by ggane            ###   ########.fr       */
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
	ft_putendl("\t\tnew_env");
	print_list(new_env);
	check = &check_dash_and_equal;
	modifications = get_modifications(data->args, check);
	ft_putendl("\t\tmodifications");
	print_list(modifications);
	ft_putendl("\t\t---------------------------------------------------------");
	modify_specific_variables(&new_env, &modifications);
	ft_putendl("\t\tmodify_specific_variables() ok");
	if (modifications)
	{
		ft_putendl("\t\tmodifications non nulle");
		//add_new_var(&modifications, &new_env);
		add_new_var(modifications, &new_env);
		ft_putendl("\t\tadd_new_var() ok");
	}
	ft_putendl("\t\tnew_env (apres modifs)");
	print_list(new_env);
	ft_putendl("\t\tmodifications (apres modifs)");
	print_list(modifications);
	if (modifications)
		delete_list(&modifications);
	return (new_env);
}
