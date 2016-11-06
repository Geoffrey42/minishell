/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:43:57 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 13:24:45 by ggane            ###   ########.fr       */
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
