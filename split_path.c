/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:34:30 by ggane             #+#    #+#             */
/*   Updated: 2016/10/05 20:38:05 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"
#include <stdio.h>

char	*get_path(char **environ)
{
	int		i;
	char	*path;

	i = 0;
	while (environ[i])
	{
		if (ft_strstr(environ[i], "PATH="))
			return (path = ft_strdup(environ[i] + 5));
		i++;
	}
	return (NULL);
}

char **split_path(char *path)
{
	char	**directories;

	directories = ft_strsplit(path, ':');
	return (directories);
}

int		main(void)
{
	int		i;
	char	*path;
	char	**directories;

	i = print_env(environ);
	path = get_path(environ);
	printf("path : [%s]\n", path);
	directories = split_path(path);
	print_env(directories);
	return (0);
}
