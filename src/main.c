/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:08:46 by ggane             #+#    #+#             */
/*   Updated: 2016/10/07 17:52:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av)
{
	char	**words;
	char	*line;
	int		status;

	ac = 0;
	av = NULL;
	status = 0;
	while (!status)
	{
		display_prompt();
		if ((get_next_line(0, &line) == -1))
		{
			return (1);
		}
		words = ft_strsplit(line, ' ');
		status = execute_commands(words);
		erase_variables(words, line);
	}
	return (0);
}
