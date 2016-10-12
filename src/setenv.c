/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:41:07 by ggane             #+#    #+#             */
/*   Updated: 2016/10/12 11:02:51 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_name(char *src, size_t size)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(sizeof(char) * size + 1);
	if (!copy)
		return (NULL);
	while (i <= size)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		variables_cmp(char *to_trim, char *var1)
{
	char	*var2;
	size_t	i;

	var2 = NULL;
	i = 0;
	while (to_trim[i] != '=')
		i++;
	if (to_trim[i] == '=')
		var2 = copy_name(to_trim, i);
	if (!ft_strcmp(var1, var2))
	{
		free(var2);
		return (1);
	}
	return (0);
}

int		check_variable_existence(char *var, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (variables_cmp(env[i], var))
			return (1);
		i++;
	}
	return (0);
}

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

size_t	len_till_c(char *src, int c)
{
	int		i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		setenv_func(char *arg, char ***env)
{
	char	*var;

	var = NULL;
	if (ft_strchr(arg, '='))
	{
		var = ft_memalloc(len_till_c(arg, '='));
		ft_memccpy(var, arg, '=', ft_strlen(arg));
	}
	else
		return (0);
	if (!check_variable_existence(var, *env))
		*env = add_str_to_array(*env, arg);
	else
		*env = reset_value(*env, var, arg);
	return (0);
}

int		check_letters(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 1 && str[i] == '=')
		return (1);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
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
