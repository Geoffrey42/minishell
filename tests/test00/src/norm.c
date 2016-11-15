/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:02:01 by ggane             #+#    #+#             */
/*   Updated: 2016/11/06 16:04:02 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** This file only contains functions made to avoid norm issues
*/

void	mute_compilator_flags(int ac, char **av)
{
	if (av)
		av = NULL;
	ac = 0;
}
