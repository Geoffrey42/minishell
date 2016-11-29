/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:39:56 by ggane             #+#    #+#             */
/*   Updated: 2016/11/29 16:49:09 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mute_compilator_flags(int ac, char **av)
{
	if (av)
		av = NULL;
	ac = 0;
}

int		main(int ac, char **av, char **env)
{
	t_list	*info;

	ft_putendl("start main()");
	info = create_env_list(env);
	ft_putendl("create_env_list() ok");
	print_list(info);
	ft_putendl("print_list() ok");
	mute_compilator_flags(ac, av);
	ft_putendl("mute_compilator() ok");
	//minishell(info);
	delete_info(&info);
	ft_putendl("delete_info() ok");
	print_list(info);
	ft_putendl("print_list() ok");
	return (0);
}
