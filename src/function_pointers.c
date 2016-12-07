/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:22:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/07 15:29:23 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_dash_equals(char **args, int i)
{
	if (args[i][0] != '-' && ft_strchr(args[i], '='))
		return (1);
	return (0);
}

int		check_dash_only(char **args, int i)
{
	if (args[i][0] != '-')
		return (1);
	return (0);
}
