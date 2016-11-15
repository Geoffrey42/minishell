/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:53 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 15:35:24 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*parse_env(char *env)
{
	t_data	*data;

	data = NULL;
	data->var_name = ft_strsub(
		env, env[0], len_till_c(env, '='));
	data->var_content = ft_strsub(
		env, '=', len_till_c(env, '\0'));
	data->args = NULL;
	return (data);
}

t_list	*create_env_list(char **env)
{
	t_list		*info;
	t_data		*data;
	int			i;

	i = 0;
	while (env[i])
	{
		data = parse_env(env[i]);
		ft_lstadd(&info, ft_lstnew(data, sizeof(data)));
		delete_data(&data);
		i++;
	}
	return (info);
}
