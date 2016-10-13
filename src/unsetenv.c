/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:41:42 by ggane             #+#    #+#             */
/*   Updated: 2016/10/13 11:37:41 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_less_env(char **copy, char **env, char *var)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	var = ft_strjoin(var, "=");
	while (env[i])
	{
		if (!variables_cmp(env[i], var))
			copy[j] = ft_strdup(env[i]);
		else
			j--;
		i++;
		j++;
	}
	copy[i] = NULL;
	free(var);
}

size_t	get_array_size(char **env)
{
	size_t		i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**erase_variable(char **env, char *var)
{
	char	**copy;
	int		i;

	i = 0;
	copy = (char **)malloc(sizeof(char *) * get_array_size(env) - 1);
	if (!copy)
		return (NULL);
	copy_less_env(copy, env, var);
	return (copy);
}

int		unsetenv_func(char *arg, char ***env)
{
	char	*var;

	var = ft_strdup(arg);
	if (!check_variable_existence(var, *env))
		*env = erase_variable(*env, var);
	free(var);
	return (0);
}

int		check_typo(char *str)
{
	int		i;

	i = 0;
	if (!ft_isalpha(str[0]))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		ft_unsetenv(t_shell *info)
{
	int		i;

	i = 1;
	while (info->args[i])
	{
		if (!check_typo(info->args[i]))
		{
			print_invalid_identifier(info->args[i], "unsetenv");
			return (1);
		}
		else
			unsetenv_func(info->args[i], &info->env);
		i++;
	}
	return (0);
}
