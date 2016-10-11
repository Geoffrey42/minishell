/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:03:58 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 11:37:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

int		display_str(char *var, int i, char *name)
{
	ft_putstr(name);
	ft_putchar('[');
	ft_putnbr(i);
	ft_putstr("] : [");
	ft_putstr(var);
	ft_putendl("]");
	return (i);
}

int		print_env(char **env, char *name)
{
	int		i;

	i = 0;
	ft_putendl("-----------------");
	while (env[i])
	{
		i = display_str(env[i], i, name);
		i++;
	}
	ft_putendl("-----------------");
	return (i);
}

void	display_prompt(void)
{
	write(1, "$> ", 3);
}
