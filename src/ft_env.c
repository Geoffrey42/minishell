/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:26:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/06 22:44:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_utility(char **args)
{
	char	**utility;
	int		i;

	i = 1;
	utility = NULL;
	while (args[i])
	{
		if (args[i][0] != '-' && !ft_strchr(args[i], '='))	
			utility = copy_array_str(args + i);
		i++;
	}
	return (utility);
}

void	get_args(t_data **new_env, t_data *data)
{
	t_data	*tmp;

	tmp = *new_env;
	while (tmp)
	{
		tmp->args = get_utility(data->args);
		tmp->ac = args_number(tmp->args); 
		tmp = tmp->next;
	}
}

void	modify_env(t_data *data)
{
	t_data	*new_env;

	new_env = create_modified_env(data);
	get_args(&new_env, data);
	if (new_env->args)
		check_if_builtin(new_env);
	delete_list(&new_env);
}

int		ft_env(t_data *data)
{
	if (data->ac == 1)
		display_env_list(data);
	else
		modify_env(data);
	return (0);
}
