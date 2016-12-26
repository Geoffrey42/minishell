/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_environ_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:11:01 by ggane             #+#    #+#             */
/*   Updated: 2016/12/26 19:11:03 by ggane            ###   ########.fr       */
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
	data->var_content = ft_strsub(env, equal + 1, ft_strlen(env) - equal - 1);
	return (data);
}

char	*join_variables(t_data *data, char *env)
{
	env = ft_strjoin(data->var_name, "=");
	env = ft_strjoin(env, data->var_content);
	return (env);
}

void	copy_each_cell(t_data *data, char **env)
{
	int		i;

	i = 0;
	while (data)
	{
		env[i] = join_variables(data, env[i]);
		data = data->next;
		i++;
	}
	env[i] = NULL;
}

char	**create_env_array(t_data *data)
{
	char	**env;
	size_t	size;

	size = list_size(data);
	env = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	copy_each_cell(data, env);
	return (env);
}
