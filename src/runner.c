/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:02:30 by ggane             #+#    #+#             */
/*   Updated: 2016/10/05 17:33:29 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		extern_commands_launcher(char **words)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == 0)
	{
		if (execve(read_path(words[0], words,)))
	}
	return (1);
}

int		execute_commands(char **words)
{
	return (0);
}

void	looping_runner(void)
{
	char	**words;
	char	*line;
	int		status;

	status = 0;
	while (status)
	{
		display_prompt();
		get_next_line(0, &line);
		words = ft_strsplit(line, ' ');
		status = execute_commands(words);
		erase_variables(words, line);
	}
}
