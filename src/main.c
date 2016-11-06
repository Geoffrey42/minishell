/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:39:56 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 17:17:37 by ggane            ###   ########.fr       */
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
	while (status)
		status = minishell(environ);
	ft_lstdel(&environ, del);
	return (0);
}
