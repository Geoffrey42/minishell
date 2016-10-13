/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:38:18 by ggane             #+#    #+#             */
/*   Updated: 2016/10/13 18:31:26 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h> // a supprimer

void	print_after_equal(char *var)
{
	ft_putstr(var + len_till_c(var, '=') + 1);
}

void	print_var_content(char *var, char **env)
{
	int		i;
	char	*equal;

	i = 0;
	equal = ft_strjoin(var, "=");
	while (env[i])
	{
		if (variables_cmp(env[i], equal))
			print_after_equal(env[i]);
		i++;
	}
}

void	print_env_var(char *var, char **env)
{
	char	*tmp;

	tmp = var + 1;
	if (!check_variable_existence(tmp, env))
		print_var_content(tmp, env);
}

void	print_message(t_shell *info, int i)
{
	if (info->args[i][0] != '$')
		ft_putstr(info->args[i]);
	else
		print_env_var(info->args[i], info->env);
}

int		ft_echo(t_shell *info)
{
	int		i;

	i = 1;
	while (info->args[i])
	{
		print_message(info, i);
		if (info->args[i])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
