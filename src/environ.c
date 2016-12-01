/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:53 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 16:01:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_if_environ_is_empty(t_data *data)
{
	while (data)
	{
		if (!data->var_name || ft_strlen(data->var_name) == 0)
			return (1);
		data = data->next;
	}
	return (0);
}

t_data	*parse_env(char *env)
{
	t_data	*data;
	int		equal;

	data = create_elem();
	equal = len_till_c(env, '=');
	data->var_name = ft_strsub(env, 0, equal);
	data->var_content = ft_strsub(env, equal + 1, ft_strlen(env));
	return (data);
}

t_data	*create_env_list(char **env)
{
	t_data		*data;
	int			i;

	i = 0;
	data = NULL;
	while (env[i])
		list_push_back(&data, parse_env(env[i++]));
	return (data);
}
