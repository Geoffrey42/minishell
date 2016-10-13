/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:46 by ggane             #+#    #+#             */
/*   Updated: 2016/10/13 13:44:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_shell		*info;

	ac = 0;
	av = NULL;
	if (!(info = ft_memalloc(sizeof(t_shell))))
		return (1);
	info->env = copy_array_str(env);
	looping_shell(info);
	free(info);
	return (0);
}
