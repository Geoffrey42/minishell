/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:10:52 by ggane             #+#    #+#             */
/*   Updated: 2016/12/27 15:30:58 by ggane            ###   ########.fr       */
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

void	execute_file(t_data *data, char *file)
{
	char	**env;

	env = create_env_array(data);
	if (execve(file, data->args, env) == -1)
	{
		erase_char_array(env);
		return ;
	}
	erase_char_array(env);
}

int		create_and_execute_new_process(char *file, t_data *data)
{
	pid_t	child;

	if ((child = fork()) == 0)
		execute_file(data, file);
	else if (child < 0)
		ft_putendl("fork() failed");
	if (wait_child_process(child))
		return (1);
	return (0);
}
