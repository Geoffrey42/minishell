/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:10:52 by ggane             #+#    #+#             */
/*   Updated: 2016/11/09 18:38:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		wait_child_process(pid_t child)
{
	int		status;

	status = 0;
	waitpid(child, &status, WUNTRACED);
	if (WIFEXITED(status))
		return (0);
	else
		return (1);
}

void	execute_file(t_shell *info, char *file)
{
	if (execve(file, info->args, copy_array_str(info->env)) == -1)
		return ;
}

int		create_and_execute_new_process(char *file, t_shell *info)
{
	pid_t	child;

	if ((child = fork()) == 0)
		execute_file(info, file);
	else if (child < 0)
		ft_putendl("fork() failed");
	if (wait_child_process(child))
		return (1);
	return (0);
}
