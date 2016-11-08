/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:46 by ggane             #+#    #+#             */
/*   Updated: 2016/11/08 20:40:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_shell		*info;
	char		**del_env;

	ac = 0;
	av = NULL;
	if (!(info = ft_memalloc(sizeof(t_shell))))
		return (1);
	info->env = copy_array_str(env);
	del_env = (char **)info->env;
	looping_shell(info);
	erase_char_array(&del_env);
	free(info);
	info = NULL;
	return (0);
}
