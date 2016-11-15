/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:59:44 by ggane             #+#    #+#             */
/*   Updated: 2016/11/15 10:32:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		minishell(t_list *environ)
{
	char	**args;
	char	*line;
	int		built_nb;

	args = NULL;
	line = NULL;
	built_nb = 0;
	while (1)
	{
		display_prompt();
		get_next_line(0, &line);
		args = ft_strsplit(line);
		ft_strdel(&line);
		if ((r = check_if_args_is_builtin(args[0])) != -1)
			execute_builtins(args, environ, built_nb);
		else
			execute_commands(args, environ);
	}
	return (0);
}
