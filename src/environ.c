/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:53 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 21:27:58 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*create_env_list(char **env)
{
	t_list	*environ;
	char	*copy;
	int		i;

	i = 0;
	environ = NULL;
	while (env[i])
	{
		copy = ft_strdup(env[i]);
		ft_lstadd(&environ, ft_lstnew(copy, sizeof(copy)));
		free(copy);
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
