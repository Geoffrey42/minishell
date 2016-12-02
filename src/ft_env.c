/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:26:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/02 17:30:48 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_utility(t_data **new_env, char **args)
{
	(void)new_env;
	(void)args;
}

void	fill_modifications_list(t_data **modifications, char *var)
{
	(void)modifications;
	(void)var;
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
			fill_modifications_list(&modifications, env_args[i]);
		i++;
	}
	return (modifications);
}

int		ft_env(t_data *data)
{
	t_data	*new_env;

	new_env = modify_env(data);
	get_utility(&new_env, data->args);
	check_if_builtin(new_env);
	delete_list(&new_env);
	return (0);
}
