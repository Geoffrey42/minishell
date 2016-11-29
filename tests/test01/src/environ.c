/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:53 by ggane             #+#    #+#             */
/*   Updated: 2016/11/29 17:04:04 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*parse_env(char *env)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ft_putendl("-----------------------------------------------------------");
	ft_putstr("\t\tenv : ");
	ft_putendl(env);
	ft_putstr("\t\tlen_till_c(env, '=') : ");
	ft_putnbr(len_till_c(env, '='));
	ft_putchar('\n');
	ft_putendl("-----------------------------------------------------------");
	ft_putendl("\t\tstart parse_env()");
	data->var_name = ft_strsub(
		env, env[0], len_till_c(env, '='));
	ft_putstr("\t\tft_strsub() ok : ");
	ft_putendl(data->var_name);
	data->var_content = ft_strsub(
		env, '=', len_till_c(env, '\0'));
	ft_putstr("\t\tft_strsub() ok : ");
	ft_putendl(data->var_content);
	data->args = NULL;
	ft_putendl("\t\tend parse_env()");
	return (data);
}

t_list	*create_env_list(char **env)
{
	t_list		*info;
	t_data		*data;
	int			i;

	i = 0;
	ft_putendl("\tstart create_env_list()");
	while (env[i])
	{
		ft_putendl("\t - debut while (env[i])");
		data = parse_env(env[i]);
		ft_putendl("\t - parse_env() ok");
		ft_lstadd(&info, ft_lstnew(data, sizeof(data)));
		ft_putendl("\t - ft_lstadd() ok");
		delete_data(&data);
		ft_putendl("\t - delete_data() ok");
		i++;
	}
	ft_putendl("\tend create_env_list()");
	return (info);
}
