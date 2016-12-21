/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:39:56 by ggane             #+#    #+#             */
/*   Updated: 2016/12/21 09:22:00 by ggane            ###   ########.fr       */
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
	t_data	*data;

	data = create_env_list(env);
	mute_compilator_flags(ac, av);
	minishell(data);
	delete_list(&data);
	return (0);
}
