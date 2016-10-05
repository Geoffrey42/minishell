/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:03:58 by ggane             #+#    #+#             */
/*   Updated: 2016/10/05 20:04:07 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		display_str(char *var, int i)
{
	ft_putstr("environ[");
	ft_putnbr(i);
	ft_putstr("] : [");
	ft_putstr(var);
	ft_putendl("]");
	return (i);
}

int		print_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		i = display_str(env[i], i);
		i++;
	}
	return (i);
}

void	display_prompt(void)
{
	write(1, "$> ", 3);
}
