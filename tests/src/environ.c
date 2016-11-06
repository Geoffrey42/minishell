/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:53 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 17:58:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*create_env_list(char **env)
{
	t_list	*environ;
	int		i;

	i = 0;
	environ = NULL;
	while (env[i])
	{
		ft_lstadd(&environ, ft_lstnew(ft_strdup(env[i]), ft_strlen(env[i])));
		i++;
	}
	return (environ);
}

void	print_list(t_list *list)
{
	ft_putendl("---------");
	while (list)
	{
		ft_putendl(list->content);
		list = list->next;
	}
	ft_putendl("---------");
}
