/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:41:07 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 12:01:16 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*add_export_infos(t_shell *info, char *cwd, char *var)
{
	info->cwd = ft_strdup(cwd);
	info->var = ft_strdup(var);
	return (info);
}

int		check_letters(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		execute_setenv(t_shell *info)
{
	int		i;

	i = 0;
	while (info->args[i])
	{
		if (!check_letters(info->args[i]))
		{
			print_invalid_identifier(info->args[i]);
			return (1);
		}
		if (ft_strchr(info->args[i], '='))
			info->env = add_str_to_array(info->env, info->args[i]);
		i++;
	}
	return (0);
}

int		nb_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int		ft_setenv(t_shell *info)
{
	if (nb_args(info->args) - 1 == 0)
		display_env(info->env);
	else
		execute_setenv(info);
	return (0);
}
