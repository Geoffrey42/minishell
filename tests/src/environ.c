/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:01:53 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 21:26:49 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*create_env_list(char **env)
{
	t_list	*environ;
	char	*copy;
	//char	*del;
	int		i;

	i = 0;
	environ = NULL;
	while (env[i])
	{
		copy = ft_strdup(env[i]);
		//del = copy;
		ft_lstadd(&environ, ft_lstnew(copy, ft_strlen(copy)));
		free(copy);
		i++;
	}
	return (environ);
}

void	print_list(t_list *list)
{
	int		i;

	i = 0;
	ft_putendl("---------");
	while (list)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putendl(list->content);
		i++;
		list = list->next;
	}
	ft_putendl("---------");
}
