/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 22:41:42 by ggane             #+#    #+#             */
/*   Updated: 2016/10/10 22:51:17 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_unsetenv(t_shell *info)
{
	t_shell		*tmp;

	tmp = info;
	ft_putendl("builtin unsetenv is called");
	return (0);
}
