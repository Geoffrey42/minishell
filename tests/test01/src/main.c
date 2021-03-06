/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:39:56 by ggane             #+#    #+#             */
/*   Updated: 2016/12/01 10:53:36 by ggane            ###   ########.fr       */
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
	t_data	*info;

	info = create_env_list(env);
	print_list(info);
	mute_compilator_flags(ac, av);
	//minishell(info);
	delete_list(&info);
	print_list(info);
	while (1);
	return (0);
}
