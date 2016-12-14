/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:22:33 by ggane             #+#    #+#             */
/*   Updated: 2016/12/14 10:48:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_dash_and_equal(char *args)
{
	if (args[0] != '-' && ft_strchr(args, '='))
		return (1);
	return (0);
}

int		check_dash_or_equal(char *args)
{
	if (args[0] == '-' || !ft_strchr(args, '='))
		return (1);
	return (0);
}

int		check_dash_only(char *args)
{
	if (args[0] != '-')
		return (1);
	return (0);
}
