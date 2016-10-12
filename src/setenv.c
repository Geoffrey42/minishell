/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:41:07 by ggane             #+#    #+#             */
/*   Updated: 2016/10/12 17:42:37 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**reset_value(char **env, char *var, char *arg)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (variables_cmp(env[i], var))
		{
			env[i] = ft_strdup(arg);
			return (env);
		}
		i++;
	}
	return (env);
}

char	*fill_with_numbers(char *var, size_t len)
{
	size_t		i;
	char		number;

	i = 0;
	number = '1';
	while (i <= len)
	{
		var[i] = number;
		number++;
		i++;
	}
	var[i] = '\0';
	return (var);
}

int		setenv_func(char *arg, char ***env)
{
	char	*var;

	var = NULL;
	if (ft_strchr(arg, '='))
	{
		if (!(var = (char *)malloc(sizeof(char) * len_till_c(arg, '=') + 1)))
			return (0);
		var = fill_with_numbers(var, len_till_c(arg, '='));
		var = copy_name(arg, len_till_c(arg, '='));
	}
	else
		return (0);
	if (!check_variable_existence(var, *env))
		*env = add_str_to_array(*env, arg);
	else
		*env = reset_value(*env, var, arg);
	free(var);
	var = NULL;
	return (0);
}

int		execute_setenv(t_shell *info)
{
	int		i;

	i = 1;
	while (info->args[i])
	{
		if (!check_letters(info->args[i]))
		{
			print_invalid_identifier(info->args[i]);
			return (1);
		}
		else
			setenv_func(info->args[i], &info->env);
		i++;
	}
	return (0);
}

int		ft_setenv(t_shell *info)
{
	if (nb_args(info->args) - 1 == 0)
		display_env(info->env);
	else
		execute_setenv(info);
	return (0);
}
