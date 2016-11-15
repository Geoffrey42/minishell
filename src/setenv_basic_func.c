/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_basic_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:29:33 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 09:07:17 by ggane            ###   ########.fr       */
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
		ft_strdel(&var2);
		return (1);
	}
	ft_strdel(&var2);
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

int		nb_args(char **args)
{
	int		i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
