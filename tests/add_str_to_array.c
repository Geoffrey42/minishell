/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 04:34:24 by ggane             #+#    #+#             */
/*   Updated: 2016/10/11 05:34:20 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int		display_str(char *var, int i, char *name)
{
	ft_putstr(name);
	ft_putchar('[');
	ft_putnbr(i);
	ft_putstr("] : [");
	ft_putstr(var);
	ft_putendl("]");
	return (i);
}

int		print_env(char **env, char *name)
{
	int		i;

	i = 0;
	ft_putendl("-----------------");
	while (env[i])
	{
		i = display_str(env[i], i, name);
		i++;
	}
	ft_putendl("-----------------");
	return (i);
}

void	copy_and_add_target(char **source, char **copy, char *target)
{
	int		i;

	i = 0;
	while (source[i])
	{
		copy[i] = ft_strdup(source[i]);
		i++;
	}
	copy[i++] = ft_strdup(target);
	copy[i] = NULL;
}

char	**allocate_memory(size_t size)
{
	char	**copy;

	if (!(copy = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	return (copy);
}

size_t	get_source_size(char **source)
{
	size_t	size;

	size = 0;
	while (source[size])
		size++;
	return (size);
}

char	**add_str_to_array(char **source, char *target)
{
	char	**copy;
	size_t	size;

	size = get_source_size(source);
	copy = allocate_memory(size + 2);
	copy_and_add_target(source, copy, target);
	return (copy);
}

int		main(int ac, char **av, char **env)
{
	char	**copy;
	char	cwd[1024];
	char	*tmp;

	copy = copy_array_str(env);
	print_env(copy, "copy");
	getcwd(cwd, sizeof(cwd));
	printf("cwd : [%s]\n", cwd);
	tmp = (char *)cwd;
	tmp = ft_strjoin("NEW_VAR=", cwd);
	copy = add_str_to_array(copy, tmp);
	print_env(copy, "copy");
	return (0);
}
