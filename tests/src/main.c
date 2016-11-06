/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:53:23 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 17:53:45 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	void	(*del)(void *, size_t);
	t_list	*environ;
	int		status;

	del = &delete_environ;
	environ = create_env_list(env);
	status = 1;
	mute_compilator_flags(ac, av);
	ft_putendl("environ - before ft_lstdel");
	print_list(environ);
	while (status)
	{
		status = minishell(environ);
		status = 0;
	}
	ft_lstdel(&environ, del);
	ft_putendl("environ - after ft_lstdel");
	print_list(environ);
	return (0);
}
