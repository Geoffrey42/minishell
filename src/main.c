/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:39:56 by ggane             #+#    #+#             */
/*   Updated: 2016/12/26 19:00:13 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mute_compilator_flags(int ac, char **av)
{
	(void)ac;
	(void)av;
}

int		main(int ac, char **av, char **env)
{
	t_data	*data;

	data = create_env_list(env);
	mute_compilator_flags(ac, av);
	minishell(data);
	delete_list(&data);
	return (0);
}
