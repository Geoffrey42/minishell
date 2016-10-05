/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:46:45 by ggane             #+#    #+#             */
/*   Updated: 2016/10/05 18:48:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>

extern char	**environ;

void	print_env(char **environ, char *name)
{
	int		i;

	i = 0;
	ft_putendl("*****************************************");
	while (environ[i])
	{
		printf("%s[%d] : [%s]\n", name, i, environ[i]);
		i++;
	}
	ft_putendl("*****************************************");
}

void	copy_each_variables(char **environ, char **copy)
{
	int		i;

	i = 0;
	while (environ[i])
	{
		copy[i] = ft_strdup(environ[i]);
		i++;
	}
	copy[i] = NULL;
}

char	**allocate_memory(size_t size)
{
	char	**copy;

	if (!(copy = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	return (copy);
}

size_t	get_env_size(char **environ)
{
	size_t	size;

	size = 0;
	while (environ[size])
		size++;
	return (size);
}

char	**copy_env(char **environ)
{
	char	**copy;
	size_t	size;
	int		i;

	i = 0;
	size = get_env_size(environ);
	copy = allocate_memory(size + 1);
	copy_each_variables(environ, copy);
	return (copy);
}

int		main(void)
{
	char	**copy;

	print_env(environ, "environ");
	copy = copy_env(environ);
	print_env(copy, "copy");
	return (0);
}
