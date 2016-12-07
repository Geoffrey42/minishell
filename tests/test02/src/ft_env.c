/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:26:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/02 20:56:28 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_utility(t_data **new_env, char **args)
{
	t_data	*tmp;

	tmp = *new_env;
	if (!*new_env || !args)
		return ;
	while (tmp)
	{
		tmp->args = copy_array_str(args);
		tmp = tmp->next;
	}
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
