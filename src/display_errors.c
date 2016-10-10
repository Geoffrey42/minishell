/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:26:39 by ggane             #+#    #+#             */
/*   Updated: 2016/10/10 17:41:01 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		print_permission_denied(char *command)
{
	ft_putstr_fd("minishell: permission denied: ", 2);
	ft_putendl_fd(command, 2);
	return (1);
}

int		print_command_not_found(char *command)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(command, 2);
	return (1);
}
