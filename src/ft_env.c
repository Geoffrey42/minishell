/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:26:16 by ggane             #+#    #+#             */
/*   Updated: 2016/12/27 00:17:41 by ggane            ###   ########.fr       */
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
		{
			utility = copy_array_str(args + i);
			return (utility);
		}
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

void	modify_temporary_env(t_data *data, t_data **new_env)
{
	ft_putendl("start modify_temporary_env()");
	*new_env = create_modified_env(data);
	get_args(new_env, data);
	ft_putendl("end modify_temporary_env()");
}

int		ft_env(t_data **data)
{
	t_data	*new_env;
	void	(*display)(t_data *);

	ft_putendl("start ft_env()");
	new_env = NULL;
	display = &display_env_variables;
	ft_putendl("display choisi");
	if ((*data)->ac == 1)
	{
		ft_putendl("un seul argument dans env");
		display_env_list(*data, display);
		ft_putendl("display_env_list() ok");
	}
	else if ((*data)->ac > 1 && check_env_errors(*data))
	{
		ft_putendl("+sieurs arguments et check ok");
		modify_temporary_env(*data, &new_env);
		ft_putendl("modify_temporary_env() ok");
		if (new_env->args)
		{
			ft_putendl("new_env->args non null");
			execute_command(new_env);
			ft_putendl("execute_command() (dans ft_env()) ok");
		}
		delete_list(&new_env);
		ft_putendl("delete_list() ok");
	}
	ft_putendl("end ft_env()");
	return (0);
}
